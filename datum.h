#ifndef __DATUM_H
#define __DATUM_H
#include <stdio.h>
enum TYPE{ UNDEF,NUMBER,VARCHAR,BOOL,NULLTYPE,DELETED};
enum COMTYPE{ EQ,NEQ,LT,GT,LE,GE };
enum OPTYPE{ ADD,SUB,MUL,DIV,NEG,AND,OR,NOT};
enum STRFUN{ UPPER,LOWER};
enum NUMFUN{ SIN,COS };
enum AGGFUN{ IDENT,COUNT,MAX,MIN,SUM,AVG };
enum ANYALL{ ANY,ALL};
enum CONSTRAINT{ NOTNULL,CHECK,UNIQ,PRKEY,FRKEY};
enum ASCDESC{ ASC,DESC };
class DATUM{
	double dval; 
	char cval[40];
	bool bval;
	TYPE type;
	
	public:
	
	DATUM::DATUM();	
	void display() ;
	
        void settype(TYPE t) ;
	TYPE  gettype() ;
	double  getdval();
	char*  getcval();
	bool  getbval();
	
	
	void cp();
	void cp(double d) ;
	
	
	void cp(char* s) ;
	void cp(bool b) ;
	void cp(DATUM&s);
	void del();
	bool cmp(DATUM& s,COMTYPE t);
	DATUM* binop(DATUM &s,OPTYPE t);
	DATUM* unop(OPTYPE t);
	void strfun(STRFUN);
	void numfun(NUMFUN);
	void aggfun(DATUM&s,AGGFUN);
	
};

DATUM* getdatum(char*s);
DATUM* getdatum(double d);
bool binaryop(OPTYPE op);
bool unaryop(OPTYPE op);
void accumulate(DATUM&,DATUM&,AGGFUN);
char* NAMEAGGFUN(int x);
char* NAMETYPE(int x);
#endif
