#include <stdlib.h>
#include <stdio.h>
#include "filaInteiros.h"

int main()
{
    Fila *f;
    int valor;
    inicializarFila(&f, 10);
    inserir(&f, 10);
    inserir(&f, 5);
    inserir(&f, 4);
    inserir(&f, 3);
    remover(&f, &valor);
    imprimeFila(f);
    printf("topo: %d\n", verificaValorTopo(f));
    return 0;
}