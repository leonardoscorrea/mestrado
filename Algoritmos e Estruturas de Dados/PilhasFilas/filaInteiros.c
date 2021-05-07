#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "filaInteiros.h"

typedef struct fila
{
    int tamanho;
    int *dados;
    int inicio;
    int fim;
} Fila;

void inicializarFila(Fila **f, int tamanho)
{
    (*f)->tamanho = tamanho;
    (*f)->dados = (int *)malloc((*f)->tamanho * sizeof(int));
    (*f)->inicio = 0;
    (*f)->fim = -1;
}
void imprimeFila(Fila *f)
{
    //if (!filaVazia(f))
    //{
    for (int i = f->inicio; i <= f->fim; i++)
    {
        printf("%d ", f->dados[i]);
    }
    printf("\n");
    //}
}
void inserir(Fila **f, int valor)
{
    //if (!filaCheia(*f))
    //{
    if ((*f)->fim == (*f)->tamanho)
        (*f)->fim = -1;
    (*f)->fim++;
    (*f)->dados[(*f)->fim] = valor;
    //}
}

int remover(Fila **f, int *valor)
{
    //if (!filaVazia(*f))
    //{
    *valor = (*f)->dados[(*f)->inicio++];
    if ((*f)->inicio == (*f)->tamanho)
        (*f)->inicio = 0;
    return 0;
    //}
    //return 0;
}

int verificaValorTopo(Fila *f)
{
    return f->dados[f->inicio];
}

int filaVazia(Fila *f)
{
    return (f->fim < f->inicio);
}

int filaCheia(Fila *f)
{
    return 0; //(f->nroItens == f->tamanho);
}

void removeMaiorTopo(Fila **f1, Fila **f2)
{
    int valor;
    if (verificaValorTopo(*f1) > verificaValorTopo(*f2))
    {
        remover(f1, &valor);
    }
    else
    {
        remover(f2, &valor);
    }
}