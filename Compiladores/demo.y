%{
#include <stdio.h>

void yyerror(char *c);
int yylex(void);
%}

%token N OP EOL

%%
S:
    S E EOL {} 
    | ;

E:
    N {}
    | E OP E{}
    ;


%%
void yyerror(char *c){
    printf("Error: %s\n", c);
}

int main(){
    yyparse();
    return 0;
}