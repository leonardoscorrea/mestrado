typedef struct lista Lista;
void inicializarLista(Lista **l);
void imprimeLista(Lista *l);
void inserirInicio(Lista **l, int valor);
void inserirFim(Lista *l, int valor);
void inserir(Lista *l, int chave, int valor);
void inserirAposValor(Lista **l, int valorProcurar, int valorInserir);
void atualizar(Lista *l, int chave, int valor);
void deletar(Lista *l, int chave);
int buscarValor(Lista *l, int valor);
