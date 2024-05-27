#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void IniciarLista(Lista *L){
    int i;
    for(i = 0; i < max - 1; i++)
        L->V[i].proximo = i + 1;
    L->V[max - 1].proximo = inv;
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
        printf("%d ", L->V[i].r.chave); 
        i = L->V[i].proximo;
    }
}

int BuscarElemento(Lista *L, TipoChave ch){
    int i = L->inicio;
    while(i != inv && L->V[i].r.chave < ch)
        i = L->V[i].proximo;
    if(i != inv && L->V[i].r.chave == ch)
        return i; 
    return inv; 
}

bool InserirElemento(Lista *L, Registro r){
    int i = L->inicio;
    int ant = inv; 
    while(i != inv && L->V[i].r.chave < r.chave){
        ant = i;
        i = L->V[i].proximo;
    }
    if(i != inv && L->V[i].r.chave == r.chave)
        return false; 
    else{
        int aux = L->disponivel;
        L->disponivel = L->V[L->disponivel].proximo;
        L->V[aux].proximo = i; 
        L->V[aux].r = r; 
        if(ant == inv) 
            L->inicio = aux; 
        else
            L->V[ant].proximo = aux; 
        return true;
    }
}

bool ExcluirElemento(Lista *L, TipoChave ch){
    int atual = L->inicio;
    int ant = inv;

    while (atual != inv && L->V[atual].r.chave != ch) {
        ant = atual;
        atual = L->V[atual].proximo;
    }

    if (atual == inv)
        return false;

    if (ant == inv)
        L->inicio = L->V[atual].proximo;
    else
        L->V[ant].proximo = L->V[atual].proximo;

    L->V[atual].proximo = L->disponivel;
    L->disponivel = atual;
    
    return true;
}
