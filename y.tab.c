#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif
#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#define YYRECOVERING (yyerrflag!=0)
#define YYPREFIX "yy"
#line 2 "parser.y"
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
	
	
#line 18 "parser.y"
typedef union{ double val;int integer;char *str; DATUM* data;
        COLUMN *col;bool tf; COMTYPE comtype;AGGFUN aggfun; ANYALL anyall; ASCDESC ascdesc;} YYSTYPE;
#line 31 "y.tab.c"
#define _NOTNULL 257
#define _CHECK 258
#define _PRIMARYKEY 259
#define _UNIQUE 260
#define _REFERENCES 261
#define VARCHARDECL 262
#define NUMBERDECL 263
#define _QUIT 264
#define _INSERT 265
#define _CREATE 266
#define _SELECT 267
#define _DELETE 268
#define _UPDATE 269
#define _WHERE 270
#define _TABLE 271
#define _TABS 272
#define _END 273
#define LB 274
#define RB 275
#define _FROM 276
#define DOT 277
#define _DESC 278
#define _NULL 279
#define _INTO 280
#define _VALUES 281
#define _SET 282
#define _GROUPBY 283
#define _HAVING 284
#define _ORDERBY 285
#define _IN 286
#define _NOT 287
#define COMMA 288
#define _EQ 289
#define _NEQ 290
#define _GT 291
#define _LT 292
#define _GE 293
#define _LE 294
#define _MAX 295
#define _MIN 296
#define _SUM 297
#define _COUNT 298
#define _AVG 299
#define _ANY 300
#define _ALL 301
#define _ASC 302
#define _ID 303
#define _STRING 304
#define _AND 305
#define _OR 306
#define _PLUS 307
#define _MINUS 308
#define _MUL 309
#define _DIV 310
#define UNARYMINUS 311
#define _NUMBER 312
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,   43,   45,   43,   44,   44,   44,   44,   44,
   44,   44,   44,   44,   46,   50,   53,   55,   31,   49,
   49,   56,   56,   59,   57,   58,   58,   58,   60,   60,
   60,   61,   61,   62,   62,   62,   62,   63,   64,    4,
    4,    4,    4,    4,   27,   28,   65,   66,   51,   67,
   67,    2,   25,   25,    8,    8,    9,    9,   10,   10,
   11,   68,   69,   11,   70,   71,   11,   72,   73,   11,
   11,   12,   12,   12,   13,   13,   13,   14,   14,   15,
   15,   15,   24,   24,    3,    1,    5,    5,    5,    5,
    5,    5,    7,    7,   52,   52,   74,   26,   26,   16,
   16,   17,   17,   18,   18,   19,   19,   20,   20,   20,
   21,   21,   21,   22,   22,   23,   23,   23,   29,   30,
   54,   75,   54,   76,   54,    6,    6,    6,   77,   47,
   34,   78,   78,   81,   79,   82,   82,   80,   80,   80,
   80,   84,   80,   86,   80,   83,   35,   35,   35,   35,
   35,   35,   85,   33,   33,   32,   42,   88,   48,   87,
   89,   89,   41,   41,   37,   37,   37,   38,   38,   38,
   39,   39,   40,   40,   36,   36,
};
short yylen[] = {                                         2,
    0,    2,    1,    0,    3,    1,    2,    2,    5,    8,
    1,    2,    1,    1,    1,    0,    0,    0,   11,    1,
    1,    2,    1,    0,    2,    3,    3,    1,    3,    3,
    1,    1,    2,    1,    1,    1,    1,    3,    6,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    2,
    1,    1,    0,    2,    1,    3,    1,    3,    1,    2,
    3,    0,    0,    8,    0,    0,    7,    0,    0,    8,
    3,    3,    3,    1,    3,    3,    1,    1,    2,    3,
    1,    3,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    0,    1,    4,    0,    2,    1,
    3,    1,    3,    1,    2,    3,    3,    3,    3,    1,
    3,    3,    1,    1,    2,    3,    6,    1,    1,    1,
    0,    0,    6,    0,    9,    0,    1,    1,    0,    6,
    1,    2,    1,    0,    4,    3,    1,    0,    1,    1,
    1,    0,    3,    0,    3,    3,    1,    1,    1,    1,
    1,    1,    3,    1,    1,    1,    1,    0,    4,    4,
    2,    1,    1,    1,    3,    3,    1,    3,    3,    1,
    1,    2,    3,    1,    1,    1,
};
short yydefred[] = {                                      1,
    0,   14,   13,    0,    0,   16,    0,    0,   11,    3,
    0,   15,    2,    4,    6,    0,    8,    0,    7,    0,
    0,  131,    0,   12,    0,  158,  129,   21,    0,    0,
   23,    0,    0,    0,    5,    0,    0,    0,   22,   40,
   41,   43,   42,   44,   45,   48,    0,   47,    0,    0,
    0,    0,   31,   32,   34,   35,   36,   37,    0,  156,
    0,    0,  159,    0,   52,   51,    0,    0,   33,    0,
    0,    0,    0,    0,    0,    0,   85,   83,    0,   84,
    0,    9,    0,    0,   77,   78,   81,    0,    0,    0,
    0,    0,    0,   17,   50,    0,   46,   38,    0,    0,
   29,   30,    0,    0,    0,    0,   59,    0,    0,   79,
    0,    0,    0,   87,   88,   89,   91,   90,   92,    0,
    0,    0,    0,    0,    0,  164,  175,    0,  176,  174,
    0,    0,  170,  171,    0,    0,    0,  155,  154,  134,
  130,  132,   54,    0,    0,   60,   71,    0,    0,   82,
    0,   86,   80,   65,    0,    0,    0,   93,   94,    0,
    0,   75,   76,    0,  172,    0,    0,    0,    0,    0,
  161,  160,    0,    0,    0,   96,    0,   56,   58,    0,
   68,   62,  173,    0,    0,  168,  169,   10,  139,  142,
  141,  140,  144,  135,  119,    0,    0,   18,   39,   66,
    0,    0,    0,    0,    0,    0,    0,    0,   99,    0,
    0,  113,  114,  118,    0,    0,    0,   69,   63,    0,
  143,    0,  145,  120,   97,    0,    0,    0,    0,  104,
  115,    0,    0,    0,    0,    0,    0,    0,    0,   19,
   67,    0,    0,  147,  148,  149,  150,  151,  152,    0,
    0,  105,  107,    0,    0,    0,    0,    0,    0,  111,
  112,  116,    0,    0,   70,   64,    0,  146,  153,  101,
  103,    0,    0,    0,    0,  122,    0,  117,    0,    0,
  128,  127,  123,    0,  124,    0,  125,
};
short yydgoto[] = {                                       1,
  153,   66,   81,  208,  122,  283,  160,  104,  105,  106,
  107,   83,   84,   85,   86,  227,  228,  229,  230,  210,
  211,  212,  213,   87,   94,  198,   50,   98,  215,  225,
   12,   90,  140,   23,  250,  130,  131,  132,  133,  134,
  136,  268,   13,   14,   25,   15,   19,   17,   29,   20,
   67,  175,  144,  240,  216,   30,   31,   51,   32,   52,
   53,   54,   55,   56,   57,   58,   68,  202,  243,  180,
  217,  201,  242,  176,  279,  286,   37,   91,   92,  194,
  173,    0,  221,  203,  223,  204,   63,   36,  137,
};
short yysindex[] = {                                      0,
  243,    0,    0, -259, -241,    0, -238, -209,    0,    0,
 -209,    0,    0,    0,    0, -209,    0, -209,    0, -222,
 -209,    0, -154,    0, -170,    0,    0,    0, -136,    0,
    0,  192, -156, -195,    0, -137, -127, -115,    0,    0,
    0,    0,    0,    0,    0,    0,  276,    0, -107, -101,
 -289, -285,    0,    0,    0,    0,    0,    0, -223,    0,
 -104,  -81,    0, -195,    0,    0,  -72, -115,    0,  -66,
  -64,  192,  192,  192,  192, -142,    0,    0, -264,    0,
  -67,    0,  233, -211,    0,    0,    0, -131, -131, -124,
  -14, -195, -142,    0,    0,  -36,    0,    0, -285, -285,
    0,    0, -223,    6,  -63,  -22,    0,  171, -125,    0,
  -18,   12,   14,    0,    0,    0,    0,    0,    0, -125,
 -125, -181, -125, -125, -118,    0,    0, -254,    0,    0,
 -150, -138,    0,    0,   28, -131,   26,    0,    0,    0,
    0,    0,    0,   20,  -64,    0,    0, -142, -142,    0,
 -239,    0,    0,    0,   31, -211, -211,    0,    0,   32,
 -111,    0,    0, -216,    0, -118, -118, -118, -118, -223,
    0,    0,  143,   -1,   35,    0,   37,    0,    0,   53,
    0,    0,    0, -138, -138,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   44, -144,    0,    0,    0,
   53,   53, -195, -209,   21, -162,  286,   48,    0,  239,
  -96,    0,    0,    0,   49,   42,   63,    0,    0,  158,
    0,   51,    0,    0,    0, -144,   70,   40,   43,    0,
    0,   -1,  240,  240,  240,  240,  240,   21,  296,    0,
    0,   72,   75,    0,    0,    0,    0,    0,    0, -118,
 -195,    0,    0, -162, -162,   77,  -96,  -96,  -89,    0,
    0,    0,   87,   78,    0,    0, -150,    0,    0,    0,
    0,   21,  -18, -115,   96,    0,   95,    0, -176,  -18,
    0,    0,    0,   99,    0, -176,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  258,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -32,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   -8,  -92,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -84,    9,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   24,    0,    0,    0,    0,    0,    0,
    0,  102,    0,    0,    0,    0,    0,    0,  -74,  -50,
    0,    0,    0,    0,  103,  -33,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -191, -242,    0,    0,    0,  104,    0,    0,    0,    0,
    0,    0,    0, -110,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   50,   76,    0,    0,    0,
  197,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -185,    0,  -93,    0,    0,    0,    0,    0,
    0,    0,    0, -203, -197,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  100,    0,    0,    0,    0, -244,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  105, -189,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  124,  148,  200,    0,
    0,    0,    0,    0,    0,    0, -179,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -178,    0,
    0,    0,    0,    0,    0, -178,    0,
};
short yygindex[] = {                                      0,
 -258,  -65,  114,  -31,  185,  110,    0,  -85,  249,    0,
  -54,  -62,  107,  108,  331,  157,  164,    0, -174,  177,
    2,   19,  213, -180,    0,    0,  352,  279, -168, -227,
 -167,  -34,    0,   -9,    0,    0, -121,   93,  101,  297,
  338,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  397,    0,    0,  202,
  203,  381,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  342,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  299,
};
#define YYTABLESIZE 599
short yytable[] = {                                      61,
   49,   24,   95,  164,   82,  196,   26,  143,   27,  109,
  262,   33,  200,  108,  276,   49,  214,   72,   73,  125,
   16,  284,  209,   74,   75,  214,  214,  167,  121,   18,
  121,  167,  167,  218,  219,  150,  167,   21,   77,   78,
   49,   49,   49,   49,  275,  214,  151,   80,  146,  127,
   76,  252,  214,  214,  214,  214,  214,  129,  183,  161,
  167,  167,  178,  256,  167,  167,  165,  120,  121,  167,
  165,  165,  166,  214,  214,  165,  166,  166,  163,   77,
   78,  166,  163,  163,   79,  102,   28,  163,   80,  138,
  166,  167,  109,   22,  126,  157,  126,  123,  124,  165,
  165,  281,   35,  165,  165,  166,  166,   60,  165,  166,
  166,  206,  163,   59,  166,  188,  102,  138,  158,  159,
  163,   77,   78,  157,  226,  282,   79,   34,  267,  206,
   80,   76,   40,   41,   42,   43,   44,  138,  139,   38,
  195,   78,  125,   62,  103,  207,   64,  126,  109,   80,
   40,   41,   42,   43,   44,  125,  166,  167,  195,   78,
   77,   78,   95,  207,   95,   79,   70,   80,  220,   80,
  168,  169,  127,   95,   95,   71,  128,   77,   78,   98,
  129,   98,   79,   28,   88,  127,   80,   65,   53,  128,
   53,   98,   89,  129,  222,  120,  121,   93,   53,   53,
   53,   26,   28,   28,   28,   28,   28,  264,  277,  111,
   28,   28,  236,  237,   28,   28,  269,  233,  234,   28,
   26,   26,   26,   26,   26,   27,  156,  157,   26,   26,
  162,  163,   26,   26,  257,  258,   45,   26,   97,   57,
  145,   57,  148,   20,   27,   27,   27,   27,   27,   57,
   57,   57,   27,   27,  260,  261,   27,   27,  184,  185,
  141,   27,   24,   24,   24,   24,   24,   25,  186,  187,
   24,   24,   57,   99,  100,   24,  101,  102,   49,   24,
  147,   49,  149,   49,  152,  154,   25,   25,   25,   25,
   25,   49,   49,   49,   25,   25,   74,  170,   74,  155,
  172,  195,  174,   25,  181,  182,   74,   74,   74,   74,
   74,  199,   74,   74,   74,   74,   74,   74,  197,    6,
  205,  232,   72,  224,   72,  238,  239,  251,   74,   74,
   74,   74,   72,   72,   72,   72,   72,  241,   72,   72,
   72,   72,   72,   72,  253,  254,  265,  255,   73,  266,
   73,  274,  263,  272,   72,   72,   72,   72,   73,   73,
   73,   73,   73,  273,   73,   73,   73,   73,   73,   73,
  278,  280,  110,  285,  110,   55,  133,   55,  162,  100,
   73,   73,   73,   73,  110,   55,   55,   55,  110,  110,
  110,  110,  110,  110,  235,  287,  108,  179,  108,  189,
  190,  191,  192,  193,  110,  110,  110,  110,  108,  110,
  270,  259,  108,  108,  108,  108,  108,  108,  271,  231,
  109,   96,  109,  177,  165,  135,   39,   69,  108,  108,
  108,  108,  109,  142,  171,    0,  109,  109,  109,  109,
  109,  109,    0,    0,    0,  150,  244,  245,  246,  247,
  248,  249,  109,  109,  109,  109,  112,  113,    0,  114,
  115,  116,  117,  118,  119,    0,    0,    0,    0,   61,
    0,   61,  106,    0,  106,    0,    0,  120,  121,   61,
   61,   61,    0,    0,  106,    0,   40,   41,   42,   43,
   44,    0,    0,    0,   45,   46,    0,    0,    2,   47,
    0,   61,   61,   48,  106,  106,    3,    4,    5,    6,
    7,    8,    0,    0,    9,   10,    0,    0,  112,  113,
   11,  114,  115,  116,  117,  118,  119,  114,  115,  116,
  117,  118,  119,    0,   40,   41,   42,   43,   44,  120,
  121,    0,  195,   78,    0,  233,  234,  207,    0,    0,
    0,   80,   24,   24,   24,   24,   24,    0,    0,    0,
   24,   24,    0,    0,    0,   24,    0,    0,    0,   24,
   40,   41,   42,   43,   44,    0,    0,    0,   45,   46,
   40,   41,   42,   43,   44,    0,    0,   48,  195,   78,
   40,   41,   42,   43,   44,    0,    0,   80,   77,
};
short yycheck[] = {                                      34,
   32,   11,   68,  125,   59,  174,   16,   93,   18,  274,
  238,   21,  180,   76,  273,   47,  197,  307,  308,  274,
  280,  280,  197,  309,  310,  206,  207,  270,  273,  271,
  275,  274,  275,  201,  202,  275,  279,  276,  303,  304,
   72,   73,   74,   75,  272,  226,  109,  312,  103,  304,
  274,  226,  233,  234,  235,  236,  237,  312,  275,  122,
  303,  304,  148,  232,  307,  308,  270,  307,  308,  312,
  274,  275,  270,  254,  255,  279,  274,  275,  270,  303,
  304,  279,  274,  275,  308,  275,  309,  279,  312,  275,
  307,  308,  274,  303,  273,  275,  275,  309,  310,  303,
  304,  278,  273,  307,  308,  303,  304,  303,  312,  307,
  308,  274,  304,  270,  312,  170,  306,  303,  300,  301,
  312,  303,  304,  303,  287,  302,  308,  282,  250,  274,
  312,  274,  295,  296,  297,  298,  299,  262,  263,  276,
  303,  304,  274,  281,  287,  308,  274,  279,  274,  312,
  295,  296,  297,  298,  299,  274,  307,  308,  303,  304,
  303,  304,  273,  308,  275,  308,  274,  312,  203,  312,
  309,  310,  304,  284,  285,  277,  308,  303,  304,  273,
  312,  275,  308,  276,  289,  304,  312,  303,  273,  308,
  275,  285,  274,  312,  204,  307,  308,  270,  283,  284,
  285,  276,  295,  296,  297,  298,  299,  239,  274,  277,
  303,  304,  309,  310,  307,  308,  251,  307,  308,  312,
  295,  296,  297,  298,  299,  276,  120,  121,  303,  304,
  123,  124,  307,  308,  233,  234,  303,  312,  303,  273,
  277,  275,  306,  276,  295,  296,  297,  298,  299,  283,
  284,  285,  303,  304,  236,  237,  307,  308,  166,  167,
  275,  312,  295,  296,  297,  298,  299,  276,  168,  169,
  303,  304,  306,   72,   73,  308,   74,   75,  270,  312,
  275,  273,  305,  275,  303,  274,  295,  296,  297,  298,
  299,  283,  284,  285,  303,  304,  273,  270,  275,  286,
  275,  303,  283,  312,  274,  274,  283,  284,  285,  286,
  287,  275,  289,  290,  291,  292,  293,  294,  284,  267,
  277,  274,  273,  303,  275,  277,  285,  277,  305,  306,
  307,  308,  283,  284,  285,  286,  287,  275,  289,  290,
  291,  292,  293,  294,  275,  306,  275,  305,  273,  275,
  275,  274,  239,  277,  305,  306,  307,  308,  283,  284,
  285,  286,  287,  277,  289,  290,  291,  292,  293,  294,
  275,  277,  273,  275,  275,  273,  275,  275,  275,  275,
  305,  306,  307,  308,  285,  283,  284,  285,  289,  290,
  291,  292,  293,  294,  210,  286,  273,  149,  275,  257,
  258,  259,  260,  261,  305,  306,  307,  308,  285,   79,
  254,  235,  289,  290,  291,  292,  293,  294,  255,  207,
  273,   70,  275,  145,  128,   88,   30,   47,  305,  306,
  307,  308,  285,   92,  136,   -1,  289,  290,  291,  292,
  293,  294,   -1,   -1,   -1,  275,  289,  290,  291,  292,
  293,  294,  305,  306,  307,  308,  286,  287,   -1,  289,
  290,  291,  292,  293,  294,   -1,   -1,   -1,   -1,  273,
   -1,  275,  273,   -1,  275,   -1,   -1,  307,  308,  283,
  284,  285,   -1,   -1,  285,   -1,  295,  296,  297,  298,
  299,   -1,   -1,   -1,  303,  304,   -1,   -1,  256,  308,
   -1,  305,  306,  312,  305,  306,  264,  265,  266,  267,
  268,  269,   -1,   -1,  272,  273,   -1,   -1,  286,  287,
  278,  289,  290,  291,  292,  293,  294,  289,  290,  291,
  292,  293,  294,   -1,  295,  296,  297,  298,  299,  307,
  308,   -1,  303,  304,   -1,  307,  308,  308,   -1,   -1,
   -1,  312,  295,  296,  297,  298,  299,   -1,   -1,   -1,
  303,  304,   -1,   -1,   -1,  308,   -1,   -1,   -1,  312,
  295,  296,  297,  298,  299,   -1,   -1,   -1,  303,  304,
  295,  296,  297,  298,  299,   -1,   -1,  312,  303,  304,
  295,  296,  297,  298,  299,   -1,   -1,  312,  303,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 312
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"_NOTNULL","_CHECK","_PRIMARYKEY",
"_UNIQUE","_REFERENCES","VARCHARDECL","NUMBERDECL","_QUIT","_INSERT","_CREATE",
"_SELECT","_DELETE","_UPDATE","_WHERE","_TABLE","_TABS","_END","LB","RB",
"_FROM","DOT","_DESC","_NULL","_INTO","_VALUES","_SET","_GROUPBY","_HAVING",
"_ORDERBY","_IN","_NOT","COMMA","_EQ","_NEQ","_GT","_LT","_GE","_LE","_MAX",
"_MIN","_SUM","_COUNT","_AVG","_ANY","_ALL","_ASC","_ID","_STRING","_AND","_OR",
"_PLUS","_MINUS","_MUL","_DIV","UNARYMINUS","_NUMBER",
};
char *yyrule[] = {
"$accept : input",
"input :",
"input : input line",
"line : _END",
"$$1 :",
"line : statement $$1 _END",
"statement : query",
"statement : _CREATE kcreate",
"statement : _INSERT kinsert",
"statement : _DELETE _FROM ktablename _WHERE cmpr",
"statement : _UPDATE ktablename _SET kcolumnname _EQ kvalue _WHERE cmpr",
"statement : _TABS",
"statement : _DESC ktablename",
"statement : _QUIT",
"statement : error",
"query : subquery",
"$$2 :",
"$$3 :",
"$$4 :",
"subquery : _SELECT $$2 optprojexps _FROM selecttabs optwher $$3 optgroupby opthaving $$4 optorderby",
"optprojexps : projexps",
"optprojexps : _MUL",
"projexps : projexps projexp",
"projexps : projexp",
"$$5 :",
"projexp : $$5 pexpression",
"pexpression : pexpression _PLUS ptimes",
"pexpression : pexpression _MINUS ptimes",
"pexpression : ptimes",
"ptimes : ptimes _MUL pneg",
"ptimes : ptimes _DIV pneg",
"ptimes : pneg",
"pneg : pterm",
"pneg : _MINUS pterm",
"pterm : projcol",
"pterm : projaggcol",
"pterm : pnumber",
"pterm : pstring",
"projcol : ptable DOT pfield",
"projaggcol : afun LB ptable DOT pfield RB",
"afun : _MAX",
"afun : _MIN",
"afun : _COUNT",
"afun : _SUM",
"afun : _AVG",
"ptable : _ID",
"pfield : _ID",
"pnumber : _NUMBER",
"pstring : _STRING",
"selecttabs : tablenames",
"tablenames : tablenames tablename",
"tablenames : tablename",
"tablename : _ID",
"optwher :",
"optwher : _WHERE boolean",
"boolean : and",
"boolean : and _OR boolean",
"and : not",
"and : not _AND and",
"not : cmpr",
"not : _NOT cmpr",
"cmpr : expression relop expression",
"$$6 :",
"$$7 :",
"cmpr : expression relop anyallnt LB $$6 subquery $$7 RB",
"$$8 :",
"$$9 :",
"cmpr : expression _IN LB $$8 subquery $$9 RB",
"$$10 :",
"$$11 :",
"cmpr : expression _NOT _IN LB $$10 subquery $$11 RB",
"cmpr : LB boolean RB",
"expression : expression _PLUS times",
"expression : expression _MINUS times",
"expression : times",
"times : times _MUL neg",
"times : times _DIV neg",
"times : neg",
"neg : term",
"neg : _MINUS term",
"term : wtablename DOT columnname",
"term : simpleterm",
"term : LB expression RB",
"simpleterm : _STRING",
"simpleterm : _NUMBER",
"wtablename : _ID",
"columnname : _ID",
"relop : _EQ",
"relop : _NEQ",
"relop : _GT",
"relop : _GE",
"relop : _LT",
"relop : _LE",
"anyallnt : _ANY",
"anyallnt : _ALL",
"optgroupby :",
"optgroupby : groupby",
"groupby : _GROUPBY gtable DOT gfield",
"opthaving :",
"opthaving : _HAVING gcmpr",
"gboolean : gand",
"gboolean : gand _OR gboolean",
"gand : gnot",
"gand : gnot _AND gand",
"gnot : gcmpr",
"gnot : _NOT gcmpr",
"gcmpr : gexpression relop gexpression",
"gcmpr : LB gboolean RB",
"gexpression : gexpression _PLUS gtimes",
"gexpression : gexpression _MINUS gtimes",
"gexpression : gtimes",
"gtimes : gtimes _MUL gneg",
"gtimes : gtimes _DIV gneg",
"gtimes : gneg",
"gneg : gterm",
"gneg : _MINUS gterm",
"gterm : gtable DOT gfield",
"gterm : afun LB gtable DOT gfield RB",
"gterm : simpleterm",
"gtable : _ID",
"gfield : _ID",
"optorderby :",
"$$12 :",
"optorderby : _ORDERBY wtablename DOT columnname $$12 ascdescnt",
"$$13 :",
"optorderby : _ORDERBY afun LB tablename DOT columnname RB $$13 ascdescnt",
"ascdescnt :",
"ascdescnt : _ASC",
"ascdescnt : _DESC",
"$$14 :",
"kcreate : _TABLE ktablename $$14 LB kcreatecols RB",
"ktablename : _ID",
"kcreatecols : kcreatecol kcreatecols",
"kcreatecols : kcreatecol",
"$$15 :",
"kcreatecol : kcolumnname kdatatype $$15 kconstraint",
"kconstraints : kconstraints DOT kconstraint",
"kconstraints : kconstraint",
"kconstraint :",
"kconstraint : _NOTNULL",
"kconstraint : _UNIQUE",
"kconstraint : _PRIMARYKEY",
"$$16 :",
"kconstraint : _CHECK $$16 kcheckconstraint",
"$$17 :",
"kconstraint : _REFERENCES $$17 kreference",
"kcheckconstraint : kcolumnname krelop kck_value",
"krelop : _EQ",
"krelop : _NEQ",
"krelop : _GT",
"krelop : _LT",
"krelop : _GE",
"krelop : _LE",
"kreference : ktablename DOT kcolumnname",
"kdatatype : NUMBERDECL",
"kdatatype : VARCHARDECL",
"kcolumnname : _ID",
"kck_value : kexpression",
"$$18 :",
"kinsert : _INTO ktablename $$18 kinsertvals",
"kinsertvals : _VALUES LB kvaluelist RB",
"kvaluelist : kvalue kvaluelist",
"kvaluelist : kvalue",
"kvalue : kexpression",
"kvalue : _NULL",
"kexpression : kexpression _PLUS ktimes",
"kexpression : kexpression _MINUS ktimes",
"kexpression : ktimes",
"ktimes : ktimes _MUL kneg",
"ktimes : ktimes _DIV kneg",
"ktimes : kneg",
"kneg : kterm",
"kneg : _MINUS kterm",
"kterm : LB kexpression RB",
"kterm : ksimpleterm",
"ksimpleterm : _STRING",
"ksimpleterm : _NUMBER",
};
#endif
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 300 "parser.y"
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







