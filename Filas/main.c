#include <stdio.h>
#include <stdlib.h>
#include "fila.c"

int main(){
    Fila fila;
    int item;
    char esc;
    int aux;

    inicializar(&fila);

    do{
        printf("\n Escolha uma opcao: \n");
        printf("a. Inserir item na fila \n");
        printf("b. Remover item da fila \n");
        printf("c. Listar dados da fila \n");
        printf("q. Sair \n");

        scanf(" %c", &esc);

        switch(esc){
            case 'a' :
                printf("\n Digite o valor do novo item: \n");
                scanf("%d", &item);
                if(enfileirar(&fila, item) == inv)
                    printf("Fila cheia! :( \n");
                else
                    printf("Item inserido no final da fila com sucesso! \n");
                break;
            case 'b':
                printf("Removendo item... \n");
                if(desenfileirar(&fila, &aux) == inv)
                    printf("Fila vazia! :( \n");
                else
                    printf("Item excluido: %d\n", aux);
                break;
            case 'c':
                printf("Exibindo itens... \n");
                if(exibir(&fila) == inv)
                    printf("Fila vazia! :( \n");
                break;
            case 'q':
                printf("Saindo... \n");
                break;
            default:
                printf("Opcao invalida! \n");
                break;
        }
    }while(esc != 'q');
    return 0;
}