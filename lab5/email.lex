commercial[A-Z a-Z 0-9]+"@"+[A-Z]+".com"
academic[A-Z a-Z 0-9]+"@"+"ac"+".in"
organization[A-Z a-Z 0-9]+"@"+[A-Z]+".org"
email[A-Z a-z 0-9]
%%
{commercial}  printf("\ncommercial email %s",yytext);
{academic}  printf("\nacademic email %s",yytext);
{organization}  printf("\norganizational email %s",yytext);

%%

int yywrap()
{
    return 1;
}

int main(){
    yylex();
    return 0;
}