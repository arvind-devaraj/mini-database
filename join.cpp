#include "defs2.h"
extern TABS tabs;	
SELECT::SELECT() {
	  Expr.reserve(20);
	  WHERE=new COLUMN;
	  HAVING=new COLUMN;
	  gp=new COLUMN;
	  _ORDERBYASC=ASC;
}

void SELECT::selectbegin() {
	
	NTABLES=0;
	prod=1;
	for(int i=0;i< 10;i++) pos[i]=-1;
	Ordering.clear();
	Marked.clear();
	Expr.clear();
	projid=0;
}
void SELECT::selecttable(char*tname) {
	int tno=tabs.gettabno(tname);
	if( tno==-1) {printf( "notable3");return;}
	pos[tno]=NTABLES;
	ipos[NTABLES]=tno;
	card[NTABLES]= tabs.totalrecords(tno);
	NTABLES++;
}
void SELECT::join() {
	for(int i=0;i<=NTABLES-1;i++)  prod=prod*card[i];
	coeff[NTABLES-1]=1;
	for(int j=NTABLES-2;j>=0;j--) coeff[j]=coeff[j+1]*card[j+1];
	Ordering.reserve(prod);
	for(int i=0;i<prod;i++) { Ordering[i]=i; }


}

