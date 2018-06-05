#ifndef __DEFS_H
#define __DEFS_H
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <vector>
#include "datum.h"
#include "col.h"
using namespace std;
class CREATE
{
	int ntable;
	bool tabexists;
	bool colexists;
	int colno;
	public:
	CREATE();
	void init();
	void createtable(char* s);
	void createfield(char*,char*);
	void createfield(char*name,TYPE type);
	void createfcons(CONSTRAINT);
	void createfcheck(COMTYPE,DATUM);
	void createfref(char*tname,char*fname);
	void createdfield();
	void createend() ;
};


class INSERT
{
	int tno,cno;
	vector<DATUM> temp;
	bool insfail;
	public:
	INSERT();
	void inserttable(char*s);
	void insertfield(DATUM& d);
	void insertfield(char*);
	void insertfield(double);
	void insertfield(int);
	void insertfield();
	void insertend();
};

enum NODETYPE { DATUMTYPE,COLUMNTYPE,AGGCOLUMNTYPE,OPERATOR };
class NODE
{
	public:
	DATUM dat;
	OPTYPE oper;
	AGGFUN aggfunction;
	char tname[40],fname[40];
	NODETYPE type;
	
	NODE(OPTYPE o)  ; 
	NODE(char*t,char*f); 
	NODE(AGGFUN,char*t,char*f);
	NODE(DATUM d) ; 
	
};
class EXPR
{
	vector<NODE> Nodes;
	char _nameexpr[30];
	
	public:
	EXPR();
	void clearnodes();
	void addnode(AGGFUN,char*,char*);
	void addnode(char*,char*);
	void addnode(double d);
	void addnode(char*s);
	void addnode(OPTYPE op);
	NODE& getnode(int i);
	char *nameexpr();
	int size();
	
};
	
	
	
class SELECT
{
	bool projall;
	
	int NTABLES;
	int prod;
	int grouptno,groupfno;
	int pos[10],ipos[10],card[10],coeff[10];
	COLUMN* WHERE;
	COLUMN* HAVING;
	COLUMN* gp;
	DATUM datum1;
	vector<int> Ordering;
	vector<bool> Marked;
	vector<EXPR> Expr;
	
	int projid;
	
	bool GROUPBYEXPR;
	ASCDESC _ORDERBYASC; 
	public:
	SELECT();
	bool selectstar;
	void selectbegin();
	
	
	
	void projbegin();
	void expbegin();
	void addnode(AGGFUN,char*,char*);
	void addnode(char*,char*);
	void addnode(double d);
	void addnode(char*s);
	void addnode(OPTYPE op);
	void expend();
	void projend();
	void addallnodes(); // after parsing tablenames
	void expdisplay();
	void stardisplay();
	void selecttable(char*);
	void join();

	void setwhere(COLUMN* bval);
	COLUMN* getfield(char*cval);
	COLUMN* getfield(double dval);
	COLUMN* getfield(DATUM d);
	COLUMN* getfield(char*tname,char*fname); // where eno
	
	COLUMN* getgroupfield(char*tname,char*fname); // having dno
	COLUMN* getgroupfield(AGGFUN,char*,char*); // having sum(eno)
	
	
	
	
	void groupby(int,int);
	void groupby(char*,char*);
	bool isgroupby();
	void setgroupby(bool);
	void sethaving(COLUMN*);
	
	COLUMN* subquery(COLUMN* col1,COLUMN* col2,COMTYPE t,ANYALL a);
	
	void orderby(char*,char*);
	void grouporderby(char*,char*);
	void grouporderby(AGGFUN,char*,char*);	
	void orderbyasc(ASCDESC);
		
	void del(char*tname);
	void update(char*tname,char* fname,DATUM d);
	
	
	COLUMN* evaluate(EXPR &);
	COLUMN* projfield(char*tname,char*fname);
	COLUMN* projfield(AGGFUN,char*,char*);
	COLUMN* projgroupfield(AGGFUN,char*,char*);	
	COLUMN* projgroupfield(char*tname,char*fname);
	
	void display(int,int);
	void displayall();
	void displayall(COLUMN*);
	void displaygroup();
	void disptabs();
	
	COLUMN* unop(COLUMN*s,OPTYPE op);	
	COLUMN* binop(COLUMN* s,COLUMN* t,OPTYPE op);
	COLUMN* cmp(COLUMN* s,COLUMN* t,COMTYPE);
	
	COLUMN* groupunop(COLUMN*s,OPTYPE op);	
	COLUMN* groupbinop(COLUMN* s,COLUMN* t,OPTYPE op);
	COLUMN* groupcmp(COLUMN* s,COLUMN* t,COMTYPE);
	
	COLUMN* alltrue();
	COLUMN* allhavingtrue();
	COLUMN* firstcolumn();
	
	//void expdisplay(COLUMN * bval); // display the row if corres. row in bval col is true
	void groupexpdisplay();
};

	

	


#endif

