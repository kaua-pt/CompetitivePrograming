%{
    // locais dos includes
    #include <iostream>
%}

// regras do lex e macros
DIGITO [0-9]
INTEIRO {DIGITO}+
FLUTUANTE {INTEIRO}[.]{INTEIRO}
%%

[0-9]+ {cout<<"Encontrei um inteiro\n"}; // sempre que encontrar um inteiro de 1 a mais dig
{FLUTUANTE} {cout<<"Encontrei um float\n"}
[[:space:]]+; // se encontrar um a mais espaço ignora, sem ação semantica
[[:^space:]]+; // nao faz nada,ambiguidade

%%
// código C++
int main(){
    cout << "Hi compiler\n";
    yylex();
    return 0;
}