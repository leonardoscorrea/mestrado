typedef struct f Fila;
Fila *criaFila(unsigned capacidade);
int cheia(Fila *fila);
int vazia(Fila *fila);
void inserir(Fila *fila, int item);
int remover(Fila *fila);
int inicio(Fila *fila);
int fim(Fila *fila);
int imprimeFila(Fila *fila);