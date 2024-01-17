%{
#include<stdio.h>
void yyerror(char *);
#include "y.tab.h"
extern int yylval;
%}

%%
[0-9]+  {yylval = atoi(yytext);
            return INTEGER;}
[-+\n]  return *yytext;
[ \t]   ;
.       {yyerror("Invalid Token");}
%%

int yywrap(){
    return 1;
}