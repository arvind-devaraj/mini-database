
#include "datum.h"
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

using namespace std;
// GENERAL FUNCTIONS
void strlower(char*s) {for(int i=0;i<strlen(s);i++)  s[i]=tolower(s[i]); }
void strupper(char*s) {for(int i=0;i<strlen(s);i++) s[i]=toupper(s[i]); }
double max(double s,double t) { return s>t ? s:t; }
double min(double s,double t) { return s<t ? s:t; }

char* NAMEAGGFUN(int i) { char* N[]={"IDENT","COUNT","MAX","MIN","SUM"}; return N[i]; }
char* NAMETYPE(int i) { char* N[]={"UNDEF","NUMBER","VARCHAR","BOOL","NULLTYPE"}; return N[i];}
bool unaryop(OPTYPE op) { if(op==NEG || op==NOT ) return true; return false; }
bool binaryop(OPTYPE op ) { if( !unaryop(op) ) return true;return false; }
// CLASS DATUM
DATUM::DATUM() {
	strcpy(cval,"$");
	dval=0.0;
}

void DATUM::display() {
	 char* TF[]={"false","true"};
 	 if (type==NUMBER ) 
	 {  if(dval-int(dval)==0) printf("%10.0lf",dval);else printf("%10.2lf",dval);}
	 else if( type==VARCHAR) printf("%10s",cval);
	 else if( type==BOOL ) printf("%10s",TF[bval]);
	 else if( type==NULLTYPE) printf("[%10s]","NULL");
	 else if( type==DELETED ) ;
	 else printf("undef1");

	}
void  DATUM::settype(TYPE t) { type=t;}
TYPE  DATUM::gettype() { return type;}
double   DATUM::getdval() { return dval;}
char*  DATUM::getcval() { return cval;}
bool  DATUM::getbval()  {return bval;}
void DATUM::cp() { type=NULLTYPE; }
void DATUM::cp(double d) { dval=d;type=NUMBER;}
void DATUM::cp(char* s) { strcpy(cval,s);type=VARCHAR; }
void DATUM::cp(bool b) {  bval=b;type=BOOL;  }
void DATUM::cp(DATUM&s) {
		type=s.gettype();
		 if(type==NUMBER) dval=s.getdval();
		 else if( type==VARCHAR) strcpy(cval,s.getcval());
		 else if( type==BOOL) bval=s.getbval();
		 else if( type==NULLTYPE) {}
		 else if( type==DELETED ) {}
		 else {printf("undef3 %d",type); s.display();}
	}

void DATUM::del() { type=DELETED;}			
DATUM* DATUM::unop(OPTYPE op)	
{
	if( type!=NUMBER && type!=VARCHAR && type!=BOOL) printf("undef8");
	if( op==NEG ) {
		if( type==NUMBER) dval=-dval;
		else printf("notallowed");
	}
	else if(op==NOT ) {
		if( type!=BOOL) printf("notallowed");
		bval=!bval;
	}
	return this;


}

	
DATUM* DATUM::binop(DATUM&s,OPTYPE op) {
		
		if( type!=NUMBER && type!=VARCHAR && type!=BOOL) { printf("undef7"); }
		if( op==ADD ) { 
			if( type==NUMBER) dval+=s.getdval();
			else if(type==VARCHAR) strcat(cval,s.getcval());
		}
		else if(op==SUB) {
			if( type==NUMBER) dval-=s.getdval();
			else if(type==VARCHAR) printf("Notallowed1"); 
		}
		else if(op==MUL) {
			if( type==NUMBER) dval*=s.getdval();
			else if( type==VARCHAR) printf("Notallowed2");
		}
		else if(op==DIV) {
			if( type==NUMBER && s.getdval()==0 ) printf("Denom=0");
			if( type==NUMBER) dval/=s.getdval();
			else if( type==VARCHAR) printf("notallowed");
		}
		else if(op==AND) {
			if( type!=BOOL || s.gettype()!=BOOL) printf("notallowed");
			bval=bval&&s.getbval();
		}
		else if(op==OR) {
			if( type!=BOOL || s.gettype()!=BOOL) printf("notallowed");
			bval=bval||s.getbval();
		}
		else printf("undef4");
		 return this;
	}
	
