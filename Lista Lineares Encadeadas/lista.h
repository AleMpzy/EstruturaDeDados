#include <stdio.h>
#include <stdlib.h>

typedef struct NoTag{
    int chave;
    struct NoTag *prox;
} no;

typedef struct{
    no *comeco;
} L;

void IniciarLista(no **L);

void PercorrerLista(no **L);

void InserirFLista(no **L, int chave);

void InserirCLista(no **L, int chave);

void RemoverFLista(no **L);

void RemoverCLista(no **L);