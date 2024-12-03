#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 49 // max 7 * 7

typedef struct{
    int u, v;
} Aresta;


int main(){
    int n_testes;
    scanf("%d", &n_testes);

    for (int teste = 0; teste < n_testes; teste++){
        int no_inicio, v, a;
        scanf("%d", &no_inicio);
        scanf("%d %d", &v, &a);

        int adj[MAX_VERTICES][MAX_VERTICES] = {{0}};
        Aresta arestas[a]; 

        for (int i = 0; i < a; i++){
            scanf("%d %d", &arestas[i].u, &arestas[i].v);
            adj[arestas[i].u][arestas[i].v] = 1;
            adj[arestas[i].v][arestas[i].u] = 1;
        }

        int movimentos = 0;

        for (int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                movimentos += adj[i][j];
            }
        }
        
        printf("%d\n", movimentos);
    }

    return 0;
}