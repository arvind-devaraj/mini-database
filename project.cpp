#include "defs2.h"
extern TABS tabs;

COLUMN* SELECT::projfield(char*tname,char *colname) {
	COLUMN * result=new COLUMN;
	if( isgroupby() == true ) { printf("groupby fn. error"); return result;}
	int tno=tabs.gettabno(tname);
	if( tno==-1) {printf( "notable5");return result;}
	int cno=tabs.getfieldno(tno,colname);
	if( cno==-1) { printf( "nofield1");return result;}
	result->createfield("#",tabs.selecttable(tno).selectcol(cno).getfieldtype());
	int n=pos[tno];
	if( n==-1)  {printf("no table8 %d %s %s",tno,tname,colname); return result;}
	for(int i=0;i<prod;i++) {
	if( WHERE->selectfield(i).getbval()==false) continue;
	result->insertfield(
	tabs.selecttable(tno).selectcol(cno).selectfield(i/coeff[n]%card[n])
	);
	}
	return result;
}


COLUMN* SELECT::projfield(AGGFUN fun,char* tname,char *fname) {
	
	int tno=tabs.gettabno(tname);
	int fno=tabs.getfieldno(tno,fname);
	COLUMN * result=new COLUMN;  
	// not group by
	//example  SELECT [SUM(ENO)] FROM EMP WHERE ENO>10
	if( isgroupby()==true )  { printf("Not group by expr"); return result;}
		
	result->createfield("#",tabs.getfieldtype(tno,fno));
	DATUM acc;acc.settype(UNDEF);
	for(int i=0;i< tabs.totalrecords(tno);i++) {
		// WHERE  CONDITION
		if( WHERE->selectfield(i).getbval()==false) continue;
		accumulate(acc,tabs.selectfield(tno,fno,i),fun);
		
	}
	result->insertfield(acc);
	return result;
	
}
	

COLUMN* SELECT::projgroupfield(AGGFUN fun,char*tname,char*fname) {

	//example  SELECT SUM(ENO) FROM EMP GROUPBY EMP.DNO HAVING EMP.DNO > 10
	
	int tno=tabs.gettabno(tname);
	int fno=tabs.getfieldno(tno,fname);
	COLUMN * result=new COLUMN;  
	if( isgroupby()==false ) { printf("groupby fn.error");return result;}
	int total=gp->totalrecords();
	result->createfield("#",tabs.getfieldtype(tno,fno));
	
	for(int i=0;i<total;i++) {
		if( HAVING->selectfield(i).getbval()==false ) continue;
		DATUM acc; acc.settype(UNDEF);	
		for(int k=0;k< tabs.totalrecords(tno);k++) {
			if( gp->selectfield(i).cmp( tabs.selectfield(grouptno,groupfno,k),EQ) )
			 accumulate(acc,tabs.selectfield(tno,fno,k),fun) ;
		}
		result->insertfield(acc);
	}
	return result;
}

COLUMN* SELECT::projgroupfield(char*tname,char*fname) {
	//CHECK HERE if tname=grouptname 
	int tno=tabs.gettabno(tname);
	int fno=tabs.getfieldno(tno,fname);
	COLUMN * result=new COLUMN;  
	if( isgroupby()==false ) { printf("not a group expr");return result;} 
	if( tno!=grouptno || fno!=groupfno) { printf("not a gp col");return result;}
	for(int i=0;i<gp->totalrecords() ; i++) {
		if( HAVING->selectfield(i).getbval()==false ) continue;
		result->insertfield( gp->selectfield(i) );
	}
	return result;
}



