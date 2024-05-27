#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void IniciarLista(Lista *L){
    int i;
    for(i=0; i<max-1; i++)
        L->V[i].proximo = i+1;
    L->V[max-1].proximo = inv;
    L->inicio = inv;
    L->disponivel = 0;
}

int NumeroElementos(Lista *L){
    int i = L->inicio;
    int tamanho = 0;
    while(i != inv){
        tamanho++;
        i = L->V[i].proximo;
    }
    return tamanho;
}

void ImprimirLista(Lista *L){
    int i = L->inicio;
    while(i != inv){
        L->V[i];
        printf("%d ", L->V[i]);
        i = L->V[i].proximo;
    }
}

int BuscarElemento(Lista *L, TipoChave ch){
    int i = L->inicio;
    while(i != inv && L->V[i].r.chave<ch)
        i = L->V[i].proximo;
    if(i != inv && L->V[i].r.chave==ch)
        return i; 
}

bool InserirElemento(Lista *L, Registro r){
    int i = L->inicio;
    int ant; // antecessor 
        while(i!=inv && L->V[i].r.chave<r.chave){
            ant = i;
            ant = L->V[i].proximo;
        }
        if(ant!= inv && L->V[ant].r.chave==r.chave)
            return 0;
        else{
            int aux = L->disponivel;
            L->V[L->disponivel].proximo = L->V[i].proximo;
            L->V[i].proximo = L->disponivel;
            L->V[L->disponivel].r.chave = r.chave;
        }
    return 0;
}
