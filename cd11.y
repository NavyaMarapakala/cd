%{
/* Definition section */
#include<stdio.h>
int flag=0;
int yylex();
void yyerror();
%}

%token NUMBER

%left '+' '-'

%left '*' '/' '%'

%left '(' ')'

/* Rule Section */
%%

ArithmeticExpression: E{

		printf("\nResult=%d\n", $$);

		return 0;

		};
E:E'+'E {$$=$1+$3;}

|E'-'E {$$=$1-$3;}

|E'*'E {$$=$1*$3;}

|E'/'E {$$=$1/$3;}

|E'%'E {$$=$1%$3;}

|'('E')' {$$=$2;}

| NUMBER {$$=$1;}

;

%%

//driver code
void main()
{
printf("Enter Any Arithmetic Expression which can have operations Addition,Subtraction, Multiplication, Division,Modulus and Round brackets:\n");

