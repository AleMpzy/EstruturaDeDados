#include <stdio.h>
#include <stdlib.h>
#include "lista.c"

int main() {
    Lista lista1;
    IniciarLista(&lista1);
    Registro r1 = {10}; 
    Registro r2 = {20}; 
    Registro r3 = {30}; 
    InserirElemento(&lista1, r1);
    InserirElemento(&lista1, r2);
    InserirElemento(&lista1, r3);
    printf("\nElementos da lista: \n");
    ImprimirLista(&lista1);

    TipoChave chaveExcluir = 20;

    bool excluido = ExcluirElemento(&lista1, chaveExcluir);
    if (excluido)
        printf("\nElemento com chave %d excluido com sucesso.\n", chaveExcluir);
    else
        printf("\nElemento com chave %d nao encontrado na lista.\n", chaveExcluir);
        
    printf("\nElementos da lista apos a exclusao: \n");
    ImprimirLista(&lista1);
    printf("\n");

    return 0;
}
