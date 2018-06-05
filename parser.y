%{
	#include <stdio.h>
	#include "defs2.h"
	extern int yyparse(),yyerror(char*),yylex();
	CREATE cm; INSERT im;
	SELECT* sm[5]; 
	
	
	COLUMN res1;
	DATUM d1;
	TABS tabs;
	void createandinsert();
	void initsm();
	int sq=0;
	
	
%}
%union{ double val;int integer;char *str; DATUM* data;
        COLUMN *col;bool tf; COMTYPE comtype;AGGFUN aggfun; ANYALL anyall; ASCDESC ascdesc;}
%token _NOTNULL _CHECK _PRIMARYKEY _UNIQUE _REFERENCES
%token <str> VARCHARDECL NUMBERDECL 	
%token  _QUIT _INSERT _CREATE _SELECT _DELETE _UPDATE _WHERE _TABLE _TABS 
%token  _END LB RB _FROM DOT _DESC  _NULL _INTO _VALUES  _SET
%token _GROUPBY _HAVING _ORDERBY 
%token _IN _NOT
%token COMMA
%token<comtype>    _EQ _NEQ _GT _LT _GE _LE 
%token<aggfun>  _MAX _MIN _SUM _COUNT _AVG
%token<anyall> _ANY _ALL 
%token<ascdesc> _ASC _DESC
%token<str> _ID
%token<str> _STRING
%left _AND _OR 
%right _NOT
%left _PLUS _MINUS
%left _MUL _DIV
%left UNARYMINUS

%type <str> columnname  
%type <str>  tablename wtablename
%type <aggfun> afun
%type <comtype> relop
%type <ascdesc> ascdescnt
%type <anyall> anyallnt
%type <col> boolean and not cmpr expression times  neg term
%type <col> gboolean gand gnot gcmpr gexpression gtimes gneg gterm
%type <col> cmpr gcmpr
%type <col> simpleterm 
%type <col> optwher opthaving
%type <str> ptable pfield gtable gfield
%type <col> subquery

%token<val> _NUMBER
%token<str> _STRING
///////////////////////////////////////////////////////////////////////////////

%type <str> kcolumnname
%type <str> kdatatype ktablename
%type <comtype> krelop
%type <data> ksimpleterm
%type <data> kexpression ktimes kneg  kterm
%type <data> kvalue kck_value

%start input

%%

input		:
		| input line;
line  		: _END 
		|statement { printf("SQL>");}   _END;
		
statement	: query  
		| _CREATE kcreate
		| _INSERT kinsert  
		| _DELETE _FROM ktablename _WHERE cmpr { sm[sq]->del($3); }
		| _UPDATE ktablename _SET kcolumnname _EQ kvalue  _WHERE cmpr { sm[sq]->update($2,$4,*$6); }
		| _TABS  { sm[sq]->disptabs(); }
		| _DESC ktablename { tabs.describe($2); }
		| _QUIT  { return 0;} 
		| error {printf("sql parse error");}


query		: subquery {  sm[sq]->expdisplay();  }

subquery	: _SELECT    { sm[sq]-> selectbegin(); }  
		  optprojexps
		  _FROM selecttabs 
		  optwher { sm[sq]-> setwhere($6);}  // optwher---> subquery 
		  optgroupby  
		  opthaving { sm[sq]-> sethaving($9); }
		  optorderby 
		  { 
			  
			  //sm[sq]-> expdisplay(); 
			  $$=sm[sq]-> firstcolumn();
		
		  }

// parsing subqueries 			 
// optwher derives subquery in one or more steps making nested subqueries possible
// see the production  cmpr==> ..... subquery .....   which are grouped under WHERE productions


////////////////////////////////////////////////////////////////////////////////////////
////////    select emp.eno+emp.dno, emp.eno*emp.dno from emp  //////////////////////////
////////    emp.eno+emp.dno is a projexp ( project expression) /////////////////////////
////////////////////////////////////////////////////////////////////////////////////////


optprojexps	: projexps { sm[sq]-> selectstar=false; }
		| _MUL { sm[sq]-> selectstar=true; }		 
projexps	: projexps projexp  | projexp
projexp		: { sm[sq]-> expbegin();} pexpression {  sm[sq]-> expend();  }
pexpression	: pexpression _PLUS ptimes  { sm[sq]-> addnode(ADD); }
		| pexpression _MINUS ptimes { sm[sq]-> addnode(SUB); }
		| ptimes
		
ptimes		: ptimes _MUL pneg { sm[sq]-> addnode(MUL); }
		| ptimes _DIV pneg { sm[sq]-> addnode(DIV); }
		| pneg
pneg		: pterm | _MINUS pterm { sm[sq]-> addnode(NEG); }
pterm		: projcol
		| projaggcol
		| pnumber 
		| pstring

