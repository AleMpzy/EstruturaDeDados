#include "lista.h"

void IniciarLista(no **L){
    *L = NULL;
}

int RetornarTamanho(no **L){
    no *P = *L;
    int tam = 0;

    while(P != NULL){
        tam++;
        P = P->prox;
    }

    return tam;
}

void ImprimirLista(no **L){
    no *P = *L;

    while(P != NULL){
        printf("\n %d", P->chave);
        P = P->prox;
    }
}

void InserirChave(no **L, int chave){ 
    no *N = (no *) malloc (sizeof(no));
    N->chave = chave;
    N->prox = NULL;
    N->ant = NULL;

    if(*L == NULL){ 
        *L = N;
    }
    else if(chave < (*L)->chave){
        N->prox = *L;
        (*L)->ant = N;
        *L = N;
    }
    else{
        no *P = *L;
        while(P->prox != NULL && P->prox->chave < chave){
            P = P->prox;
        }
        N->prox = P->prox;
        if(P->prox != NULL){
            P->prox->ant = N;
        }
        P->prox = N;
        N->ant = P;
    }
}

void RemoverChave(no **L, int chave){
    if(*L == NULL)
        printf("\nLista vazia!");

    no *P = *L;

    while(P != NULL && P->chave != chave){
        P = P->prox;
    }

    if(P == NULL)
        printf("\nChave nao encontrada!");
    
    if(P->ant != NULL)
        P->ant->prox = P->prox;
    else
        *L = P->prox;

    if(P->prox != NULL)
        P->prox->ant = P->ant;

    free(P);
    printf("\nChave %d removida!", chave);
}

void BuscarChave(no **L, int chave){
    if(*L == NULL)
        printf("\nLista vazia!");

    no *P = *L;

    while(P != NULL && P->chave != chave){
        P = P->prox;
    }

    if(P == NULL)
        printf("\nChave %d nao encontrada!", chave);
    else
        printf("\nChave %d encontrada!", chave);
}

void ReiniciarLista(no **L){
    no *P = *L;
    no *aux;

    while(P != NULL){ 
        aux = P->prox;
        free(P); 
        P = aux; 
    }

    *L = NULL; 
}