#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct f
{
    int inicio, fim, tamanho;
    unsigned capacidade;
    int *dados;
} Fila;

Fila *criaFila(unsigned capacidade)
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->capacidade = capacidade;
    fila->inicio = fila->tamanho = 0;

    fila->fim = capacidade - 1;
    fila->dados = (int *)malloc(fila->capacidade * sizeof(int));
    return fila;
}

int cheia(Fila *fila)
{
    return (fila->tamanho == fila->capacidade);
}

int vazia(Fila *fila)
{
    return (fila->tamanho == 0);
}

void inserir(Fila *fila, int item)
{
    if (cheia(fila))
        return;
    fila->fim = (fila->fim + 1) % fila->capacidade;
    fila->dados[fila->fim] = item;
    fila->tamanho = fila->tamanho + 1;
    //printf("%d inserido na fila\n", item);
}

int remover(Fila *fila)
{
    if (vazia(fila))
        return INT_MIN;
    int item = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % fila->capacidade;
    fila->tamanho = fila->tamanho - 1;
    return item;
}

int inicio(Fila *fila)
{
    if (vazia(fila))
        return INT_MIN;
    return fila->dados[fila->inicio];
}

int fim(Fila *fila)
{
    if (vazia(fila))
        return INT_MIN;
    return fila->dados[fila->fim];
}

int imprimeFila(Fila *fila)
{
    if (fila->tamanho > 0)
    {
        for (int i = fila->inicio; i <= fila->fim; i++)
        {
            printf("%d ", fila->dados[i]);
        }
        printf("\n");
    }
}