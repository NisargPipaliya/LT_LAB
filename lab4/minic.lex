identifier[_ A-Z a-z][_ A-Z a-z 0-9]+
float[0-9]+"."[0-9]+
int[0-9]+
signint[+ -]?[1-9]+[0-9]*
keywords "if"|"else"|"for"|"while"|"do"|"int"|"float"|"double"|"null"|"true"|"false"|"string"|"char"|"bool"|"return"|"main"|"void"|"class"|"struct"|"union"|"enum"

comment "//"[A-Z a-z 0-9]*
multiline_c "/*""*"?[^"*/"]*"*"*"/"*[^"*/"]*"*/"

%%
{multiline_c}+   {printf("\nMultiLine %s",yytext);}
{comment}       {printf("\nComment %s",yytext);}
{keywords}  {printf("\nKeyword %s",yytext);}
{int}         { printf("\nInt %s",yytext);}
{float}         { printf("\nFloat %s",yytext);}
{signint}         { printf("\nsignint %s",yytext);}
{identifier}    { printf("\nIdentifier %s",yytext);}
.               {printf("\nUnidentified %s",yytext);}
%%
int yywrap(){
return 1;
}

int main(){
yylex();
return 0;
}
