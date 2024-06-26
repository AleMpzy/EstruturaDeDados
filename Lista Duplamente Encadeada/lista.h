typedef struct NoTag{
    int chave;
    struct NoTag *prox;
    struct NoTag *ant;
} no;

typedef struct{
    no *comeco;
} L;

void IniciarLista(no **L);

int RetornarTamanho(no **L);

void ImprimirLista(no **L);

void InserirFinal(no **L, int chave);

void InserirInicio(no **L, int chave);

void RemoverFinal(no **L);

void RemoverInicio(no **L);

void RemoverChave(no **L, int chave);

void BuscarChave(no **L, int chave);

void ReiniciarLista(no **L);