projcol		: ptable DOT pfield  { sm[sq]-> addnode($1,$3);}
projaggcol	: afun LB ptable DOT pfield RB { sm[sq]-> addnode($1,$3,$5); }
afun		: _MAX | _MIN | _COUNT | _SUM | _AVG

ptable		: _ID
pfield		: _ID 
pnumber		: _NUMBER { sm[sq]-> addnode($1); }
pstring		: _STRING { sm[sq]-> addnode($1); }

/////////////////////////////////////////////////////////////////////////////////////////
////////////////////////  .. FROM dept,emp ...  after this tables must be joined ////////
/////////////////////////////////////////////////////////////////////////////////////////


selecttabs	:  tablenames { sm[sq]-> join();  if(sm[sq]-> selectstar) sm[sq]-> addallnodes(); }
tablenames	: tablenames,tablename | tablename 
tablename	: _ID { sm[sq]-> selecttable($1); }
		  
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////// ... WHERE emp.eno=dept.dno... optional where/////////////////////////
////////////////////////// emp.dno=dept.dno evaluates to a boolean column  /////////////////
////////////////a row in bool column contains true if that row satisfies the query /////////
////////////////////////////////////////////////////////////////////////////////////////////


optwher		:  { $$=sm[sq]-> alltrue();} 
		 | _WHERE boolean { $$=$2; }
		 

boolean		: and {$$=$1;} | and _OR boolean {$$=sm[sq]-> binop($1,$3,OR); }
and		: not {$$=$1;} | not _AND and { $$=sm[sq]-> binop($1,$3,AND); }
not		: cmpr { $$=$1; }| _NOT cmpr {$$=sm[sq]-> unop($2,NOT); }
cmpr		:  expression relop expression { $$=sm[sq]-> cmp($1,$3,$2);  }
cmpr		:  expression relop anyallnt LB {sq++;} subquery { sq--;} RB 
			{ $$=sm[sq]->subquery($1,$6,$2,$3);  }
cmpr		:  expression  _IN  LB {sq++;} subquery { sq--;} RB 
			{ $$=sm[sq]->subquery($1,$6,EQ,ANY);  }

cmpr		:  expression _NOT _IN LB {sq++;} subquery { sq--;} RB 
			{ $$=sm[sq]->subquery($1,$6,NEQ,ALL);  }
						
cmpr		:  LB boolean RB { $$=$2; }

expression	: expression _PLUS times { $$=sm[sq]-> binop($1,$3,ADD); }
		| expression _MINUS times { $$=sm[sq]-> binop($1,$3,SUB); }
		| times            { $$=$1; }
times		: times _MUL neg { $$=sm[sq]-> binop($1,$3,MUL); }
		| times _DIV neg { $$=sm[sq]-> binop($1,$3,DIV); }
		| neg { $$=$1;}
neg		: term { $$=$1;}  | _MINUS term %prec UNARYMINUS { $$=sm[sq]-> unop($2,NEG); }
term	 	: wtablename DOT columnname 
		 {  $$=sm[sq]-> getfield($1,$3);}
term		: simpleterm 
term		: LB expression RB { $$=$2; }
simpleterm	: _STRING { $$=sm[sq]-> getfield($1); }
		| _NUMBER { $$=sm[sq]-> getfield($1); }		 
wtablename	: _ID { $$=$1; }
columnname	: _ID { $$=$1; }
relop		: _EQ| _NEQ| _GT|_GE|_LT|_LE
anyallnt	: _ANY | _ALL
		  		 
/////////////////////////////////////////////////////////////////////////////////////////////		 
///////////////////////// optional group by. having clause is also implemented //////////////
///////////////////////// using groupcmp functions //////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

		
optgroupby	: { sm[sq]-> setgroupby(false);  }
		| groupby 		   
groupby		: _GROUPBY gtable  DOT gfield { sm[sq]-> groupby($2,$4);  }		    
opthaving	: { $$=sm[sq]-> allhavingtrue(); }
		| _HAVING gcmpr{ $$=$2;}
		


gboolean	: gand {$$=$1;} | gand _OR gboolean {$$=sm[sq]-> groupbinop($1,$3,OR); }
gand		: gnot {$$=$1;} | gnot _AND gand { $$=sm[sq]-> groupbinop($1,$3,AND); }
gnot		: gcmpr { $$=$1; }| _NOT gcmpr {$$=sm[sq]-> groupunop($2,NOT); }
gcmpr		:  gexpression relop gexpression { $$=sm[sq]-> groupcmp($1,$3,$2);  }
gcmpr		:  LB gboolean RB { $$=$2; }



