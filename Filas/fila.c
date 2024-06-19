#include "fila.h"

void inicializar(Fila *f){
    f->inicio = 0;
    f->fim = 0;
    f->tam = 0;
}

int itsVazia(Fila *f) {
    if (f->tam == 0)
        return(1);
    else
        return(0);
}

int enfileirar(Fila *f, int x){
    if(f->tam == MAXSIZE)
        return inv;
    else{
        f->item[f->fim] = x;
        f->tam++;
        if(f->fim == MAXSIZE -1)
            f->fim = 0;
        else
            f->fim++;
    return(f->fim);
    }
}

int desenfileirar(Fila *f, int *aux){
    if(f->tam == 0)
        return inv;
    else{
        *aux = f->inicio[f->item];
        if(f->inicio != MAXSIZE-1)
            f->inicio++;
        else
            f->inicio = 0;
    }
    f->tam--;
    return *aux;
}

int itsCheia(Fila *f){
    if(f->tam == MAXSIZE)
        return (1);
    else
        return (0);
}

int exibir(Fila *f){
    if(f->tam == 0)
        return inv;
    else{ 
        int i = f->inicio;
        for(int cont = 0; cont < f->tam; cont++){
            printf("%d ", f->item[i]);
            i = (i + 1) % MAXSIZE;
        }
    printf("\n");
    return 0;
    }
}