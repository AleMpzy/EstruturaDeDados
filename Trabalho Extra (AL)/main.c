#include <stdio.h>
#include <stdlib.h>

float determinante_menor(float menor[3][3]){
    return menor[0][0] * (menor[1][1] * menor[2][2] - menor[1][2] * menor[2][1]) 
         - menor[0][1] * (menor[1][0] * menor[2][2] - menor[1][2] * menor[2][0]) 
         + menor[0][2] * (menor[1][0] * menor[2][1] - menor[1][1] * menor[2][0]);
}

float determinante(float matrix[4][4]){
    float det = 0;
    for(int i = 0; i < 4; i++){
        float menor[3][3];
        for(int j = 1, l = 0; j < 4; j++, l++){
            for(int k = 0, m = 0; k < 4; k++){
                if(k != i){
                    menor[l][m++] = matrix[j][k];
                }
            }
        }
        float det_menor = determinante_menor(menor);
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * det_menor; 
    }
    return det;
}

int main(){
    float matrix[4][4];
    printf("Digite a matriz 4x4:\n"); // digite da esquerda pra direita a cada linha
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    printf("Determinante: %f\n", determinante(matrix));
    return 0;
}

/* Linha 22 explicada ->

int sinal;
    if(i % 2 == 0)
        sinal = 1;
    else 
        sinal = -1;
    det += sinal * matrix[0][i] * det_menor;
    
*/