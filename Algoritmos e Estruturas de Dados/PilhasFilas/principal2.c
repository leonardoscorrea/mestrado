#include <stdlib.h>
#include <stdio.h>
#include "filaEncadeada.h"

int main()
{
    Fila *f;
    Fila *f2;
    int valor;
    inicializarFila(&f);
    inserir(&f, 16);
    inserir(&f, 14);
    inserir(&f, 12);
    imprimeFila(&f);
    //inicializarFila(&f2);

    return 0;
}