#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int pilhasIguais(Pilha *p1, Pilha *p2){
    if(tamanho(*p1) != tamanho(*p2)){
        return 0;
    }

    Pilha aux1, aux2;
    inicializar(&aux1);
    inicializar(&aux2);

    int iguais = 1;

    TipoItem item1, item2;

    while(!itsVazia(*p1) && !itsVazia(*p2)){
        pop(p1, &item1);
        pop(p2, &item2);
        push(item1, &aux1);
        push(item2, &aux2);

        if(item1.chave != item2.chave){
            iguais = 0;
        }
    }

    while(!itsVazia(aux1)){
        pop(&aux1, &item1);
        pop(&aux2, &item2);
        push(item1, p1);
        push(item2, p2);
    }

    return iguais;
}

int main(){
    Pilha P1, P2;
    TipoItem temp;
    
    inicializar(&P1);
    inicializar(&P2);

    push((TipoItem){11}, &P1);
    push((TipoItem){22}, &P1);
    push((TipoItem){33}, &P1);

    push((TipoItem){11}, &P2);
    push((TipoItem){22}, &P2);
    push((TipoItem){33}, &P2);

    printf("Exibindo itens da P1: \n");
    imprimir(P1);

    printf("Exibindo itens da P2: \n");
    imprimir(P2);

    if(pilhasIguais(&P1, &P2)){
        printf("P1 e P2 sao iguais!\n");
    } 
    else{
        printf("P1 e P2 nao sao iguais!\n");
    }
    return 0;
}