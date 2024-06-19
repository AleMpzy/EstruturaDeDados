#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int main(){
    Pilha pilha;
    TipoItem chave;
    char esc;

    inicializar(&pilha);

    do{
        printf("\n Escolha uma opcao: \n");
        printf("a. Inserir item na pilha \n");
        printf("b. Remover item da pilha \n");
        printf("c. Listar dados da pilha \n");
        printf("d. Retornar tamanho da pilha \n");
        printf("q. Sair \n");

        scanf(" %c", &esc);

        switch(esc){
            case 'a' :
                printf("\n Digite o valor do novo item: \n");
                scanf("%d", &chave);
                if(push(chave, &pilha) == 0)
                    printf("Pilha Cheia! \n");
                break;
            case 'b':
                printf("Removendo item... \n");
                if(pop(&pilha, &chave) == 0)
                    printf("Pilha Vazia! \n");
                else
                    printf("Item excluido: %d\n", chave);
                break;
            case 'c':
                printf("Exibindo itens... \n");
                if(imprimir(pilha) == 0)
                    printf("Pilha Vazia! \n");
                break;
            case 'd':
                printf("Tamanho da pilha: %d \n", tamanho(pilha));
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