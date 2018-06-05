#include "defs2.h"
#include <stack>
extern TABS tabs;	



COLUMN* SELECT::alltrue() {
	COLUMN* result=new COLUMN;
	result->createfield("#",BOOL);
	for(int i=0;i<prod;i++) { result->insertfield(true); }
	return result;
}

COLUMN* SELECT::allhavingtrue() {
	COLUMN *result=new COLUMN;
	result->createfield("#",BOOL);
	for(int i=0;i< gp->totalrecords();i++) { result->insertfield(true); }
	return result;
}


COLUMN* SELECT::cmp(COLUMN* s,COLUMN* t,COMTYPE c)  {
	return colcmp(s,t,c,prod);
}

COLUMN* SELECT::binop(COLUMN* s,COLUMN* t,OPTYPE op) {
	return colbinop(s,t,op,prod);
}

COLUMN* SELECT::unop(COLUMN*s,OPTYPE op) {
	return colunop(s,op,prod);
}
COLUMN* SELECT::groupcmp(COLUMN* s,COLUMN* t,COMTYPE c)  {
	return colcmp(s,t,c,gp->totalrecords());
}

COLUMN* SELECT::groupbinop(COLUMN* s,COLUMN* t,OPTYPE op) {
	return colbinop(s,t,op,gp->totalrecords());
}

COLUMN* SELECT::groupunop(COLUMN*s,OPTYPE op) {
	return colunop(s,op,gp->totalrecords());
}




void SELECT::del(char*tname) 
{
	int tno=tabs.gettabno(tname);
	for(int i=0;i< tabs.totalrecords(tno); i++ ) {
		if( WHERE->selectfield(i).getbval()==true)   {
			tabs.deleterecord(tno,i);
			
		}
	}
}


void SELECT::update(char*tname,char* fname,DATUM d)
{
	int tno=tabs.gettabno(tname);
	int fno=tabs.getfieldno(tno,fname);
	for(int i=0;i< tabs.totalrecords(tno);i++ ) {
		if( WHERE->selectfield(i).getbval()==true)  {
			tabs.selecttable(tno).selectcol(fno).selectfield(i).cp(d);
			//d.display();
			
		}
		
	}
}




//tabs.selecttable(tno).selectcol(cno).selectfield(i/coeff[n]%card[n])
void SELECT::orderby(char*tname,char *fldname) {
	Ordering.reserve(prod); 
	for(int i=0;i<prod;i++) {  Ordering[i]=i; }
	Marked.reserve(prod); for(int i=0;i<prod;i++) Marked[i]=false;
	int tno=tabs.gettabno(tname);
	if(tno==-1) return;
	int cno=tabs.getfieldno(tno,fldname); if(cno==-1) return;
	int n=pos[tno];
	for(int k=0;k< prod; k++) {
		
		DATUM min; min.cp(double(LONG_MAX));	
		DATUM ith;
		int p=-1;
		for(int i=0;i<prod;i++) {
			if( Marked[i] ) continue;	
			ith.cp(tabs.selectfield(tno,cno,i/coeff[n]%card[n]));
			if( ith.cmp(min,LE) ) {
		    	min.cp( ith); p=i;
			}
		}
	Marked[p]=true;
	Ordering[k]=p;
	}
	
}



void SELECT::grouporderby(AGGFUN fun,char*tname,char *fldname) {
	int total=gp->totalrecords();
	Ordering.reserve(total); 
	for(int i=0;i<total;i++) {  Ordering[i]=i; }
	Marked.reserve(total); for(int i=0;i<total;i++) Marked[i]=false;
	int tno=tabs.gettabno(tname);
	if(tno==-1) return;
	int cno=tabs.getfieldno(tno,fldname); if(cno==-1) return;
	int n=pos[tno];
	COLUMN * aggfld= getgroupfield(fun,tname,fldname);
	
	for(int k=0;k< total ; k++) {
		DATUM min; min.cp(double(LONG_MAX));	
		DATUM ith;
		int p=-1;
		for(int i=0;i< total;i++) {
			if( Marked[i] ) continue;	
			ith.cp( aggfld->selectfield(i) );
			if( ith.cmp(min,LE) ) {
		    	min.cp( ith); p=i;
			}
		}
	Marked[p]=true;
	Ordering[k]=p;
	}
	
}

void SELECT::grouporderby(char*tname,char *fldname) {
	int total=gp->totalrecords();
	Ordering.reserve(total); 
	for(int i=0;i<total;i++) {  Ordering[i]=i; }
	Marked.reserve(total); for(int i=0;i<total;i++) Marked[i]=false;
	int tno=tabs.gettabno(tname);
	if(tno==-1) return;
	int cno=tabs.getfieldno(tno,fldname); if(cno==-1) return;
	int n=pos[tno];
	
	for(int k=0;k< total; k++) {
		DATUM max; max.cp(double(-LONG_MAX));	
		DATUM ith;
		int p=-1;
		for(int i=0;i<total;i++) {
			if( Marked[i] ) continue;	
			ith.cp( gp->selectfield(i));
			if( ith.cmp(max,GT) ) {
		    	max.cp( ith); p=i;
			}
		}
	Marked[p]=true;
	Ordering[k]=p;
	}
	
}
void SELECT::orderbyasc(ASCDESC a)
{	
	_ORDERBYASC=a;
	
}


COLUMN* SELECT::subquery(COLUMN* s,COLUMN* t,COMTYPE theta,ANYALL aa) {
		DATUM d1;
		COLUMN * result=new COLUMN; result->reserve();
		result->createfield("#",BOOL);
		if( aa==ANY ) {
			for(int i=0;i<s->totalrecords();i++) {
				bool found=false;
				for(int j=0;j<t->totalrecords();j++) {
				if( s->selectfield(i).cmp(t->selectfield(j),theta)) found=true;
				}
			 d1.cp(found);
			 
			 result->insertfield(d1 );
			}
		}
		else if( aa==ALL ) {
			for(int i=0;i<s->totalrecords();i++) {
				bool found=true;
				for(int j=0;j<t->totalrecords();j++) {
				if( s->selectfield(i).cmp(t->selectfield(j),theta)==false) found=false;
				}
				
			 d1.cp(found);
			 result->insertfield(d1);
			}
		}
		
		return result;
	}
	


void SELECT::disptabs() {
	
		for(int i=0;i< tabs.gettotaltabs() ;i++ ) {
		printf("%s\n", tabs.gettabname(i));
	}
}
