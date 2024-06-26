#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main(){
    no* l = NULL;
    IniciarLista(&l);

    InserirFinal(&l, 10);
    InserirFinal(&l, 22);
    InserirFinal(&l, 47);
    printf("Lista apos insercoes no final:");
    ImprimirLista(&l);

    InserirInicio(&l, 7);
    InserirInicio(&l, 1);
    printf("\nLista apos insercoes no inicio:");
    ImprimirLista(&l);

    printf("\nTamanho da lista: %d", RetornarTamanho(&l));

    BuscarChave(&l, 22);
    BuscarChave(&l, 40);

    RemoverFinal(&l);
    printf("\nLista apos remover final:");
    ImprimirLista(&l);

    RemoverInicio(&l);
    printf("\nLista apos remover inicio:");
    ImprimirLista(&l);

    RemoverChave(&l, 22);
    printf("\nLista apos remover chave:");
    ImprimirLista(&l);

    ReiniciarLista(&l);
    printf("\nLista apos reiniciar:");
    ImprimirLista(&l);
    return 0;
}