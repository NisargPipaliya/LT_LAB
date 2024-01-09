%%
username printf("Username is : %s", getpwnam('nisarg'));
%%

int yywrap(){
return 1;
}

int main(){
yylex();
return 0;
}
