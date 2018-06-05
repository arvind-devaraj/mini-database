#include "defs2.h"

extern CREATE cm;
extern INSERT im;

void createandinsert()
{
DATUM d1;
cm.createtable("DEPT"); 
cm.createfield("DNO",NUMBER);   cm.createdfield();
cm.createfield("DNAME",VARCHAR); cm.createdfield();
cm.createfield("LOC",VARCHAR); cm.createdfield();
cm.createend();

cm.createtable("EMP");
cm.createfield("ENO",NUMBER); cm.createfcons(NOTNULL);cm.createdfield();
cm.createfield("ENAME",VARCHAR); cm.createdfield();
cm.createfield("JOB",VARCHAR); cm.createdfield();
cm.createfield("MGR",NUMBER); cm.createdfield();
cm.createfield("SAL",NUMBER); cm.createdfield();
cm.createfield("DNO",NUMBER);  cm.createdfield();
cm.createend();

INSERT im;
im.inserttable("DEPT"); 
im.insertfield(10);
im.insertfield("Accounting"); 
im.insertfield("NewYork");
im.insertend();

im.inserttable("DEPT");
im.insertfield(20);
im.insertfield("Research");
im.insertfield("Dallas");
im.insertend();

im.inserttable("DEPT");
im.insertfield(30);
im.insertfield("Sales");
im.insertfield("Chicago");
im.insertend();

im.inserttable("DEPT");
im.insertfield(40);
im.insertfield("Operations");
im.insertfield("Boston");
im.insertend();


im.inserttable("EMP");
im.insertfield(7369);
im.insertfield("SMITH");
im.insertfield("CLERK");
im.insertfield(7902);
im.insertfield(800);
im.insertfield(20);
im.insertend(); 



im.inserttable("EMP");
im.insertfield(7499);
im.insertfield("ALLEN");
im.insertfield("SALESMAN");
im.insertfield(7698);
im.insertfield(1600);
im.insertfield(30);
im.insertend(); 

im.inserttable("EMP");
im.insertfield(7521);
im.insertfield("WARD");
im.insertfield("SALESMAN");
im.insertfield(7698);
im.insertfield(1250);
im.insertfield(30);
im.insertend(); 

im.inserttable("EMP");
im.insertfield(7566);
im.insertfield("JONES");
im.insertfield("MANAGER");
im.insertfield(7839);
im.insertfield(2975);
im.insertfield(20);
im.insertend(); 

im.inserttable("EMP");
im.insertfield(7654);
im.insertfield("MARTIN");
im.insertfield("SALESMAN");
im.insertfield(7698);
im.insertfield(1250);
im.insertfield(30);
im.insertend(); 

im.inserttable("EMP");
im.insertfield(7698);
im.insertfield("BLAKE");
im.insertfield("MANAGER");
im.insertfield(7839);
im.insertfield(2850);
im.insertfield(30);
im.insertend(); 




}
