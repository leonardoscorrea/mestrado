#include <stdlib.h>
#include <stdio.h>
#include "arvoresBinarias.h"

int main()
{
    Arvore *a = criar();

    inserir(&a, 10);
    inserir(&a, 12);
    inserir(&a, 5);
    inserir(&a, 4);
    inserir(&a, 6);
    inserir(&a, 11);
    apresentaArvore(a, "pre");
    apresentaArvore(a, "pos");
    apresentaArvore(a, "central");

    int valorRemover = 12;
    printf("Removendo valor %d\n", valorRemover);
    remover(&a, valorRemover);

    apresentaArvore(a, "pre");

    return 0;
}