#line 622 "y.tab.c"
#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse()
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    yyerror("syntax error");
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 4:
#line 71 "parser.y"
{ printf("SQL>");}
break;
case 9:
#line 76 "parser.y"
{ sm[sq]->del(yyvsp[-2].str); }
break;
case 10:
#line 77 "parser.y"
{ sm[sq]->update(yyvsp[-6].str,yyvsp[-4].str,*yyvsp[-2].data); }
break;
case 11:
#line 78 "parser.y"
{ sm[sq]->disptabs(); }
break;
case 12:
#line 79 "parser.y"
{ tabs.describe(yyvsp[0].str); }
break;
case 13:
#line 80 "parser.y"
{ return 0;}
break;
case 14:
#line 81 "parser.y"
{printf("sql parse error");}
break;
case 15:
#line 84 "parser.y"
{  sm[sq]->expdisplay();  }
break;
case 16:
#line 86 "parser.y"
{ sm[sq]-> selectbegin(); }
break;
case 17:
#line 89 "parser.y"
{ sm[sq]-> setwhere(yyvsp[0].col);}
break;
case 18:
#line 91 "parser.y"
{ sm[sq]-> sethaving(yyvsp[0].col); }
break;
case 19:
#line 93 "parser.y"
{ 
			  
			  /*sm[sq]-> expdisplay(); */
			  yyval.col=sm[sq]-> firstcolumn();
		
		  }
