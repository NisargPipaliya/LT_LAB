letter[A-Z a-z]
digit[0-9]
signint[- +]?[1-9][0-9]*

%%
{letter}+ printf("\nLetter is %s",yytext);
{digit}+ printf("\nDigit Recognized, %d",yytext);
{signint} printf("\nsign int ");

.   printf("\n Unrecognized");
%%

int yywrap(void){
return 1;
}

int main(void){
yylex();
return 0;
}

