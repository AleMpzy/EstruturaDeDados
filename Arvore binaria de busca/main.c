#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.c"

int main(){
    Node* raiz = NULL;
    char opcao;
    int chave;

    do{
        printf("  a - Inserir chave\n");
        printf("  b - Buscar chave\n");
        printf("  c - Remover chave\n");
        printf("  d - Pre-ordem\n");
        printf("  e - Em-ordem\n");
        printf("  f - Pos-ordem\n");
        printf("  g - Predecessor de uma chave\n");
        printf("  h - Sucessor de uma chave\n");
        printf("  i - Maximo valor na arvore\n");
        printf("  j - Minimo valor na arvore\n");
        printf("  q - Sair\n");
        scanf(" %c", &opcao);

        switch(opcao){
            case 'a':
                printf("Digite a chave a ser inserida: ");
                scanf("%d", &chave);
                raiz = inserir(raiz, chave);
                break;

            case 'b':
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &chave);
                if(buscar_chave(raiz, chave) != NULL)
                    printf("Chave %d encontrada na arvore.\n", chave);
                else
                    printf("Chave %d nao encontrada na arvore.\n", chave);
                break;

            case 'c':
                printf("Digite a chave a ser removida: ");
                scanf("%d", &chave);
                raiz = remover(raiz, chave);
                break;

            case 'd':
                printf("Pre-ordem: ");
                pre_ordem(raiz);
                printf("\n");
                break;

            case 'e':
                printf("Em-ordem: ");
                em_ordem(raiz);
                printf("\n");
                break;

            case 'f':
                printf("Pos-ordem: ");
                pos_ordem(raiz);
                printf("\n");
                break;

            case 'g':
                printf("Digite a chave para encontrar o predecessor: ");
                scanf("%d", &chave);
                Node* n_pred = buscar_chave(raiz, chave);
                if(n_pred != NULL){
                    Node* pred = predecessor(n_pred);
                    if(pred != NULL)
                        printf("O predecessor de %d e %d.\n", chave, pred->chave);
                    else
                        printf("Nao tem predecessor para %d.\n", chave);
                }
                else
                    printf("Chave %d nao encontrada na arvore.\n", chave);
                break;
            case 'h':
                printf("Digite a chave para encontrar o sucessor: ");
                scanf("%d", &chave);
                Node* n_suc = buscar_chave(raiz, chave);
                if(n_suc != NULL){
                    Node* suc = sucessor(n_suc);
                    if(suc != NULL)
                        printf("O sucessor de %d e %d.\n", chave, suc->chave);
                    else
                        printf("Nao tem sucessor para %d.\n", chave);
                } 
                else 
                    printf("Chave %d nao encontrada na arvore.\n", chave);
                break;
            case 'i':
                if(raiz != NULL){
                    Node* max = maximo(raiz);
                    printf("O maximo valor na arvore e %d.\n", max->chave);
                } 
                else{
                    printf("A arvore esta vazia.\n");
                }
                break;

            case 'j':
                if(raiz != NULL){
                    Node* min = minimo(raiz);
                    printf("O minimo valor na arvore e %d.\n", min->chave);
                } 
                else
                    printf("A arvore esta vazia.\n");
                break;

            case 'q':
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }while(opcao != 'q');
    return 0;
}