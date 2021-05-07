typedef struct fila Fila;
void inicializarFila(Fila **f, int tamanho);
void imprimeFila(Fila *f);
void inserir(Fila **f, int valor);
int remover(Fila **f, int *valor);
int verificaValorTopo(Fila *f);
int filaVazia(Fila *f);
int filaCheia(Fila *f);
void removeMaiorTopo(Fila **f1, Fila **f2);
