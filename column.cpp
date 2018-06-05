#include "col.h"

extern TABS tabs;
COLUMN::COLUMN() { 
	reserve();  
	
}
void COLUMN::reserve() { 

	field.reserve(50); 
	totalrc=0;
	strcpy(name,"$");
	strcpy(fr_tname,"$");
	strcpy(fr_fname,"$");
	ck_cmp=EQ;
	ck_data.cp(0.0);
	ck_data.cp("$");
	type=NUMBER;
	notnull=check=prkey=frkey=uniq=false; 

}
void COLUMN::copy(COLUMN& ref) {
	type=ref.type;
	totalrc=ref.totalrc;
	strcpy(name,ref.name);
	for(int i=0;i<totalrc;i++) { field[i].cp(ref.selectfield(i));} 
}
void COLUMN::copy() {
	type=UNDEF; totalrc=0; strcpy(name,"NULL_COLUMN");
}
void COLUMN::copy(COLUMN* ref) {
	type=ref->type;
	totalrc=ref->totalrc;
	strcpy(name,ref->name);
	for(int i=0;i<totalrc;i++) { field[i].cp(ref->selectfield(i));} 
}
	

void COLUMN::createfield(char*s,TYPE t) { strcpy(name,s); type=t; totalrc=0; }
void COLUMN::createfcons(CONSTRAINT c)  { 
		if(c==NOTNULL)  notnull=true;
		if(c==CHECK) check=true;
		if(c==PRKEY) prkey=true;
		if(c==FRKEY) frkey=true;
		if(c==UNIQ) uniq=true;
	}
void COLUMN::createfcheck(COMTYPE eq,DATUM d) {
		
		ck_cmp=eq;
		ck_data=d;
	
		
	}
void COLUMN::createfref(char* tname,char* fname) {
		strcpy(fr_tname,tname);
		strcpy(fr_fname,fname);

	}
char* COLUMN::getfieldname()  { return name;}
TYPE COLUMN::getfieldtype() { return type;}

bool COLUMN::validate(DATUM d)
{

	if(d.gettype()!=type && d.gettype()!=NULLTYPE) {printf("warn1");d.display();return false; }
	if(d.gettype()==NULLTYPE && notnull==true) { printf("notnull vio"); return false;}
	
	if( uniq==true) {
		
		for(int i=0;i<totalrc;i++) {
			if( field[i].gettype()==NULLTYPE) continue;
			if( field[i].cmp(d,EQ)==true) { printf("unique vio");return false;}
		}
	}
	if( prkey==true) {
		for(int i=0;i<totalrc;i++) {
			if( field[i].gettype()==NULLTYPE) {printf("nullvalinprkey");return false;}
			if( field[i].cmp(d,EQ)==true) { printf("dupvalinprkey");return false;}
		}
	}	
	
	if( check==true) {
		if( d.cmp(ck_data,ck_cmp)==false ) { printf("check vio");return false;}
		
	}
	if( frkey==true) {
		int tno=tabs.gettabno(fr_tname);
		int fno=tabs.getfieldno(tno,fr_fname);
		int found=false;
		for(int i=0;i< tabs.totalrecords(tno) ; i++ )
		{
			if( tabs.selectfield(tno,fno,i).cmp(d,EQ)==true ) found=true;
		}
		if( found==false) { printf("frkey vio");return false;}
	}
	
	return true;
}

void COLUMN::insertfield(DATUM d)  { 
	
	field[totalrc]=d; totalrc++;  

	}
void COLUMN::insertfield(bool b) {
	DATUM d1; d1.cp(b);
	insertfield(d1);
}
	
int COLUMN::totalrecords() { return totalrc; }
DATUM& COLUMN::selectfield(int recno) { return field[recno]; }
void COLUMN::display() {
	for(int i=0;i<totalrc;i++)  {

		field[i].display(); 
	}
	printf("\n");
}

//display i th record
void COLUMN::display(int i) {
	field[i].display();
}

void COLUMN::displayx(COLUMN* bval) {
	
	for(int i=0;i<totalrc;i++)  {
		if( bval->selectfield(i).getbval()==true) 
		field[i].display(); 

	}
	printf("\n");
	}

void COLUMN::deleterecord(int i) {
	DATUM temp ;
	temp.cp(field[ totalrecords()]) ;
	field[i].cp(temp);
	totalrc--;
}


	