break;
case 20:
#line 111 "parser.y"
{ sm[sq]-> selectstar=false; }
break;
case 21:
#line 112 "parser.y"
{ sm[sq]-> selectstar=true; }
break;
case 24:
#line 114 "parser.y"
{ sm[sq]-> expbegin();}
break;
case 25:
#line 114 "parser.y"
{  sm[sq]-> expend();  }
break;
case 26:
#line 115 "parser.y"
{ sm[sq]-> addnode(ADD); }
break;
case 27:
#line 116 "parser.y"
{ sm[sq]-> addnode(SUB); }
break;
case 29:
#line 119 "parser.y"
{ sm[sq]-> addnode(MUL); }
break;
case 30:
#line 120 "parser.y"
{ sm[sq]-> addnode(DIV); }
break;
case 33:
#line 122 "parser.y"
{ sm[sq]-> addnode(NEG); }
break;
case 38:
#line 128 "parser.y"
{ sm[sq]-> addnode(yyvsp[-2].str,yyvsp[0].str);}
break;
case 39:
#line 129 "parser.y"
{ sm[sq]-> addnode(yyvsp[-5].aggfun,yyvsp[-3].str,yyvsp[-1].str); }
break;
case 47:
#line 134 "parser.y"
{ sm[sq]-> addnode(yyvsp[0].val); }
break;
case 48:
#line 135 "parser.y"
{ sm[sq]-> addnode(yyvsp[0].str); }
break;
case 49:
#line 142 "parser.y"
{ sm[sq]-> join();  if(sm[sq]-> selectstar) sm[sq]-> addallnodes(); }
break;
case 52:
#line 144 "parser.y"
{ sm[sq]-> selecttable(yyvsp[0].str); }
break;
case 53:
#line 153 "parser.y"
{ yyval.col=sm[sq]-> alltrue();}
break;
case 54:
#line 154 "parser.y"
{ yyval.col=yyvsp[0].col; }
break;
case 55:
#line 157 "parser.y"
{yyval.col=yyvsp[0].col;}
break;
case 56:
#line 157 "parser.y"
{yyval.col=sm[sq]-> binop(yyvsp[-2].col,yyvsp[0].col,OR); }
break;
case 57:
#line 158 "parser.y"
{yyval.col=yyvsp[0].col;}
break;
case 58:
#line 158 "parser.y"
{ yyval.col=sm[sq]-> binop(yyvsp[-2].col,yyvsp[0].col,AND); }
break;
case 59:
#line 159 "parser.y"
{ yyval.col=yyvsp[0].col; }
break;
case 60:
#line 159 "parser.y"
{yyval.col=sm[sq]-> unop(yyvsp[0].col,NOT); }
break;
case 61:
#line 160 "parser.y"
{ yyval.col=sm[sq]-> cmp(yyvsp[-2].col,yyvsp[0].col,yyvsp[-1].comtype);  }
break;
case 62:
#line 161 "parser.y"
{sq++;}
break;
case 63:
#line 161 "parser.y"
{ sq--;}
break;
case 64:
#line 162 "parser.y"
{ yyval.col=sm[sq]->subquery(yyvsp[-7].col,yyvsp[-2].col,yyvsp[-6].comtype,yyvsp[-5].anyall);  }
break;
case 65:
#line 163 "parser.y"
{sq++;}
break;
case 66:
#line 163 "parser.y"
{ sq--;}
break;
case 67:
#line 164 "parser.y"
{ yyval.col=sm[sq]->subquery(yyvsp[-6].col,yyvsp[-1].col,EQ,ANY);  }
break;
case 68:
#line 166 "parser.y"
{sq++;}
break;
case 69:
#line 166 "parser.y"
{ sq--;}
break;
case 70:
#line 167 "parser.y"
{ yyval.col=sm[sq]->subquery(yyvsp[-7].col,yyvsp[-2].col,NEQ,ALL);  }
break;
case 71:
#line 169 "parser.y"
{ yyval.col=yyvsp[-1].col; }
break;
case 72:
#line 171 "parser.y"
{ yyval.col=sm[sq]-> binop(yyvsp[-2].col,yyvsp[0].col,ADD); }
break;
case 73:
#line 172 "parser.y"
{ yyval.col=sm[sq]-> binop(yyvsp[-2].col,yyvsp[0].col,SUB); }
break;
case 74:
#line 173 "parser.y"
{ yyval.col=yyvsp[0].col; }
break;
case 75:
#line 174 "parser.y"
{ yyval.col=sm[sq]-> binop(yyvsp[-2].col,yyvsp[0].col,MUL); }
break;
case 76:
#line 175 "parser.y"
{ yyval.col=sm[sq]-> binop(yyvsp[-2].col,yyvsp[0].col,DIV); }
break;
case 77:
#line 176 "parser.y"
{ yyval.col=yyvsp[0].col;}
break;
case 78:
#line 177 "parser.y"
{ yyval.col=yyvsp[0].col;}
break;
case 79:
#line 177 "parser.y"
{ yyval.col=sm[sq]-> unop(yyvsp[0].col,NEG); }
break;
case 80:
#line 179 "parser.y"
{  yyval.col=sm[sq]-> getfield(yyvsp[-2].str,yyvsp[0].str);}
break;
case 82:
#line 181 "parser.y"
{ yyval.col=yyvsp[-1].col; }
break;
case 83:
#line 182 "parser.y"
{ yyval.col=sm[sq]-> getfield(yyvsp[0].str); }
break;
case 84:
#line 183 "parser.y"
{ yyval.col=sm[sq]-> getfield(yyvsp[0].val); }
break;
case 85:
#line 184 "parser.y"
{ yyval.str=yyvsp[0].str; }
break;
case 86:
#line 185 "parser.y"
{ yyval.str=yyvsp[0].str; }
break;
case 95:
#line 195 "parser.y"
{ sm[sq]-> setgroupby(false);  }
break;
case 97:
#line 197 "parser.y"
{ sm[sq]-> groupby(yyvsp[-2].str,yyvsp[0].str);  }
break;
case 98:
#line 198 "parser.y"
{ yyval.col=sm[sq]-> allhavingtrue(); }
break;
case 99:
#line 199 "parser.y"
{ yyval.col=yyvsp[0].col;}
break;
case 100:
#line 203 "parser.y"
{yyval.col=yyvsp[0].col;}
break;
case 101:
#line 203 "parser.y"
{yyval.col=sm[sq]-> groupbinop(yyvsp[-2].col,yyvsp[0].col,OR); }
break;
case 102:
#line 204 "parser.y"
{yyval.col=yyvsp[0].col;}
break;
case 103:
#line 204 "parser.y"
{ yyval.col=sm[sq]-> groupbinop(yyvsp[-2].col,yyvsp[0].col,AND); }
break;
case 104:
#line 205 "parser.y"
{ yyval.col=yyvsp[0].col; }
break;
case 105:
#line 205 "parser.y"
{yyval.col=sm[sq]-> groupunop(yyvsp[0].col,NOT); }
break;
case 106:
#line 206 "parser.y"
{ yyval.col=sm[sq]-> groupcmp(yyvsp[-2].col,yyvsp[0].col,yyvsp[-1].comtype);  }
break;
case 107:
#line 207 "parser.y"
{ yyval.col=yyvsp[-1].col; }
break;
case 108:
#line 211 "parser.y"
{ yyval.col=sm[sq]-> groupbinop(yyvsp[-2].col,yyvsp[0].col,ADD); }
break;
case 109:
#line 212 "parser.y"
{ yyval.col=sm[sq]-> groupbinop(yyvsp[-2].col,yyvsp[0].col,SUB); }
break;
case 110:
#line 213 "parser.y"
{ yyval.col=yyvsp[0].col; }
break;
case 111:
#line 214 "parser.y"
{ yyval.col=sm[sq]-> groupbinop(yyvsp[-2].col,yyvsp[0].col,MUL); }
break;
case 112:
#line 215 "parser.y"
{ yyval.col=sm[sq]-> groupbinop(yyvsp[-2].col,yyvsp[0].col,DIV); }
break;
case 113:
#line 216 "parser.y"
{ yyval.col=yyvsp[0].col; }
break;
case 114:
#line 217 "parser.y"
{ yyval.col=yyvsp[0].col; }
break;
case 115:
#line 218 "parser.y"
{ yyval.col=sm[sq]-> groupunop(yyvsp[0].col,NEG); }
break;
case 116:
#line 220 "parser.y"
{ yyval.col=sm[sq]-> getgroupfield(yyvsp[-2].str,yyvsp[0].str);  }
break;
case 117:
#line 221 "parser.y"
{ yyval.col=sm[sq]-> getgroupfield(yyvsp[-5].aggfun,yyvsp[-3].str,yyvsp[-1].str);  }
break;
case 122:
#line 228 "parser.y"
{ 
			if( sm[sq]->isgroupby()==false)  sm[sq]->orderby(yyvsp[-2].str,yyvsp[0].str); 
			else  sm[sq]->grouporderby(yyvsp[-2].str,yyvsp[0].str);
		  }
