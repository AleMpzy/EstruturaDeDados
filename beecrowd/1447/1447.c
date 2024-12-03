#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 150
#define INF INT_MAX

typedef struct{
    int u, v, prox;
    int custo, capacidade;
} Aresta;

typedef struct{
    long long int origem, destino, custo; // a, b, c;
} Rota;

Aresta grafo[MAX_VERTICES * 4]; 
Rota rotas[MAX_VERTICES];
int anterior[MAX_VERTICES];
long long int distancia[MAX_VERTICES], custo_menor_caminho, fluxo_atual;
long long int p[MAX_VERTICES], V, E, num_arestas;
long long int fluxo_total = 0, custo_total = 0;
int visitado[MAX_VERTICES];

typedef struct{
    int vertice, distancia;
} NodoFila;

NodoFila heap[MAX_VERTICES * 4];
int tam_heap = 0;

void inserirHeap(int vertice, int distancia){
    int i = tam_heap++;
    while(i > 0 && distancia < heap[(i - 1) / 2].distancia){
        heap[i] = heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap[i] = (NodoFila){vertice, distancia};
}

NodoFila removerHeap(){
    NodoFila min = heap[0];
    NodoFila temp = heap[--tam_heap];
    int i = 0, filho;

    while((filho = 2 * i + 1) < tam_heap){
        if(filho + 1 < tam_heap && heap[filho + 1].distancia < heap[filho].distancia)
            filho++;
        if(temp.distancia <= heap[filho].distancia)
            break;
        heap[i] = heap[filho];
        i = filho;
    }
    heap[i] = temp;
    return min;
}

int vazioHeap(){
    return tam_heap == 0;
}

void adicionarAresta(int u, int v, int custo, int capacidade){
    grafo[num_arestas] = (Aresta){u, v, anterior[u], custo, capacidade};
    anterior[u] = num_arestas++;
    grafo[num_arestas] = (Aresta){v, u, anterior[v], -custo, 0};
    anterior[v] = num_arestas++;
}

void aumentarFluxo(int v, int min_fluxo){
    for(int i = p[v]; i != -1; i = p[grafo[i].u]){
        min_fluxo = (min_fluxo < grafo[i].capacidade) ? min_fluxo : grafo[i].capacidade;
    }

    for(int i = p[v]; i != -1; i = p[grafo[i].u]){
        grafo[i].capacidade -= min_fluxo;
        grafo[i ^ 1].capacidade += min_fluxo;
    }
    fluxo_atual = min_fluxo;
}

int dijkstra(int s, int t){
    for(int i = 0; i <= V + 1; ++i){
        distancia[i] = INF;
        p[i] = -1;
    }

    tam_heap = 0;
    distancia[s] = 0;
    inserirHeap(s, 0);

    while(!vazioHeap()){
        NodoFila atual = removerHeap();
        int u = atual.vertice;

        if(distancia[u] < atual.distancia) continue;

        for(int i = anterior[u]; i != -1; i = grafo[i].prox){
            int v = grafo[i].v;
            if(grafo[i].capacidade > 0 && distancia[u] + grafo[i].custo < distancia[v]){
                distancia[v] = distancia[u] + grafo[i].custo;
                p[v] = i;
                inserirHeap(v, distancia[v]);
            }
        }
    }

    custo_menor_caminho = distancia[t];
    return custo_menor_caminho != INF;
}

int main(){
    num_arestas = 0;
    int k = 1;
    int demanda, capacidade_maxima;

    while(scanf("%lld %lld", &V, &E) != EOF){
        num_arestas = 0;
        fluxo_total = 0;
        custo_total = 0;
        for(int i = 0; i <= V + 1; ++i)
            anterior[i] = -1;

        for(int i = 0; i < E; ++i)
            scanf("%lld %lld %lld", &rotas[i].origem, &rotas[i].destino, &rotas[i].custo);

        scanf("%d %d", &demanda, &capacidade_maxima);

        printf("Instancia %d\n", k++);

        adicionarAresta(0, 1, 0, demanda);
        adicionarAresta(V, V + 1, 0, demanda);

        for(int i = 0; i < E; ++i){
            adicionarAresta(rotas[i].origem, rotas[i].destino, rotas[i].custo, capacidade_maxima);
            adicionarAresta(rotas[i].destino, rotas[i].origem, rotas[i].custo, capacidade_maxima);
        }

        while(dijkstra(0, V + 1)){
            fluxo_atual = 0;
            aumentarFluxo(V + 1, INF);
            fluxo_total += fluxo_atual;
            custo_total += custo_menor_caminho * fluxo_atual;

            if(fluxo_total >= demanda)
                break;
        }

        if(fluxo_total < demanda)
            printf("impossivel\n\n");
        else 
            printf("%lld\n\n", custo_total);
    }

    return 0;
}