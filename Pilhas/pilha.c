#include "pilha.h"

void inicializar(Pilha *p){
    p->Topo = -1;
}

int itsVazia(Pilha p){
    return p.Topo == -1;
}

int push(TipoItem x, Pilha *p){ // funçao empilha
    if(p->Topo == MAX-1)
        return 0;
    else{
        p->Topo = p->Topo + 1;
        p->Item[p->Topo] = x;
    }
}

int pop(Pilha *p, TipoItem *Item){ // funçao desempilha
    if(p->Topo == -1)
        return 0;
    else{
        *Item = p->Item[p->Topo];
        p->Topo = p->Topo - 1;
        return 1;
    }
}

int imprimir(Pilha p){
    if(p.Topo == -1)
        return 0;
    else{
        for(int i = p.Topo; i >=0; --i){
            printf("%d \n", p.Item[i].chave);
        }
    return 1;
    }
}

int tamanho(Pilha p){
    return p.Topo + 1;
}