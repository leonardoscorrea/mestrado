#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

void ordenaPorRegra(int *vetor)
{
    int conta1 = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if (vetor[i] == 1)
            conta1++;
    }

    for (int i = 0; i < tamanho; i++)
    {
        if (i < conta1)
            vetor[i] = 1;
        else
            vetor[i] = 2;
    }
}

int main()
{
    int vetor[tamanho];
    vetor[0] = 1;
    vetor[1] = 2;
    vetor[2] = 2;
    vetor[3] = 1;
    vetor[4] = 1;

    ordenaPorRegra(vetor);
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}