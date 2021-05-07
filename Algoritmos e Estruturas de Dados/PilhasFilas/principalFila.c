#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int comparaElementoInicio(Fila *fila1, Fila *fila2)
{
    printf("Inicio fila 1: %d | inicio fila 2: %d\n", inicio(fila1), inicio(fila2));
    if (inicio(fila1) > inicio(fila2))
    {
        printf("IMPRIMINDO FILA 1\n");
        imprimeFila(fila1);
        printf("%d removido da fila 1\n", remover(fila1));
        imprimeFila(fila1);
    }
    else
    {
        printf("IMPRIMINDO FILA 2\n");
        imprimeFila(fila2);
        printf("%d removido da fila 2\n", remover(fila2));
        imprimeFila(fila2);
    }
}

int separaParImpar(Fila *f, Fila *F_Pares, Fila *F_Impares)
{
    printf("\n");
    printf("IMPRIMINDO FILA\n");
    imprimeFila(f);
    int valor;
    for (int i = inicio(f); i <= fim(f); i++)
    {
        valor = remover(f);
        if ((valor % 2) == 0)
        {
            inserir(F_Pares, valor);
        }
        else
        {
            inserir(F_Impares, valor);
        }
    }
    printf("IMPRIMINDO FILA PARES\n");
    imprimeFila(F_Pares);
    printf("IMPRIMINDO FILA IMPARES\n");
    imprimeFila(F_Impares);
    printf("\n");
}

int main()
{
    Fila *f1 = criaFila(1000);
    Fila *f2 = criaFila(1000);
    Fila *F_Pares = criaFila(1000);
    Fila *F_Impares = criaFila(1000);

    inserir(f1, 7);
    inserir(f1, 10);
    inserir(f1, 20);
    inserir(f1, 30);
    inserir(f1, 33);
    inserir(f1, 31);
    inserir(f1, 40);

    inserir(f2, 5);
    inserir(f2, 6);

    printf("\n");
    printf("IMPRIMINDO FILA 1\n");
    imprimeFila(f1);
    printf("IMPRIMINDO FILA 2\n");
    imprimeFila(f2);
    printf("\n");

    comparaElementoInicio(f1, f2);
    separaParImpar(f1, F_Pares, F_Impares);

    return 0;
}