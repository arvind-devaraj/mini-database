#include "defs2.h"

extern TABS tabs;
	INSERT::INSERT() { temp.reserve(20);}
	void INSERT::inserttable(char*s) {
		tno=-1;
		insfail=false;
		for(int i=0;i< tabs.gettotaltabs();i++) {
			if(strcmp(tabs.gettabname(i),s)==0) tno=i;
		}
		if(tno==-1) printf( "notable1");
		cno=0;
	}
	void INSERT::insertfield(DATUM& d) {
		if(tno==-1) return;
		
		if(tabs.validate(tno,cno,d)==false ) insfail=true;
		temp[cno].cp(d);
		cno++;
		
	}
	void INSERT::insertfield() {
		DATUM d1; d1.cp(); 
		insertfield(d1);
	}
	void INSERT::insertfield(char* s) {
		DATUM d1; d1.cp(s);
		insertfield(d1);
	}
	void INSERT::insertfield(double d) {
		DATUM d1;d1.cp(d);
		insertfield(d1);
	}
	void INSERT::insertfield(int i) {
		insertfield((double)i);
	}
	void INSERT::insertend() {
		if( tno==-1) return;
		if(insfail) { printf("Insert failed\n");return;} 
		else if( cno!=tabs.gettotalcolumns(tno)) printf( "morefields!");
		else { 
		
		for(int i=0;i<tabs.gettotalcolumns(tno);i++) tabs.insertfield(tno,i,temp[i]);
		printf( "Record inserted\n");
		}
	}
	

	
