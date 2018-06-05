%{
	#include "defs2.h"
	#include "y.tab.h"
	#include <stdlib.h>
	#include <string.h>
	#include <math.h>
	
%}

white	 [ \t]+
digit 	 [0-9]
alpha    [a-zA-Z]
real     {digit}*"\."{digit}+
integer  {digit}+
id       [a-zA-Z][a-zA-Z0-9]*
string   "\'"[a-zA-Z][a-zA-Z0-9]*"\'"

%%
{white}    {};
{real}     {yylval.val=atof(yytext); return _NUMBER;};
{integer}  { yylval.val=atof(yytext); return _NUMBER; };
"QUIT"     { return _QUIT; } 
"INSERT"   { return _INSERT;}
"CREATE"   {  return _CREATE;}
"SELECT"   { return _SELECT; }
"DELETE"   { return _DELETE; }
"UPDATE"   { return _UPDATE; }
"TABLE"    { return _TABLE; }
"TABS"	   { return _TABS; }
"DESC"     { return _DESC;}
"INTO"     { return _INTO;  }
"NULL"     { return _NULL;  }
"VALUES"   { return _VALUES; }
"SET"	   { return _SET;}

"PRIMARYKEY"  { return _PRIMARYKEY;}
"REFERENCES"  { return _REFERENCES; }
"UNIQUE"      { return _UNIQUE; }
"NOTNULL"     { return _NOTNULL; }
"CHECK"	      { return _CHECK;}


  
"NUMBER"   { 
	    yylval.str=new char[strlen("NUMBER")+1]; 
	    strcpy(yylval.str,"NUMBER"); return NUMBERDECL; 
           }
"VARCHAR"  {
	    yylval.str=new char[strlen("VARCHAR")+1];
	    strcpy(yylval.str,"VARCHAR"); return VARCHARDECL; 
           }


"WHERE"    { return _WHERE; }
"HAVING"   { return _HAVING; }
"ORDERBY"  { return _ORDERBY; }
"ASC"	   { return _ASC; }
"FROM"     { return _FROM;}
"GROUPBY"  { return _GROUPBY; }
"."	   { return DOT; }

"("        { return LB; }
")"        { return RB; }  
","        {}	
"+"        { return _PLUS;}
"-"	   { return _MINUS;}
"*"	   { return _MUL; }
"/"	   { return _DIV; }
"=" 	   { yylval.comtype=EQ; return _EQ; }
"!="       { yylval.comtype=NEQ; return _NEQ; }
"<" 	   { yylval.comtype=LT; return _LT; }
">"        { yylval.comtype=GT; return _GT; }
">="	   { yylval.comtype=GE; return _GE; }
"<="       { yylval.comtype=LE; return _LE; } 
"MAX" 	   { yylval.aggfun=MAX; return _MAX; }
"MIN"	   { yylval.aggfun=MIN; return _MIN; }
"COUNT"    { yylval.aggfun=COUNT; return _COUNT;}
"AVG"      { yylval.aggfun=AVG; return _AVG;}
"SUM"	   { yylval.aggfun=SUM;return _SUM; }
"AND"	   { return _AND; }
"OR"	   { return _OR;  }
"NOT"	   { return _NOT; }
"IN"	   { return _IN;}
"ANY"	   { yylval.anyall=ANY;return _ANY; }
"ALL"      { yylval.anyall=ALL;return _ALL; }

{id}       {
	  	yylval.str=new char[strlen(yytext)+1];
		strcpy(yylval.str,yytext);  return  _ID; 
	   }
{string}   { 
		// remove the leading and trailing ' character
	  	int len=strlen(yytext)+1;
		yylval.str=new char[len];
		char * buff=new char[len];
		strcpy(buff,yytext); buff[ strlen(yytext)-1]='\0';
		buff++;
		strcpy(yylval.str,buff); return _STRING;
	   }  
"\n"  return _END;
.	printf("Unrecognized Character %s",yytext);










