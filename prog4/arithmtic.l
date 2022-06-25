%{
 #include<stdio.h>
int c=0;
FILE *fp;

%}

id [a-zA-Z][a-zA-Z0-9]*
ar [/*+-]
num [0-9]+

%%
\n {c++;}
{id}"="({id}|{num})({ar}({id}|{num}))+ {printf("\nValid arithmetic operation in line %d ",c+1);ECHO;}
{id}"="({id}|{num}){ar} {printf("\nInvalid operation ! No right operand for the arithmetic operation %d ",c+1);ECHO;}
{id}"="{ar}({id}|{num}) {printf("\nInvalid operation ! No Left operand for the arithmetic operation %d ",c+1);ECHO;}
%%
void main()
{
 yyin =fopen("arith.c","r");
 yylex();
fclose(yyin);
}
