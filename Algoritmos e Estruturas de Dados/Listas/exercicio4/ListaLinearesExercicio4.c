#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaProduto.h"

int main()
{
    ListaProduto *l;
    inicializarLista(&l);
    imprimeLista(l, 0, 10);
    inserir(&l, 2, "Teste", 100.0, 1, 0, 10);
    inserir(&l, 10, "Teste 2", 300.0, 1, 5, 10);
    imprimeLista(l, 0, 10);
    consultaProduto(l, 10, 0, 10);
    consultaProduto(l, 10, 4, 10);
    return 0;
}