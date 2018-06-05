#ifndef __COL_H
#define __COL_H

#include "datum.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class COLUMN
{
vector<DATUM> field;

int totalrc;
char name[40];
char fr_tname[40];
char fr_fname[40];
COMTYPE ck_cmp;
DATUM ck_data;
TYPE type;


public:
bool notnull,check,uniq,prkey,frkey;
COLUMN() ;
void reserve();
void copy();
void copy(COLUMN* ptr);
void copy(COLUMN& ref);
void createfield(char*s,TYPE t) ;
void createfcons(CONSTRAINT);
void createfcheck(COMTYPE eq,DATUM d);
void createfref(char* tname,char* fname);
char* getfieldname() ;
TYPE getfieldtype();
bool validate(DATUM d);
void  insertfield(DATUM d)  ;
void insertfield(bool b);
int totalrecords();
DATUM& selectfield(int recno);
void deleterecord(int i);
void display() ;
void display(int);
void displayx(COLUMN*);
void writefile(ofstream&);
void readfile(ifstream&);
};

COLUMN* colcmp(COLUMN*,COLUMN*,COMTYPE,int prod);
COLUMN* colbinop(COLUMN*,COLUMN*,OPTYPE,int prod);
COLUMN* colunop(COLUMN*,OPTYPE,int prod);


using namespace std;
class TABLE
{
vector<COLUMN> column;
bool Deleted[50];
char tabname[20];
int totalcol;
public:
TABLE();
void reserve() ;
//create operations
void createfield(int colno,char *name,TYPE type) ;
void createfcons(int colno,CONSTRAINT);
void createfcheck(int colno,COMTYPE eq,DATUM d);
void createfref(int colno,char* tname,char* fname);
char* getfieldname(int colno);
TYPE getfieldtype(int colno);
void settabname(char *s) ;
char* gettabname()  ;
int getfieldno(char*s);
void settotalcolumns(int totcol) ;
int gettotalcolumns();
//insert operations
bool validate(int colno,DATUM data);
void insertfield(int colno,DATUM data);


int totalrecords(int colno);
//select operations
DATUM& selectfield(int colno,int recno);
COLUMN& selectcol(int colno) ;
// other operations
void disprow(int row);
void display();
void describe();
void writefile(ofstream&);
void readfile(ifstream&);
void deleterecord(int);
bool isdeleted(int);
};


class TABS
{
vector<TABLE> table;
int totaltabs;
public:
TABS();
void reserve();
//create
void createfield(int tno,int colno,char*name,TYPE type);
void createfcons(int tno,int colno,CONSTRAINT);
void createfcheck(int tno,int colno,COMTYPE eq,DATUM d);
void createfref(int tno,int colno,char*tname,char*fname);
char* getfieldname(int tno,int colno) ;
TYPE getfieldtype(int tno,int colno);
void settabname(int tno,char* s) ;
char* gettabname(int tno);
int gettabno(char*s);
int getfieldno(int tno,char*s);
void settotalcolumns(int tno,int tot) ;
int gettotalcolumns(int tno) ;
int gettotaltabs();
void settotaltabs(int);
	
//insert
bool validate(int tno,int colno,DATUM data);
void insertfield(int tno,int colno,DATUM data);
int totalrecords(int tno,int colno);
int totalrecords(int tno);

//select
DATUM& selectfield(int tno,int colno,int recno) ;
TABLE& selecttable(int tno) ;
//others
void disprow(int tno,int row);
void display(int tno);
void display(int tno,int row,int fld);
void displayall();
void describe(char*s);
void writefile(ofstream&);
void readfile(ifstream&);
void deleterecord(int,int);
bool isdeleted(int,int);
};

#endif
