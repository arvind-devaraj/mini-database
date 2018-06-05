#include "col.h"
#include "defs2.h"

#include <fstream>
#include <stdio.h>

ostream& operator<<(ostream& o,COMTYPE t) {  o<<int(t); return o;}
ostream& operator<<(ostream& o,TYPE t) {  o<<int(t); return o;}
istream& operator>>(istream& i,COMTYPE& t) { int temp;i>>temp;t=(COMTYPE)temp; return i;}
istream& operator>>(istream& i,TYPE& t) { int temp;i>>temp;t=(TYPE)temp; return i; }
void COLUMN::writefile(ofstream& out)
{
	
	char buff[40];
	
	out<<totalrc<<'\n'
	
	<<name<<'\n'<<fr_tname<<'\n'<<fr_fname<<'\n'<<ck_cmp<<'\n'
	<< ck_data.getdval()<<'\n'<<ck_data.getcval()<<'\n'<<type<<'\n'
	<<notnull<<'\n'<<check<<'\n'<<uniq<<'\n'<<prkey<<'\n'<<frkey<<'\n';
	
	
	if( type==VARCHAR) {
		for(int i=0;i<totalrc;i++) {
			out<<field[i].getcval()<<'\n';
		}
	}
	if( type==NUMBER ) {
		for(int i=0;i<totalrc;i++) {
			out<<field[i].getdval()<<'\n';
		}
	}
	
	
	
}
void COLUMN::readfile(ifstream& in)
{	
	
	char string[40]="";
	 double number=0;
	in>>totalrc>>name
	>>fr_tname>>fr_fname >>ck_cmp >>number>>string
	>>type>>notnull>>check>>uniq>>prkey>>frkey; 
		    
		 ;
	
	ck_data.cp(string);
	ck_data.cp(number);
	
	
	
	if( type==NUMBER ) {
		for(int i=0;i<totalrc;i++) {
			in>>number;
			field[i].cp(number);
		}
	}
	if( type==VARCHAR ) {
		for(int i=0;i<totalrc;i++) {
			in>>string;
			field[i].cp(string);
		}
	}
	
	
	
	
}

void TABLE::writefile(ofstream& out)  {
	out<<totalcol<<'\n';
	out<<tabname<<'\n';
	for(int i=0;i<totalcol;i++) {
		column[i].writefile(out);
	}
}

void TABLE::readfile(ifstream&in) {
	in>>totalcol;
	in>>tabname;
	
	for(int i=0;i<totalcol;i++) {
		column[i].readfile(in);
	}
}
	
void TABS::writefile(ofstream & out) {
	out<<totaltabs<<'\n';
	for(int i=0;i<totaltabs;i++) {
		table[i].writefile(out);
	}
}
void TABS::readfile(ifstream& in) {
	
	in>>totaltabs;
	
	for(int i=0;i<totaltabs;i++) {
		table[i].readfile(in);
	}
}

/*
 TABS tabs,tabs2;
 CREATE cm;
void createandinsert();
int main() {
	createandinsert();
	tabs.displayall();
	ofstream f("OBJ.DAT");
	tabs.writefile(f);
	f.close();
	ifstream in("OBJ.DAT");
	tabs2.readfile(in);
	printf("....");
	tabs2.displayall();
	return 0;
}

  
*/

