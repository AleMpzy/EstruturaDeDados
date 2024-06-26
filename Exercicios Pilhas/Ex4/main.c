#include <stdio.h>
#include "pilha.c"

int Parentizacao(char *expressao){
    Pilha p;
    TipoItem item;
    inicializar(&p);
    
    for(char *ptr = expressao; *ptr != '\0'; ptr++){
        if(*ptr == '('){
            item.chave = *ptr;
            push(item, &p);
        }else if (*ptr == ')'){
            if(itsVazia(p)){
                return 0;
            }
            pop(&p, &item);
        }
    }
    
    return itsVazia(p);
}

int main(){
    char ex1[] = "(())--(()())--()()";
    char ex2[] = ")(--(()(--))(((";
    
    if(Parentizacao(ex1)){
        printf("Expressao 1 esta correta!\n");
    } 
    else{
        printf("Expressao 1 esta incorreta!\n");
    }
    
    if(Parentizacao(ex2)){
        printf("Expressao 2 esta correta!\n");
    } 
    else{
        printf("Expressao 2 esta incorreta!\n");
    }
    return 0;
}