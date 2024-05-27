#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main() {
    no *l = NULL;
    IniciarLista(&l);

    InserirCLista(&l, 11);
    InserirFLista(&l, 22);
    InserirCLista(&l, 10);

    printf("\n  Lista apos insercoes: ");
    PercorrerLista(&l);

    InserirCLista(&l, 7);

    printf("\n Lista apos insercao no comeco: ");
    PercorrerLista(&l);

    RemoverFLista(&l);

    printf("\n Lista apos remocao no final: ");
    PercorrerLista(&l);

    RemoverCLista(&l);

    printf("\n Lista apos remocao no comeco: ");
    PercorrerLista(&l);
    
    return 0;
}