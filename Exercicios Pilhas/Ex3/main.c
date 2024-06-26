#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.c"

int Palindromo(char *palavra){
    Pilha p;
    TipoItem item;
    inicializar(&p);
    
    for(char *ptr = palavra; *ptr != '\0'; ptr++){
        if(*ptr >= 'a' && *ptr <= 'z'){
            item.chave = *ptr;
            push(item, &p);
        }else if (*ptr >= 'A' && *ptr <= 'Z'){
            item.chave = *ptr + ('a' - 'A');
            push(item, &p);
        }
    }

    for(char *ptr = palavra; *ptr != '\0'; ptr++){
        if((*ptr >= 'a' && *ptr <= 'z') || (*ptr >= 'A' && *ptr <= 'Z')){
            char currentChar = (*ptr >= 'A' && *ptr <= 'Z') ? *ptr + ('a' - 'A') : *ptr;
            pop(&p, &item);
            if(currentChar != item.chave){
                return 0; 
            }
        }
    }
    return 1; // É palíndromo
}

int main(){
    Pilha p;
    inicializar(&p);
    char palavra[100];
    
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    for(int i = 0; palavra[i]!= '\0'; i++){
        push((TipoItem) {palavra[i]}, &p);
    }

    if(Palindromo(palavra))
        printf("A palavra %s e um palindromo.\n", palavra);
    else 
        printf("A palavra %s nao e um palindromo.\n", palavra);
    return 0;
}