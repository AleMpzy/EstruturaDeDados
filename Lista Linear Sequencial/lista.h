#define max 30
#define inv -1
#define val 0

typedef int TipoChave;

typedef struct {
    TipoChave chave;
} Registro;

typedef struct {
    Registro V[max];
    int N;
} Lista;

void Iniciar(Lista *L);

int RetornarNumElementos(Lista *L);

void Imprimir(Lista *L);

int BuscarElemento(Lista *L, TipoChave *ch);

int InserirComeco(Lista *L, Registro *R);

int InserirFinal(Lista *L, Registro *R);

int InserirPosicao(Lista *L, Registro *R, int i);

int ExcluirElemento(Lista *L, TipoChave *ch);

void ReniciarLista(Lista *L);