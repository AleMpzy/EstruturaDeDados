#define MAX 100

typedef int TipoChave;

typedef struct{
    TipoChave chave;
}TipoItem;

typedef struct{
    TipoItem Item[MAX];
    int Topo;
}Pilha;

void inicializar(Pilha *p);

int itsVazia(Pilha p);

int push(TipoItem x, Pilha *p);

int pop(Pilha *p, TipoItem *Item);

int tamanho(Pilha p);

int imprimir(Pilha p);

Pilha p;