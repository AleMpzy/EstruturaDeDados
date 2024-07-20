#include "arvore_binaria.h"

No getnode(){
    No p;
    p = (No)malloc(sizeof(No));
    return p;
}

No vazia(){
    return NULL;
}

No criarArvore(int chave){
    No raiz;
    raiz = getnode();
    raiz->info = chave;
    raiz->esquerda = NULL;
    raiz->direita = NULL;
    return raiz;
}

No inserir(No* raiz, int valor){
    if(*raiz == NULL){
        *raiz = criarArvore(valor);
    } 
    else{
        if(valor < (*raiz)->info){
            if((*raiz)->esquerda == NULL){
                (*raiz)->esquerda = criarArvore(valor);
                (*raiz)->esquerda->pai = *raiz;
            } 
            else
                inserir(&((*raiz)->esquerda), valor);
        } 
        else{
            if((*raiz)->direita == NULL){
                (*raiz)->direita = criarArvore(valor);
                (*raiz)->direita->pai = *raiz;
            } 
            else
                inserir(&((*raiz)->direita), valor);
        }
    }
}

No busca_chave(No raiz, int chave){
    if(raiz == NULL || raiz->info == chave)
        return raiz;
    else if(chave < raiz->info)
        return busca_chave(raiz->esquerda, chave);
    else
        return busca_chave(raiz->direita, chave);
}

void remover(No* raiz, int valor){
    No nodo = busca_chave(*raiz, valor);
    if(nodo != NULL){
        if(nodo->esquerda == NULL && nodo->direita == NULL){
            if(nodo->pai != NULL){
                if(nodo->pai->esquerda == nodo){
                    nodo->pai->esquerda = NULL;
                } 
                else{
                    nodo->pai->direita = NULL;
                }
            } 
            else 
                *raiz = NULL;

            free(nodo);
        } 
        else if(nodo->esquerda == NULL){
            if(nodo->pai != NULL){
                if(nodo->pai->esquerda == nodo)
                    nodo->pai->esquerda = nodo->direita;
                else 
                    nodo->pai->direita = nodo->direita;
            } 
            else
                *raiz = nodo->direita;

            free(nodo);
        }
        else if(nodo->direita == NULL){
            if(nodo->pai != NULL){
                if(nodo->pai->esquerda == nodo){
                    nodo->pai->esquerda = nodo->esquerda;
                } 
                else{
                    nodo->pai->direita = nodo->esquerda;
                }
            } 
            else
                *raiz = nodo->esquerda;

            free(nodo);
        } 
        else{
            No menor = nodo->direita;
            while(menor->esquerda != NULL){
                menor = menor->esquerda;
            }
            nodo->info = menor->info;
            remover(&(nodo->direita), menor->info);
        }
    }
}

void pre_ordem(No raiz){
    if(raiz != NULL){
        printf("%d ", raiz->info);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(No raiz){
    if(raiz != NULL){
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->info);
        em_ordem(raiz->direita);
    }
}

void pos_ordem(No raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->info);
    }
}

No predecessor(No raiz, int chave){
    No nodo = busca_chave(raiz, chave);
    if(nodo != NULL){
        if(nodo->esquerda != NULL)
            return nodo->esquerda;
        else{
            No pai = nodo->pai;
            while(pai != NULL && pai->esquerda == nodo){
                nodo = pai;
                pai = pai->pai;
            }
            return pai;
        }
    }
    return NULL;
}

No sucessor(No raiz, int chave){
    No nodo = busca_chave(raiz, chave);
    if(nodo != NULL){
        if(nodo->direita != NULL)
            return nodo->direita;
        else{
            No pai = nodo->pai;
            while(pai != NULL && pai->direita == nodo){
                nodo = pai;
                pai = pai->pai;
            }
            return pai;
        }
    }
    return NULL;
}

No maximo(No raiz){
    if(raiz == NULL)
        return NULL;
    No nodo = raiz;
    while(nodo->direita != NULL){
        nodo = nodo->direita;
    }
    return nodo;
}

No minimo(No raiz){
    if(raiz == NULL)
        return NULL;
    No nodo = raiz;
    while(nodo->esquerda != NULL){
        nodo = nodo->esquerda;
    }
    return nodo;
}