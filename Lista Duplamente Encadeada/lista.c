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

void InserirFinal(no **L, int chave){
    no *P = *L;
    no *N = (no *) malloc (sizeof(no));

    N->chave = chave;
    N->prox = NULL;

    if(*L == NULL){ 
        *L = N;
        N->ant = NULL;
    }
    else{
        while(P->prox != NULL)
            P = P->prox;
        P->prox = N; 
        N->ant = P;
    }
}

void InserirInicio(no **L, int chave){
    no *N = (no *) malloc (sizeof(no));
    N->chave = chave;
    N->prox = *L;
    N->ant = NULL;
    *L = N;
}

void RemoverFinal(no **L){
    if(*L == NULL)
        printf("\nLista vazia!");

    no *P = *L;

    if(P->prox == NULL){
        free(P);
        *L = NULL;
    }

    while(P->prox != NULL){
        P = P->prox;
    }

    P->ant->prox = NULL;
    free(P);
}

void RemoverInicio(no **L){
    if(*L == NULL)
        printf("\nLista vazia!");

    no *aux  = *L;
    *L = (*L)->prox;
    free(aux);
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