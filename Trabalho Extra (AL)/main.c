#include <stdio.h>
#include <stdlib.h>

float determinante_menor(float menor[3][3]){
    float a = menor[0][0];
    float b = menor[0][1];
    float c = menor[0][2];
    float d = menor[1][0];
    float e = menor[1][1];
    float f = menor[1][2];
    float g = menor[2][0];
    float h = menor[2][1];
    float i = menor[2][2];

    return a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
}

float determinante(float matrix[4][4]){
    float det = 0;
    int i;

    for(i = 0; i < 4; i++){
        float menor[3][3];
        int j, k, l = 0, m = 0;

        for(j = 1; j < 4; j++){
            for(k = 0; k < 4; k++){
                if(k != i){
                    menor[l][m] = matrix[j][k];
                    m++;
                }
            }
            l++;
            m = 0;
        }

        float det_menor = determinante_menor(menor);

        int sinal;
        if(i % 2 == 0)
            sinal = 1;
        else
            sinal = -1;
        det += sinal * matrix[0][i] * det_menor;
    }

    return det;
}

int main(){
    float matrix[4][4];
    int i, j;

    printf("Digite a matriz 4x4:\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%f", &matrix[i][j]);
        }
    }

    float det = determinante(matrix);

    printf("Determinante: %f\n", det);

    return 0;
}