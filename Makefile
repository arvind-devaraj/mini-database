yacc -d parser.y
lex parser.l
g++ -c *.cpp
g++ lex.yy.c y.tab.c create.o insert.o select_op.o  join.o selectcolumn.o project.o col_op.o datum.o tabs.o column.o  expr.o  store.o createandinsert.o -ll
