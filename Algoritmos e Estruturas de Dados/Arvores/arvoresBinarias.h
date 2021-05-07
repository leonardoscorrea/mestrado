typedef struct arvore Arvore;
typedef struct dado Dado;
Arvore *criar();
void apresentaArvore(Arvore *a, char *metodo);
int arvoreVazia(Arvore *a);
void inserir(Arvore **a, int valor);
int procurar(Arvore *a, int valor);
void remover(Arvore **a, int valor);