bool DATUM::cmp(DATUM& s,COMTYPE eq) { 
	if( type!=NUMBER && type!=VARCHAR) { printf("undef6%d",type);return false;}
	if( eq==EQ ) {
	if( type==NUMBER ) { if( fabs(dval-s.dval)<0.001) return true; return false;}
	else if( type==VARCHAR) { if( strcmp(cval,s.cval)==0) return true; return false;}
	}
	else if( eq==NEQ) {
	if( type==NUMBER) { if(fabs(dval-s.dval)>0.001) return true;return false; }
	else if( type==VARCHAR) { if(strcmp(cval,s.cval)!=0) return true;return false;}
	}
	else if( eq==LT) {
	if( type==NUMBER)  { if(fabs(dval-s.dval)>0.001 && dval<s.dval) return true; return false;}
	else if( type==VARCHAR) { if( strcmp(cval,s.cval)<0) return true;return false; }
	}
	else if( eq==GT) {
	if( type==NUMBER)  { if(fabs(dval-s.dval)>0.001 && dval>s.dval) return true; return false;}
	else if( type==VARCHAR) { if(strcmp(cval,s.cval)>0) return true; return false; }
	}
	else if( eq==LE) {
	if( type==NUMBER) { if( fabs(dval-s.dval)<0.001 || dval<s.dval) return true; return false;}
	else if( type==VARCHAR) { if( strcmp(cval,s.cval)<=0) return true;return false; }
	}
	else if( eq==GE) {
	if( type==NUMBER) {if(fabs(dval-s.dval)<0.001 || dval>s.dval) return true;return false;}
	else if(type==VARCHAR) { if(strcmp(cval,s.cval)>=0) return true;return false; }
	}
	else {printf("undef2"); return false;}
}


void DATUM::numfun(NUMFUN f)
{
	if(f==SIN) { dval=sin(dval); }
	else if(f==COS) { dval=cos(dval);}
}

void DATUM::strfun(STRFUN f)
{
	if(f==LOWER)  strlower(cval); 
	else if(f==UPPER) strupper(cval);
	
}
void DATUM::aggfun(DATUM&s,AGGFUN f)
{
if(f==MAX) { dval=max(dval,s.dval); 
	     if(strcmp(cval,s.cval)<0) strcpy(cval,s.cval);//copy max element in this
           }
else if(f==MIN) { dval=min(dval,s.dval);
	    if( strcmp(cval,s.cval)>0) strcpy(cval,s.cval); 
	    }
else if(f==COUNT) { dval+=1;} 

}

void accumulate(DATUM& acc,DATUM& data,AGGFUN f)
{
	static double count=0; 
	DATUM d1,d2;
	
	if( f==SUM )  { 
		if(acc.gettype()==UNDEF ) { acc.cp(data); }
		else acc.binop(data,ADD);
	}
	else if( f==MAX) {
		
		if( acc.gettype()==UNDEF ) acc.cp(data);
		else acc.aggfun(data,MAX);
	}
	else if( f==MIN) {
		
		if( acc.gettype()==UNDEF ) acc.cp(data);
		else acc.aggfun(data,MIN);
	}
	else if( f==COUNT ) {
		if( acc.gettype()==UNDEF) { acc.settype(NUMBER); acc.cp(1.0);}
		else acc.aggfun(data,COUNT);
	}
	else if( f==AVG )  {
		if( acc.gettype()==UNDEF)  { acc.cp(data);count=1; }
		
		else {  count++; d1.cp(count-1); acc.binop(d1,MUL);
			acc.binop(data,ADD); d1.cp(count); acc.binop(d1,DIV); 
			
		}
	}
	
	
	
}
		
/////////////////////////////////////////////////////////////////////////////////////////

DATUM * getdatum(char*s) 
{
	DATUM * d1=new DATUM;
	d1->cp(s);
	return d1;
}

DATUM* getdatum(double d)
{	
	DATUM *d1=new DATUM;
	d1->cp(d);
	return d1;
}

