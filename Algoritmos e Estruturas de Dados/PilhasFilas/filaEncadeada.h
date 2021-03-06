typedef struct fila Fila;
typedef struct elementoFila elemento;
void inicializarFila(Fila **f);
void imprimeFila(Fila **f);
void inserir(Fila **f, int valor);
int remover(Fila *f);
int verificaValorTopo(Fila *f);
int filaVazia(Fila *f);
int filaCheia(Fila *f);
void removeMaiorTopo(Fila **f1, Fila **f2);
