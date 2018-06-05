#include "defs2.h"
#include <vector>
#include <string>
extern TABS tabs;
	CREATE::CREATE() {}
	void CREATE::init() { ntable=tabs.gettotaltabs();  tabexists=false; }	
	void CREATE::createtable(char *s) {
		tabexists=false; colexists=false;
		for(int i=0;i<ntable;i++) {
		if( strcmp(s,tabs.gettabname(i))==0 ) {tabexists=true;printf("Tab exists\n");return; }
		}
		tabs.settabname(ntable,s);
		colno=0;
	}
	void CREATE::createfield(char*name,char*type) {
		if( strcmp(type,"NUMBER")==0) createfield(name,NUMBER);
		else if( strcmp(type,"VARCHAR")==0) createfield(name,VARCHAR);
		else printf("err create.cpp");
	}
	
	void CREATE::createfield(char*name,TYPE type) {
		
		for(int i=0;i<colno;i++) {
		if( strcmp(name,tabs.getfieldname(ntable,i))==0)  
			{ colexists=true;printf("col exists\n");return; }
		}
		tabs.createfield(ntable,colno,name,type);
		
	}
	void CREATE::createfcons(CONSTRAINT c) {
		 tabs.createfcons(ntable,colno,c);
	}
	void CREATE::createfcheck(COMTYPE t,DATUM d) {
		tabs.createfcheck(ntable,colno,t,d);
	}
	void CREATE::createfref(char* tname,char* fname) {
		tabs.createfref(ntable,colno,tname,fname);
	}
	
	void CREATE::createdfield() {
		colno++;
	}
	void CREATE::createend() {
		tabs.settotalcolumns(ntable,colno);
		if(!tabexists && !colexists) { ntable++;printf("Table created\n");}
		tabs.settotaltabs(ntable); //
	}
