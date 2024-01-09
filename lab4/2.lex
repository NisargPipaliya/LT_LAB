letter[A-Z a-z]
digit[0-9]
keywords{"if" |"else" |"for" |"while" |"do" |"int" |"float" |"double" |"null" |"true" |"false" |"string" |"char" |"bool" |"return" |"main" |"void" |"class" |"struct" |"union" |"enum" }

%%
[keywords] { printf("\nkeyword %s",yytext);}
%%
int yywrap(){
return 1;
}

int main(){
yylex();
return 0;
}
