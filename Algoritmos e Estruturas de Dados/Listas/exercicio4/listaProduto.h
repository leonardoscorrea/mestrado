typedef struct lista ListaProduto;
void inicializarLista(ListaProduto **l);
void imprimeLista(ListaProduto *l, int inicio, int fim);
void inserir(ListaProduto **l, int cod, char nome[40], float preco, int indice, int inicio, int fim);
void consultaProduto(ListaProduto *l, int cod, int inicio, int fim);