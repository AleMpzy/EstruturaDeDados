#define MAXSIZE 100
#define inv -1

typedef struct{
    int item[MAXSIZE];
    int inicio;
    int fim;
    int tam;
}Fila;

void inicializar(Fila *f);

int enfileirar(Fila *f, int x);

int desenfileirar(Fila *f, int *aux);

int itsVazia(Fila *f);

int itsCheia(Fila *f);

int exibir(Fila *f);

Fila f;