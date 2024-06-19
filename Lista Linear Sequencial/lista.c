
#include "lista.h"

void Iniciar(Lista *L) {
    L->N = 0;
}

int Retornar(Lista *L) {
    return L->N;
}

void Imprimir(Lista *L) {
    int i;
    for (i = 0; i < L->N; i++)
        printf("%d ", L->V[i].chave); 
}

int BuscarElemento(Lista *L, TipoChave *ch) {
    int i = 0;
    while (i < L->N) {
        if (*ch == L->V[i].chave) 
            return i;
        else
            i++;
    }
    return inv;
}

int InserirFinal(Lista *L, Registro *R) {
    if (L->N == max)
        return inv;
    else {
        L->V[L->N] = *R;
        L->N++;
        return val;
    }
}

int InserirComeco(Lista *L, Registro *R) {
    if (L->N == max)
        return inv;
    else {
        int j;
        for (j = L->N; j > 0; j--) 
            L->V[j] = L->V[j - 1]; 
        L->V[0] = *R;
        L->N++;
        return val;
    }
}

int InserirPosicao(Lista *L, Registro *R, int i) {
    if (L->N == max) {
        printf("\n Lista cheia!");
        return inv;
    } else if (i < 0 || i > L->N) {
        printf("\n Posicao invalida!");
        return inv;
    } else if (i == L->N) {
        return InserirFinal(L, R);
    } else {
        for (int j = L->N; j > i; j--) 
            L->V[j] = L->V[j - 1];
        L->V[i] = *R;
        L->N++;
        return val;
    }
}

int ExcluirElemento(Lista *L, TipoChave *ch) {
    int i, aux;
    if (L->N == 0) {
        printf("Lista vazia!");
        return inv;
    } else {
        aux = BuscarElemento(L, ch);
        if (aux == inv)
            return inv;
        else {
            for (i = aux; i < L->N - 1; i++) 
                L->V[i] = L->V[i + 1]; 
        }
        L->N--;
        return val;
    }
}

void ReniciarLista(Lista *L) {
    L->N = 0;
}