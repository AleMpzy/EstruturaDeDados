#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.c"

int main(){
    No raiz = NULL;
    char esc;
    int chave;

    do{
        printf("Escolha uma opcao:\n");
        printf("  a - Inserir chave\n");
        printf("  b - Buscar chave\n");
        printf("  c - Predecessor de uma chave\n");
        printf("  d - Sucessor de uma chave\n");
        printf("  e - Maximo valor na arvore\n");
        printf("  f - Minimo valor na arvore\n");
        printf("  q - Sair\n");
        scanf(" %c", &esc);

        switch(esc){
            case 'a':
                printf("Digite a chave a ser inserida: ");
                scanf("%d", &chave);
                raiz = inserir(&raiz, chave);
                break;

            case 'b':
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &chave);
                No nodo = busca_chave(raiz, chave);
                if(nodo!= NULL)
                    printf("Chave encontrada!\n");
                else 
                    printf("Chave nao encontrada!.\n");
                break;

            case 'c':
                printf("Digite a chave para encontrar o predecessor: ");
                scanf("%d", &chave);
                nodo = predecessor(raiz, chave);
                if(nodo!= NULL)
                    printf("Predecessor: %d\n", nodo->info);
                else 
                    printf("Predecessor nao encontrado.\n");
                break;

            case 'd':
                printf("Digite a chave para encontrar o sucessor: ");
                scanf("%d", &chave);
                nodo = sucessor(raiz, chave);
                if(nodo!= NULL)
                    printf("Sucessor: %d\n", nodo->info);
                else
                    printf("Sucessor nao encontrado.\n");
                break;

            case 'e':
                nodo = maximo(raiz);
                if(nodo!= NULL)
                    printf("Maximo valor: %d\n", nodo->info);
                else
                    printf("Arvore vazia.\n");
                break;

            case 'f':
                nodo = minimo(raiz);
                if(nodo!= NULL) 
                    printf("Minimo valor: %d\n", nodo->info);
                else 
                    printf("Arvore vazia.\n");
                break;

            case 'q':
                printf("Saindo...\n");
                break;

            default:
                printf("ERRO!.\n");
        }
    }while(esc!= 'q');

    return 0;
}