break;
case 124:
#line 233 "parser.y"
{
			 sm[sq]->grouporderby(yyvsp[-5].aggfun,yyvsp[-3].str,yyvsp[-1].str);
		 }
break;
case 126:
#line 236 "parser.y"
{ sm[sq]->orderbyasc(ASC); }
break;
case 127:
#line 237 "parser.y"
{ sm[sq]->orderbyasc(ASC);}
break;
case 128:
#line 238 "parser.y"
{ sm[sq]->orderbyasc(DESC);  }
break;
case 129:
#line 243 "parser.y"
{ cm.createtable(yyvsp[0].str); }
break;
case 130:
#line 243 "parser.y"
{ cm.createend(); }
break;
case 134:
#line 246 "parser.y"
{ cm.createfield(yyvsp[-1].str,yyvsp[0].str);}
break;
case 135:
#line 246 "parser.y"
{ cm.createdfield();}
break;
case 139:
#line 249 "parser.y"
{ cm.createfcons(NOTNULL); }
break;
case 140:
#line 250 "parser.y"
{ cm.createfcons(UNIQ); }
break;
case 141:
#line 251 "parser.y"
{ cm.createfcons(PRKEY); }
break;
case 142:
#line 252 "parser.y"
{ cm.createfcons(CHECK); }
break;
case 144:
#line 253 "parser.y"
{ cm.createfcons(FRKEY);}
break;
case 146:
#line 254 "parser.y"
{ cm.createfcheck(yyvsp[-1].comtype,*yyvsp[0].data);  }
break;
case 153:
#line 256 "parser.y"
{ cm.createfref(yyvsp[-2].str,yyvsp[0].str); }
break;
case 157:
#line 260 "parser.y"
{ yyval.data=new DATUM; yyval.data->cp(yyvsp[0].data); }
break;
case 158:
#line 264 "parser.y"
{ im.inserttable(yyvsp[0].str); }
break;
case 159:
#line 264 "parser.y"
{ im.insertend(); }
break;
case 163:
#line 267 "parser.y"
{ im.insertfield(*yyvsp[0].data); }
break;
case 164:
#line 268 "parser.y"
{ im.insertfield(); }
break;
case 165:
#line 270 "parser.y"
{ yyval.data=yyvsp[-2].data->binop(*yyvsp[0].data,ADD);  }
break;
case 166:
#line 271 "parser.y"
{ yyval.data=yyvsp[-2].data->binop(*yyvsp[0].data,SUB); }
break;
case 167:
#line 272 "parser.y"
{ yyval.data=yyvsp[0].data; }
break;
case 168:
#line 273 "parser.y"
{ yyval.data=yyvsp[-2].data->binop(*yyvsp[0].data,MUL);; }
break;
case 169:
#line 274 "parser.y"
{ yyval.data=yyvsp[-2].data->binop(*yyvsp[0].data,DIV);  }
break;
case 170:
#line 275 "parser.y"
{ yyval.data=yyvsp[0].data; }
break;
case 171:
#line 276 "parser.y"
{ yyval.data=yyvsp[0].data; }
break;
case 172:
#line 277 "parser.y"
{yyval.data=yyvsp[0].data->unop(NEG);  }
break;
case 173:
#line 278 "parser.y"
{yyval.data=yyvsp[-1].data;}
break;
case 174:
#line 279 "parser.y"
{ yyval.data=yyvsp[0].data;  }
break;
case 175:
#line 281 "parser.y"
{ yyval.data=getdatum(yyvsp[0].str); }
break;
case 176:
#line 282 "parser.y"
{ yyval.data=getdatum(yyvsp[0].val); }
break;
#line 1233 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
