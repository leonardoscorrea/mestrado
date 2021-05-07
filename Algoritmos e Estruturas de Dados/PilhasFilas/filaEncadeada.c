#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "filaEncadeada.h"

typedef struct elementoFila
{
    int valor;
    struct elementoFila *seguinte;
} elemento;

typedef struct fila
{
    elemento *inicio;
    elemento *fim;
    int tamanho;
} Fila;

void inicializarFila(Fila **f)
{
    (*f)->inicio = NULL;
    (*f)->fim = NULL;
    (*f)->tamanho = 0;
}
void imprimeFila(Fila **f)
{
    elemento *proximo;
    printf("%d ", (*f)->inicio->valor);
    proximo = (*f)->inicio->seguinte;
    while (proximo->seguinte != NULL)
    {
        printf("%d ", proximo->valor);
        proximo = proximo->seguinte;
    }

    //if (!filaVazia(f))
    //{
    /*for (int i = f->inicio; i <= f->fim; i++)
    {
        printf("%d ", f->valor[i]);
    }
    printf("\n");*/
    //}
}
void inserir(Fila **f, int valor)
{
    if ((*f)->tamanho == 0)
    {
        (*f)->inicio = (elemento *)malloc(sizeof(elemento));
        (*f)->inicio->valor = valor;
        (*f)->fim = (*f)->inicio;
        (*f)->tamanho++;
    }
    else
    {
        (*f)->fim->seguinte = (elemento *)malloc(sizeof(elemento));
        (*f)->fim->seguinte->valor = valor;
        (*f)->fim->seguinte->seguinte = NULL;
        (*f)->fim = (*f)->fim->seguinte;
        (*f)->tamanho++;
    }
}

int remover(Fila *f)
{
    int valor;
    elemento *aux;

    valor = -1;

    if (f->tamanho == 0)
    {
        printf("Fila vazia!\n");
        return -1;
    }
    else
    {
        valor = f->inicio->valor;
        aux = f->inicio;
        f->inicio = f->inicio->seguinte;
        free(aux);
        f->tamanho--;
        return valor;
    }
    return -1;
}

int verificaValorTopo(Fila *f)
{
    return 0; //f->dados[f->inicio];
}

int filaVazia(Fila *f)
{
    return 0; //(f->fim < f->inicio);
}

int filaCheia(Fila *f)
{
    return 0; //(f->nroItens == f->tamanho);
}

void removeMaiorTopo(Fila **f1, Fila **f2)
{
    /*int valor;
    if (verificaValorTopo(*f1) > verificaValorTopo(*f2))
    {
        remover(f1, &valor);
    }
    else
    {
        remover(f2, &valor);
    }*/
}