#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int verificarpilhas(Pilha *p1, Pilha *p2){
        return tamanho(*(p1)) > tamanho(*(p2));
    }

int main(){
    Pilha P1, P2;
    TipoItem temp;
    
    inicializar(&P1);
    inicializar(&P2);

    push((TipoItem){11}, &P1);
    push((TipoItem){22}, &P1);
    push((TipoItem){33}, &P1);

    push((TipoItem){10}, &P2);
    push((TipoItem){47}, &P2);

    printf("Exibindo itens da P1: \n");
    imprimir(P1);

    printf("Exibindo itens da P2: \n");
    imprimir(P2);

    if(verificarpilhas(&P1, &P2)){
        printf("P1 tem mais elementos que P2\n");
    } 
    else{
        printf("P1 nao tem mais elementos que P2\n");
    }
    return 0;
}