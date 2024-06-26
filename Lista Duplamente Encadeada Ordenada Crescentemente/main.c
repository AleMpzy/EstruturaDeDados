#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main(){
    no* l = NULL;
    IniciarLista(&l);

    InserirChave(&l, 10);
    InserirChave(&l, 22);
    InserirChave(&l, 47);
    printf("Lista apos insercoes de 10, 22 e 47:");
    ImprimirLista(&l);

    InserirChave(&l, 7);
    InserirChave(&l, 1);
    printf("\nLista apos insercoes de 7 e 1:");
    ImprimirLista(&l);

    printf("\nTamanho da lista: %d", RetornarTamanho(&l));

    BuscarChave(&l, 22);
    BuscarChave(&l, 40);

    RemoverChave(&l, 22);
    printf("\nLista apos remover chave:");
    ImprimirLista(&l);

    ReiniciarLista(&l);
    printf("\nLista apos reiniciar:");
    ImprimirLista(&l);
    return 0;
}