gexpression	: gexpression _PLUS gtimes { $$=sm[sq]-> groupbinop($1,$3,ADD); }
		| gexpression _MINUS gtimes { $$=sm[sq]-> groupbinop($1,$3,SUB); }
		| gtimes { $$=$1; }
gtimes		: gtimes _MUL gneg { $$=sm[sq]-> groupbinop($1,$3,MUL); }
		| gtimes _DIV gneg { $$=sm[sq]-> groupbinop($1,$3,DIV); }
		| gneg  { $$=$1; }
gneg		: gterm  { $$=$1; }
		| _MINUS gterm %prec UNARYMINUS { $$=sm[sq]-> groupunop($2,NEG); }

gterm		: gtable DOT gfield { $$=sm[sq]-> getgroupfield($1,$3);  }
gterm		: afun LB gtable DOT gfield RB  { $$=sm[sq]-> getgroupfield($1,$3,$5);  }
gterm		: simpleterm 
gtable		: _ID
gfield		: _ID

////////////////////////////////////////////////////////////////////////////////////////////
optorderby	:
		| _ORDERBY wtablename DOT columnname { 
			if( sm[sq]->isgroupby()==false)  sm[sq]->orderby($2,$4); 
			else  sm[sq]->grouporderby($2,$4);
		  } ascdescnt 

		| _ORDERBY afun LB tablename DOT columnname RB {
			 sm[sq]->grouporderby($2,$4,$6);
		 }  ascdescnt 
ascdescnt	:  { sm[sq]->orderbyasc(ASC); }
		| _ASC { sm[sq]->orderbyasc(ASC);} 
		| _DESC { sm[sq]->orderbyasc(DESC);  }


///////////////////////////////  CREATE //////////////////////////////////////////////////////

kcreate		: _TABLE ktablename{ cm.createtable($2); } LB kcreatecols RB { cm.createend(); }
ktablename	: _ID
kcreatecols	: kcreatecol,kcreatecols | kcreatecol
kcreatecol	: kcolumnname kdatatype{ cm.createfield($1,$2);} kconstraint { cm.createdfield();}
kconstraints     : kconstraints DOT kconstraint | kconstraint
kconstraint      :
		 |_NOTNULL { cm.createfcons(NOTNULL); }
		 |_UNIQUE { cm.createfcons(UNIQ); }
		 |_PRIMARYKEY{ cm.createfcons(PRKEY); }
		 |_CHECK  { cm.createfcons(CHECK); }  kcheckconstraint;
		 |_REFERENCES { cm.createfcons(FRKEY);} kreference
kcheckconstraint : kcolumnname krelop  kck_value { cm.createfcheck($2,*$3);  }
krelop		: _EQ|_NEQ|_GT|_LT|_GE|_LE
kreference	: ktablename DOT kcolumnname { cm.createfref($1,$3); }	 

kdatatype	: NUMBERDECL | VARCHARDECL
kcolumnname	:_ID 
kck_value	: kexpression { $$=new DATUM; $$->cp($1); }

///////////////////////////  INSERT ////////////////////////////////////////////////////// 

kinsert		: _INTO ktablename { im.inserttable($2); } kinsertvals { im.insertend(); }
kinsertvals	: _VALUES LB kvaluelist RB
kvaluelist	: kvalue,kvaluelist| kvalue
kvalue		: kexpression { im.insertfield(*$1); }
		 | _NULL { im.insertfield(); }

kexpression	: kexpression _PLUS ktimes  { $$=$1->binop(*$3,ADD);  }
		| kexpression _MINUS ktimes { $$=$1->binop(*$3,SUB); }
		| ktimes     { $$=$1; }
ktimes 		: ktimes _MUL  kneg  { $$=$1->binop(*$3,MUL);; }
		| ktimes _DIV  kneg  { $$=$1->binop(*$3,DIV);  }
		| kneg        { $$=$1; }
kneg		: kterm  { $$=$1; }
		  | _MINUS  kterm  %prec UNARYMINUS {$$=$2->unop(NEG);  }
kterm		: LB kexpression RB  {$$=$2;}
		| ksimpleterm { $$=$1;  }
		 
ksimpleterm	:  _STRING { $$=getdatum($1); }
		 | _NUMBER { $$=getdatum($1); }
















%%
#include <fstream>
void createandinsert();
int yyerror(char*s) { ;return 0; }
int main(int argc,char** argv) {

//ifstream in("OBJ.DAT"); tabs.readfile(in);  
createandinsert();
tabs.displayall();
cm.init();
initsm();
printf("SQL>");
yyparse(); 
ofstream out("OBJ.DAT"); tabs.writefile(out); 
return 0;
}	

void initsm() {
	for(int i=0;i<5;i++) 
	{
	sm[i]=new SELECT;
	}
}







