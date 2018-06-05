#include "defs2.h"
#include "datum.h"
#include "col.h"


/*******************************************************************************************/

 /******************************************************************************************/
TABLE::TABLE() { reserve();  for(int i=0;i<50;i++) Deleted[i]=false; }
void TABLE::reserve() {column.reserve(10); for(int i=0;i<10;i++) column[i].reserve(); }
//create operations
void TABLE::createfield(int colno,char *name,TYPE type) { column[colno].createfield(name,type);  }
void TABLE::createfcons(int colno,CONSTRAINT c) { column[colno].createfcons(c);}
void TABLE::createfcheck(int colno,COMTYPE eq,DATUM d) {  column[colno].createfcheck(eq,d);}
void TABLE::createfref(int colno,char* tname,char* fname) { column[colno].createfref(tname,fname);}
char* TABLE::getfieldname(int colno) { return column[colno].getfieldname(); }
TYPE TABLE::getfieldtype(int colno) {return column[colno].getfieldtype();}
void TABLE::settabname(char *s) { strcpy(tabname,s);}
char* TABLE::gettabname()  { return tabname;} 
void TABLE::settotalcolumns(int totcol) { totalcol=totcol;}
int TABLE::gettotalcolumns()	{ return totalcol;}
int TABLE::getfieldno(char* s) 
	{
		for(int i=0;i< totalcol; i++) {
		if( strcmp(s,column[i].getfieldname())==0 ) return i;
		}
		return -1;
	}
//insert operations
bool TABLE::validate(int colno,DATUM data) { return column[colno].validate(data); }
void TABLE::insertfield(int colno,DATUM data) {  column[colno].insertfield(data); }
int TABLE::totalrecords(int colno) { return column[colno].totalrecords(); }

//select operations
DATUM& TABLE::selectfield(int colno,int recno) { return column[colno].selectfield(recno); }
COLUMN& TABLE::selectcol(int colno) {  return column[colno];  }
//other operations
//even if any one field of a row is deleted the entire row is considered deleted
void TABLE::disprow(int i) {
		bool deleted=false;
		for(int j=0;j<gettotalcolumns();j++) {
			if( column[j].selectfield(i).gettype()==DELETED )  deleted=true;
			if(!deleted) column[j].selectfield(i).display();
		}
		
}

void TABLE::display() {
	for(int i=0;i< totalrecords(0);i++) { //warn
		bool deleted=false;
		for(int j=0;j<gettotalcolumns();j++) {
			if( column[j].selectfield(i).gettype()==DELETED )  deleted=true;
			if(!deleted) column[j].selectfield(i).display();
		}
		if( !deleted )  printf("\n");
	}
}
void TABLE::describe() {
	for(int i=0;i< gettotalcolumns();i++)  {
		printf( "%s\t",column[i].getfieldname());
		printf("%s\t ",NAMETYPE( column[i].getfieldtype())) ;
		if( column[i].notnull==true) printf("NOTNULL");
		if( column[i].check==true) printf("CHECK");
		if( column[i].prkey==true) printf("PRKEY");
		if( column[i].uniq==true) printf("UNIQ");
		if( column[i].frkey==true) printf("FRKEY");
		printf("\n");
		
	}
}

void TABLE::deleterecord(int n) {
	for(int i=0;i< gettotalcolumns();i++ ) {
		column[i].deleterecord(n);
	}
}

	
/******************************************************************************************/

TABS::TABS() { reserve(); totaltabs=0;}
void TABS::reserve() { table.reserve(4); for(int i=0;i<4;i++) table[i].reserve(); }
//create
void TABS::createfield(int tno,int colno,char*name,TYPE type) {  table[tno].createfield(colno,name,type); }
void TABS::createfcons(int t,int colno,CONSTRAINT c) { table[t].createfcons(colno,c);}
void TABS::createfcheck(int t,int colno,COMTYPE eq,DATUM d) { table[t].createfcheck(colno,eq,d);}
void TABS::createfref(int t,int colno,char* tname,char* fname) { table[t].createfref(colno,tname,fname);}


char* TABS::getfieldname(int tno,int colno) { return table[tno].getfieldname(colno);}
TYPE TABS::getfieldtype(int tno,int colno) { return table[tno].getfieldtype(colno);}
void TABS::settabname(int tno,char* s) {  table[tno].settabname(s); }
char* TABS::gettabname(int tno) {return table[tno].gettabname(); }
// GET TABLE NUMBER
int  TABS::gettabno(char*s) {
	for(int i=0;i<totaltabs;i++) {
		if( strcmp(s, table[i].gettabname())==0) return i;
	}
	return -1;
}

int TABS::getfieldno(int tno,char *s) { return table[tno].getfieldno(s); }
void TABS::settotalcolumns(int tno,int tot) { table[tno].settotalcolumns(tot);}
int TABS::gettotalcolumns(int tno) { return table[tno].gettotalcolumns(); }
int TABS::gettotaltabs() { return totaltabs; }
void TABS::settotaltabs(int n) { totaltabs=n; }
	
//insert
bool TABS::validate(int tno,int colno,DATUM data) { return table[tno].validate(colno,data);}
void TABS::insertfield(int tno,int colno,DATUM data) {  table[tno].insertfield(colno,data);}
int TABS::totalrecords(int tno,int colno) { return table[tno].totalrecords(colno); }
int TABS::totalrecords(int tno) { return table[tno].totalrecords(0); }

//select
DATUM& TABS::selectfield(int tno,int colno,int recno) { return table[tno].selectfield(colno,recno); }
TABLE& TABS::selecttable(int tno) { return table[tno];}

// OTHER FUNS
void TABS::disprow(int tno,int row) { table[tno].disprow(row);}
void TABS::display(int tno) {
	table[tno].display();
}
void TABS::display(int tno,int row,int fno)
{
	table[tno].selectcol(fno).selectfield(row).display();
}

void TABS::displayall() {
	
	for(int i=0;i< gettotaltabs(); i++) 
	{
	printf("%s\n", gettabname(i)); 
	printf("\t");
	for(int j=0;j< gettotalcolumns(i);j++) printf("%s\t", getfieldname(i,j));
	printf("\n");
	display(i);
	}
}

void TABS::describe(char *tab) {
	int tno=gettabno(tab);
	table[tno].describe();
}

void TABS::deleterecord(int tno,int i) {
	table[tno].deleterecord(i);
}

