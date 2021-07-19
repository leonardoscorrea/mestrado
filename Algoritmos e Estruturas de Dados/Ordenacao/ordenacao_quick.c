#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

void quick_sort(int *vetor, int inicio, int fim)
{
    int i, j, pivot, y;

    i = inicio;
    j = fim;
    /*cuidar a forma de escolher o pivot, pois dependendo da forma pode tornar o algorítmo n^2*/
    //pivot = vetor[(inicio + fim) / 2]; //pivot central
    //pivot = vetor[fim - 1]; // pivot final
    pivot = vetor[inicio]; //pivot inicial

    while (i <= j)
    {
        while (vetor[i] < pivot && i < fim)
        {
            i++;
        }
        while (vetor[j] > pivot && j > inicio)
        {
            j--;
        }
        if (i <= j)
        {
            y = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = y;
            i++;
            j--;
        }
    }

    if (j > inicio)
    { //esquerda do pivot
        quick_sort(vetor, inicio, j);
    }
    if (i < fim)
    { //direita do pivot
        quick_sort(vetor, i, fim);
    }
}

int main()
{
    int vetor[tamanho];
    vetor[0] = 3;
    vetor[1] = 1;
    vetor[2] = 5;
    vetor[3] = 9;
    vetor[4] = 7;

    quick_sort(vetor, 0, tamanho);
    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    return 0;
}