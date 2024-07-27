#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

Node* getNode(){
    Node* p = (Node*)malloc(sizeof(Node));
    return p;
}

Node* inserir(Node* raiz, int chave){
    if(raiz == NULL){
        Node* novo = getNode();
        novo->chave = chave;
        novo->esquerda = novo->direita = novo->pai = NULL;
        return novo;
    }
    if(chave < raiz->chave){
        Node* esquerda = inserir(raiz->esquerda, chave);
        raiz->esquerda = esquerda;
        if(esquerda != NULL) 
            esquerda->pai = raiz;
    }
    else if(chave > raiz->chave){
        Node* direita = inserir(raiz->direita, chave);
        raiz->direita = direita;
        if(direita != NULL) 
            direita->pai = raiz;
    }
    return raiz;
}

Node* buscar_chave(Node* raiz, int chave){
    if(raiz == NULL || raiz->chave == chave)
        return raiz;
    if(chave < raiz->chave)
        return buscar_chave(raiz->esquerda, chave);

    return buscar_chave(raiz->direita, chave);
}

Node* remover(Node* raiz, int chave){
    if(raiz == NULL)
        return raiz;
    if(chave < raiz->chave){
        raiz->esquerda = remover(raiz->esquerda, chave);
    } 
    else if(chave > raiz->chave)
        raiz->direita = remover(raiz->direita, chave);
    else{
        if(raiz->esquerda == NULL){
            Node* temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if(raiz->direita == NULL){
            Node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        Node* temp = minimo(raiz->direita);
        raiz->chave = temp->chave;
        raiz->direita = remover(raiz->direita, temp->chave);
    }
    return raiz;
}

void pre_ordem(Node* raiz){
    if(raiz != NULL){
        printf("%d ", raiz->chave);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void em_ordem(Node* raiz){
    if(raiz != NULL){
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->chave);
        em_ordem(raiz->direita);
    }
}

void pos_ordem(Node* raiz){
    if(raiz != NULL){
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}

Node* predecessor(Node* n){
    if(n->esquerda != NULL){
        Node* atual = n->esquerda;
        while(atual && atual->direita != NULL)
            atual = atual->direita;
        return atual;
    }
    Node* pred = n->pai;
    while(pred != NULL && n == pred->esquerda){
        n = pred;
        pred = pred->pai;
    }
    return pred;
}

Node* sucessor(Node* n) {
    if(n->direita != NULL){
        Node* atual = n->direita;
        while(atual && atual->esquerda != NULL)
            atual = atual->esquerda;
        return atual;
    }
    Node* suc = n->pai;
    while(suc != NULL && n == suc->direita){
        n = suc;
        suc = suc->pai;
    }
    return suc;
}

Node* maximo(Node* raiz){
    Node* atual = raiz;
    while(atual && atual->direita != NULL)
        atual = atual->direita;
    return atual;
}

Node* minimo(Node* raiz){
    Node* atual = raiz;
    while(atual && atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}