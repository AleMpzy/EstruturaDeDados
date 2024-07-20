struct Nodo{
    int info;
    struct Nodo* pai;
    struct Nodo* esquerda;
    struct Nodo* direita;
};

typedef struct Nodo* No;