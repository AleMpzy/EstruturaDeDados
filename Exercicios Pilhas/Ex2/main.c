#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int main(){
    Pilha P1, P2;
    TipoItem temp;
    
    inicializar(&P1);
    inicializar(&P2);

    push((TipoItem){1}, &P1);
    push((TipoItem){2}, &P1);
    push((TipoItem){3}, &P1);

    printf("Exibindo itens da P1: \n");
    imprimir(P1);

    printf("Transferindo itens da P1 para P2...\n");

    while(!itsVazia(P1)){
        pop(&P1, &temp);
        push(temp, &P2);
    }

    printf("Exibindo itens da P2: \n");
    imprimir(P2);
    return 0;
}