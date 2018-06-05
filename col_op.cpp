#include "defs2.h"

COLUMN* colcmp(COLUMN* s,COLUMN* t,COMTYPE c,int prod)
{
	COLUMN* result=new COLUMN;
	result->createfield("#",BOOL);
	
	if( s->totalrecords()==1 && t->totalrecords() > 1)  
	{
		 DATUM s1; s1.cp( s->selectfield(0) ) ;
		for(int i=0;i<prod;i++) {
			DATUM t1;
			t1.cp( t->selectfield(i));
			result->insertfield(s1.cmp(t1,c));
		}
	}
	if( s->totalrecords()> 1 && t->totalrecords()==1) 
	{
		DATUM t1;
		t1.cp( t->selectfield(0));
		for(int i=0;i<prod;i++) {
			DATUM s1;
			s1.cp( s->selectfield(i));
			result->insertfield(s1.cmp(t1,c));
		}
	}
	if( s->totalrecords()==1 && t->totalrecords()==1)
	{
		DATUM s1,t1;
		s1.cp( s->selectfield(0));
		t1.cp( t->selectfield(0));
		result->insertfield( s1.cmp(t1,c));
	}
	if( s->totalrecords()>1 && t->totalrecords() >1 )
	{	
		for(int i=0;i<prod;i++) {
			DATUM s1,t1;
			s1.cp( s->selectfield(i));
			t1.cp( t->selectfield(i));
			result->insertfield(s1.cmp(t1,c));
		}
	}
	return result;
}


COLUMN* colbinop(COLUMN* s,COLUMN* t,OPTYPE op,int prod)
{
	
	COLUMN* result=new COLUMN;
	if( s->getfieldtype()!=t->getfieldtype()) {printf("typemismatch12"); return result;}
	result->createfield("#",s->getfieldtype());
	
	if( s->totalrecords()==1 && t->totalrecords() > 1)  
	{
		
		
		for(int i=0;i<prod;i++) {
			DATUM t1;
			DATUM s1;	
			s1.cp( s->selectfield(0) ) ;
			t1.cp( t->selectfield(i));
			s1.binop(t1,op);
			result->insertfield(s1); 
			
		}
	}
	if( s->totalrecords()> 1 && t->totalrecords()==1) 
	{
		for(int i=0;i<prod;i++) {
			DATUM s1;
			DATUM t1;
			t1.cp( t->selectfield(0));
			s1.cp( s->selectfield(i));
			s1.binop(t1,op);
			result->insertfield(s1);
		}
	}
	if( s->totalrecords()==1 && t->totalrecords()==1)
	{
		DATUM s1,t1;
		s1.cp( s->selectfield(0));
		t1.cp( t->selectfield(0));
		s1.binop(t1,op);
		result->insertfield( s1);
	}
	if( s->totalrecords()>1 && t->totalrecords() >1 )
	{	
		for(int i=0;i<prod;i++) {
			DATUM s1,t1;
			s1.cp( s->selectfield(i));
			t1.cp( t->selectfield(i));
			s1.binop(t1,op);
			result->insertfield(s1);
		}
	}
	return result;
}


COLUMN* colunop(COLUMN* s,OPTYPE op,int prod)
{
	
	COLUMN* result=new COLUMN;
	result->createfield("#",s->getfieldtype());
	
	if( s->totalrecords()==1 )  
	{
		DATUM s1;
		s1.cp( s->selectfield(0) ) ;
			s1.unop(op);
			result->insertfield(s1);
		
	}
	if( s->totalrecords()> 1 ) 
	{
		for(int i=0;i<prod;i++) {
			DATUM s1;
			s1.cp( s->selectfield(i));
			s1.unop(op);
			result->insertfield(s1);
		}
	}
	return result;
}






