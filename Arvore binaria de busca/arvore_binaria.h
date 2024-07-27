typedef struct Node{
    int chave;
    struct Node* esquerda;
    struct Node* direita;
    struct Node* pai;
}Node;

Node* getNode();

Node* inserir(Node* raiz, int chave);

Node* buscar_chave(Node* raiz, int chave);

Node* remover(Node* raiz, int chave);

void pre_ordem(Node* raiz);

void em_ordem(Node* raiz);

void pos_ordem(Node* raiz);

Node* predecessor(Node* n);

Node* sucessor(Node* n);

Node* maximo(Node* raiz);

Node* minimo(Node* raiz);