#include <stdlib.h>
#include <stdio.h>
#include "lista.h"

void IniciarLista(no **L){
    *L = NULL;
}

void PercorrerLista(no **L){
    no *P = *L;

    while(P != NULL){
        printf("\n %d", P->chave);
        P = P->prox;
    }
}

void InserirFLista(no **L, int chave){
    no *P = *L;
    no *N = (no *) malloc (sizeof(no));

    N->chave = chave;
    N->prox = NULL;

    if(*L == NULL)
        *L = N;

    else{
        while(P->prox != NULL)
            P = P->prox;
        P->prox = N; 
    }
}

void InserirCLista(no **L, int chave){
    no *N = (no *) malloc (sizeof(no));
    N->chave = chave;
    N->prox = *L;
    *L = N;
}

void RemoverFLista(no **L){
    if(*L == NULL)
        printf("Lista vazia!");

    no *P = *L;
    no *ant = NULL;

    if(P->prox == NULL){
        free(P);
        *L = NULL;
    }

    while(P->prox != NULL){
        ant = P;
        P = P->prox;
    }

    ant->prox = NULL;
    free(P);
}


void RemoverCLista(no **L){
    if(*L == NULL)
        printf("Lista vazia!");

    no *aux  = *L;
    *L = (*L)->prox;
    free(aux);
}