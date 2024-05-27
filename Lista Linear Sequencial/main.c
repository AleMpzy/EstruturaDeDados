#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main() {
    Lista lista;
    TipoChave chave;
    Registro newRegistro;
    char esc;

    Iniciar(&lista);

    do {
        printf("\n Escolha uma opcao: \n");
        printf("a. Inserir elemento no comeco da lista \n");
        printf("b. Inserir elemento no final da lista \n");
        printf("c. Inserir elemento em uma posicao especifica \n");
        printf("d. Excluir elemento da lista \n");
        printf("e. Imprimir lista \n");
        printf("f. Reiniciar lista \n");
        printf("q. Quitar \n");

        scanf(" %c", &esc);

        switch (esc) {
            case 'a' :
                printf("\n Digite o valor do novo elemento: ");
                scanf("%d", &newRegistro.chave);
                InserirComeco(&lista, &newRegistro);
                printf("Elemento inserido no comeco da lista com sucesso! \n");
                break;
            case 'b':
                printf("\n Digite o valor do novo elemento: ");
                scanf("%d", &newRegistro.chave);
                if (InserirFinal(&lista, &newRegistro))
                    printf("Elemento inserido no final da lista com sucesso! \n");
                else
                    printf("Nao foi possivel inserir o elemento :( \n");
                break;
            case 'c':
                printf("\n Digite o valor do novo elemento: ");
                scanf("%d", &newRegistro.chave);
                int posicao;
                printf("Digite a posicao onde deseja inserir o elemento: ");
                scanf("%d", &posicao);
                if (InserirPosicao(&lista, &newRegistro, posicao))
                    printf("Elemento inserido na posicao %d da lista com sucesso! \n", posicao);
                else
                    printf("Nao foi possivel inserir o elemento :( \n");
                break;
            case 'd':
                printf("\n Digite a chave do elemento a ser excluido: ");
                scanf("%d", &chave);
                if (ExcluirElemento(&lista, &chave))
                    printf("Elemento com chave %d excluido com sucesso! \n", chave);
                else
                    printf("Elemento com chave %d nao encontrado ou lista vazia :( \n", chave);
                break;
            case 'e':
                printf("\n Lista: ");
                Imprimir(&lista);
                printf("\n");
                break;
            case 'f':
                ReniciarLista(&lista);
                printf("Lista reiniciada! \n");
                break;
            case 'q':
                printf("Quitando... \n");
                break;
            default:
                printf("Opcao invalida! \n");
                break;
        }
    } while (esc != 'q');

    return 0;
}