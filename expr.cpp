#include "defs2.h"
#include <stack>
extern TABS tabs;

NODE::NODE(OPTYPE o)  {oper=o; type=OPERATOR;}  
NODE::NODE(AGGFUN fun,char* t,char* f) {
	 strcpy(tname,t); strcpy(fname,f);type=AGGCOLUMNTYPE;
	 aggfunction=fun;
	}
NODE::NODE(char*t,char*f) { 
	
	strcpy(tname,t); strcpy(fname,f); type=COLUMNTYPE;
	}
NODE::NODE(DATUM d) { dat.cp(d); type=DATUMTYPE;}
EXPR::EXPR() { Nodes.reserve(20); }
void EXPR::clearnodes() { Nodes.clear(); }
void EXPR::addnode(AGGFUN fun,char* t,char*f) {
	strcpy(_nameexpr, NAMEAGGFUN(fun) );
	strcat(_nameexpr,"(");
	strcat(_nameexpr,f);
	strcat(_nameexpr,")");
	Nodes.push_back( NODE(fun,t,f));
}

void EXPR::addnode(char* t,char* f) {
	strcpy(_nameexpr,"*");
	strcat(_nameexpr,f);
	Nodes.push_back( NODE(t,f));
}
void EXPR::addnode(double d) {	
	DATUM d1; d1.cp(d); Nodes.push_back(d1);
}
void EXPR::addnode(char*s) {
	DATUM d1;d1.cp(s); Nodes.push_back(d1);
}
void EXPR::addnode(OPTYPE o) {
	Nodes.push_back(o);
}
char* EXPR::nameexpr() { return _nameexpr;}
int EXPR::size() { return Nodes.size(); }
NODE& EXPR::getnode(int i) { return Nodes[i]; }

void SELECT::projbegin()
{	
 	projid=0;
}
void SELECT::expbegin() 
{
	
	Expr[projid].clearnodes();
	
}
void SELECT::addnode(AGGFUN fun,char*t,char*f) {
	Expr[projid].addnode(fun,t,f);
}
void SELECT::addnode(char*t,char*f) {
	Expr[projid].addnode(t,f);
}
void SELECT::addnode(char *s) {
	Expr[projid].addnode(s); 
}
void SELECT::addnode(double d) {
	Expr[projid].addnode(d);
}
void SELECT::addnode(OPTYPE o) {
	Expr[projid].addnode(o);
}
void SELECT::expend() {
	projid++;
}

void SELECT::addallnodes() {
	projbegin();
	for(int i=0;i< NTABLES ; i++ ) {
		int tno=ipos[i];
		for( int j=0; j< tabs.gettotalcolumns(tno) ;j++) {
			expbegin();
			addnode(tabs.gettabname(tno),tabs.getfieldname(tno,j));
			expend();
		}
	}
	
}
		

void SELECT::expdisplay() 
{

	
	COLUMN * pcol[10];
	for(int i=0;i<projid;i++) 
	{
		pcol[i]= evaluate(Expr[i]);
	}
	printf("\n");
	for(int j=0;j<projid;j++) {
		printf("%7s\t",Expr[j].nameexpr()); 
	}
	printf("\n");
	int totalrecords=pcol[0]->totalrecords();
	if( _ORDERBYASC==DESC) {
	for(int i=totalrecords-1;i>=0 ;i--)  {
		
		
		for(int j=0;j<projid;j++) {
			
			
			 pcol[j]->display(Ordering[i]);
		}
		
		
		printf("\n");
	
	}
	}
	else{
	
	for(int i=0;i< totalrecords; i++)  {
		
		
		for(int j=0;j<projid;j++) {
			
			
			 pcol[j]->display(Ordering[i]);
		}
		
		
		printf("\n");
	
	}
	}
	printf("\n");
	
}
	
		
COLUMN *SELECT::firstcolumn() {
	return evaluate( Expr[0] );
}

	


COLUMN* SELECT::evaluate(EXPR& expr) {
	stack<COLUMN*> store;
	
	for(int i=0 ; i< expr.size() ;i++) 
	{
		NODE& node=expr.getnode(i);
		
		if( node.type==COLUMNTYPE && isgroupby()==false)  {
			COLUMN * col=new COLUMN;
			col=projfield(node.tname,node.fname);
			 store.push( col);
		}
		else if( node.type==AGGCOLUMNTYPE && isgroupby() ==false ) {
			COLUMN * col=new COLUMN;
			
			col=projfield(node.aggfunction,node.tname,node.fname);
			store.push(col);
		}
		
		else if( node.type==COLUMNTYPE && isgroupby() ==true ) {
			COLUMN * col=new COLUMN;
			
			col=projgroupfield(node.tname,node.fname);
			 
			
			store.push(col);
		}
		else if( node.type==AGGCOLUMNTYPE && isgroupby() ==true ) {
			COLUMN * col=new COLUMN;
			
			col=projgroupfield(node.aggfunction,node.tname,node.fname);
			store.push(col);
		}
		
		
		else if( node.type==DATUMTYPE ) {
			COLUMN* col=new COLUMN;
			col=getfield(node.dat);
			store.push(col);
		}
			 
		else if( node.type==OPERATOR && binaryop(node.oper))  {  
			COLUMN * c2=store.top(); store.pop();
			COLUMN * c1=store.top(); store.pop();
			COLUMN * c3=new COLUMN;
			int totrec=max(c1->totalrecords(),c2->totalrecords());
			c3=colbinop(c1,c2,node.oper,totrec);
			 store.push(c3);
			
		}
		else if( node.type==OPERATOR && unaryop(node.oper)) {
			COLUMN *c1=store.top() ;store.pop();
			COLUMN *c3=new COLUMN;
			c3=colunop(c1,node.oper,c1->totalrecords());
			store.push(c3);
		}
	}
	return  store.top(); 	
}	
	
