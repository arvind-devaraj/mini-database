#include "defs2.h"
extern TABS tabs;


COLUMN* SELECT::getfield(char*tname,char *colname) {
	COLUMN * result=new COLUMN;
	int tno=tabs.gettabno(tname);
	if( tno==-1) {printf( "notable5");return result;}
	int cno=tabs.getfieldno(tno,colname);
	if( cno==-1) { printf( "nofield1");return result;}
	result->createfield("#",tabs.selecttable(tno).selectcol(cno).getfieldtype());
	int n=pos[tno];
	if( n==-1)  {printf("no table8 %d %s %s",tno,tname,colname); return result;}
	for(int i=0;i<prod;i++) {
	result->insertfield(
	tabs.selecttable(tno).selectcol(cno).selectfield(i/coeff[n]%card[n])
	);
	}
	return result;
}

void SELECT::setwhere( COLUMN* bval ) { WHERE->copy(bval); }
void SELECT::sethaving(COLUMN* bval)  {HAVING->copy(bval); }

void SELECT::groupby(char*tname,char*fld)
{
	grouptno=tabs.gettabno(tname);
	groupfno=tabs.getfieldno(grouptno,fld);
	groupby(grouptno,groupfno);
}
// depends on WHERE clause. For groupby all rows not satisfying WHERE clause are eliminated
void  SELECT::groupby(int grouptno,int groupfno)
{
	GROUPBYEXPR=true;
	gp=new COLUMN; gp->reserve();
	
	int total=tabs.totalrecords(grouptno,groupfno);
	gp->createfield("#",tabs.getfieldtype(grouptno,groupfno));
	for(int i=0;i<total;i++) {
		if( WHERE->selectfield(i).getbval()==false) continue;
		DATUM d1,d2;
		bool flduniq=true;
		for(int j=0;j<i;j++) {
			d1.cp(tabs.selectfield(grouptno,groupfno,i)); d2.cp(tabs.selectfield(grouptno,groupfno,j));
			if( d1.cmp(d2,EQ)) flduniq=false;
		}
		if( flduniq) gp->insertfield( tabs.selectfield(grouptno,groupfno,i));
	}
	
}

bool SELECT::isgroupby() { return GROUPBYEXPR; }
void SELECT::setgroupby(bool b) { GROUPBYEXPR=b; }

COLUMN* SELECT::getgroupfield(char*tname,char*fname) 
{
	COLUMN* result=new COLUMN;
	if( isgroupby()==false ) { printf("not a gp expr"); return result;}
	result->copy(gp);
	return result;
}
// having count(dno)>=2
COLUMN* SELECT::getgroupfield(AGGFUN fun,char*tname,char*colname) 
{
	COLUMN * result=new COLUMN;
	int tno=tabs.gettabno(tname);
	if( tno==-1) {printf( "notable5");return result;}
	int fno=tabs.getfieldno(tno,colname);
	if( fno==-1) { printf( "nofield1");return result;}
	if( isgroupby()==false ) { printf("not a gp expr"); return result;}
	
	int total=gp->totalrecords();
	result->createfield("#",tabs.getfieldtype(tno,fno));
	for(int i=0;i<total;i++) {
		
		DATUM acc; acc.settype(UNDEF);	
		for(int k=0;k< tabs.totalrecords(tno);k++) {
			if( WHERE->selectfield(k).getbval()==false ) continue;
			if( gp->selectfield(i).cmp( tabs.selectfield(grouptno,groupfno,k),EQ) )
		 	accumulate(acc,tabs.selectfield(tno,fno,k),fun) ;
		}
		result->insertfield(acc);
		
	}
	return result;
}





COLUMN* SELECT::getfield(char* cval) {
	COLUMN* result=new COLUMN;
	result->createfield("#",VARCHAR);
	DATUM d1; d1.cp(cval);
	result->insertfield(d1);
	return result;
}
COLUMN* SELECT::getfield(double dval) {
	COLUMN*result=new COLUMN;
	result->createfield("#",NUMBER);
	DATUM d1;d1.cp(dval);
	result->insertfield(d1);
	return result;
}

COLUMN* SELECT::getfield(DATUM d) {
	COLUMN * result=new COLUMN;
	result->createfield("#",d.gettype());
	result->insertfield(d);
	return result;
}
