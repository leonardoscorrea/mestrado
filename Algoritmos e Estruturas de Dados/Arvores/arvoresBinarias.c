#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvoresBinarias.h"

typedef struct dado
{
    int valor;
} Dado;

typedef struct arvore
{
    Dado dado;
    struct arvore *arvoreDireita;
    struct arvore *arvoreEsquerda;
} Arvore;

Arvore *criar()
{
    return NULL;
}

void imprimirArvore(Arvore *a, char *metodo)
{
    if (strcmp(metodo, "pre") == 0)
    {
        if (!arvoreVazia(a))
        {
            printf("%d ", a->dado.valor);
            imprimirArvore(a->arvoreEsquerda, metodo);
            imprimirArvore(a->arvoreDireita, metodo);
        }
    }
    else if (strcmp(metodo, "pos") == 0)
    {
        if (!arvoreVazia(a))
        {
            imprimirArvore(a->arvoreEsquerda, metodo);
            imprimirArvore(a->arvoreDireita, metodo);
            printf("%d ", a->dado.valor);
        }
    }
    else
    {
        if (!arvoreVazia(a))
        {
            imprimirArvore(a->arvoreEsquerda, metodo);
            printf("%d ", a->dado.valor);
            imprimirArvore(a->arvoreDireita, metodo);
        }
    }
}

int arvoreVazia(Arvore *a)
{
    return a == NULL;
}

void inserir(Arvore **a, int valor)
{
    if (*a == NULL)
    {
        *a = (Arvore *)malloc(sizeof(Arvore));
        (*a)->arvoreEsquerda = NULL;
        (*a)->arvoreDireita = NULL;
        (*a)->dado.valor = valor;
    }
    else
    {
        if (valor < (*a)->dado.valor)
        {
            inserir(&(*a)->arvoreEsquerda, valor);
        }
        if (valor > (*a)->dado.valor)
        {
            inserir(&(*a)->arvoreDireita, valor);
        }
    }
}

void apresentaArvore(Arvore *a, char *metodo)
{
    printf("Metodo %s\n", metodo);
    imprimirArvore(a, metodo);
    printf("\n");
}

int procurar(Arvore *a, int valor)
{

    if (arvoreVazia(a))
    {
        return 0;
    }

    return a->dado.valor == valor || procurar(a->arvoreEsquerda, valor) || procurar(a->arvoreDireita, valor);
}

Arvore *MaiorDireita(Arvore **a)
{
    if ((*a)->arvoreDireita != NULL)
        return MaiorDireita(&(*a)->arvoreDireita);
    else
    {
        Arvore *aux = *a;
        if ((*a)->arvoreEsquerda != NULL)
            *a = (*a)->arvoreEsquerda;
        else
            *a = NULL;
        return aux;
    }
}

Arvore *MenorEsquerda(Arvore **a)
{
    if ((*a)->arvoreEsquerda != NULL)
        return MenorEsquerda(&(*a)->arvoreEsquerda);
    else
    {
        Arvore *aux = *a;
        if ((*a)->arvoreDireita != NULL)
            *a = (*a)->arvoreDireita;
        else
            *a = NULL;
        return aux;
    }
}

void remover(Arvore **a, int valor)
{
    if (*a == NULL)
    {
        printf("Valor %d nao existe na arvore\n", valor);
        return;
    }
    if (valor < (*a)->dado.valor)
        remover(&(*a)->arvoreEsquerda, valor);
    else if (valor > (*a)->dado.valor)
        remover(&(*a)->arvoreDireita, valor);
    else
    {
        Arvore *pAux = *a;
        if (((*a)->arvoreEsquerda == NULL) && ((*a)->arvoreDireita == NULL))
        {
            free(pAux);
            (*a) = NULL;
        }
        else
        {
            if ((*a)->arvoreEsquerda == NULL)
            {
                (*a) = (*a)->arvoreDireita;
                pAux->arvoreDireita = NULL;
                free(pAux);
                pAux = NULL;
            }
            else
            {
                if ((*a)->arvoreDireita == NULL)
                {
                    (*a) = (*a)->arvoreEsquerda;
                    pAux->arvoreEsquerda = NULL;
                    free(pAux);
                    pAux = NULL;
                }
                else
                {
                    pAux = MaiorDireita(&(*a)->arvoreEsquerda);
                    pAux->arvoreEsquerda = (*a)->arvoreEsquerda;
                    pAux->arvoreDireita = (*a)->arvoreDireita;
                    (*a)->arvoreEsquerda = (*a)->arvoreDireita = NULL;
                    free((*a));
                    *a = pAux;
                    pAux = NULL;
                }
            }
        }
    }
}
