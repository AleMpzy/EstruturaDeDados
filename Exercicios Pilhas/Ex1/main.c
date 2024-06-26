#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

void InverterPalavras(char *p){
    Pilha pilha;
    inicializar(&pilha);
    TipoItem item;
    char resultado[*p];
    int inventer = 0;

    printf("Antes da inversao:\n%s\n", p);

    for(int i = 0; p[i] != '\0'; i++){
        if(p[i] == ' '){
            while(!itsVazia(pilha)){
                pop(&pilha, &item);
                resultado[inventer++] = item.chave;
            }
            resultado[inventer++] = ' ';
        } 
        else{
            item.chave = p[i];
            push(item, &pilha);
        }
    }

    while(!itsVazia(pilha)){
        pop(&pilha, &item);
        resultado[inventer++] = item.chave;
    }

    resultado[inventer] = '\0';

    printf("Apos inversao:\n%s\n", resultado);
}

int main(){
    char entrada[] = "ESTE EXERCICIO E MUITO FACIL";
    InverterPalavras(entrada);
    return 0;
}