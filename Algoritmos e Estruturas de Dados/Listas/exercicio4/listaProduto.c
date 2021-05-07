#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include "listaProduto.h"

#define TAMANHO 10

typedef struct SProduto
{
    int cod;
    char nome[40];
    float preco;
} Produto;

typedef struct lista
{
    Produto produtos[TAMANHO];
    int inicio;
    int fim;
} ListaProduto;

void inicializarLista(ListaProduto **l)
{
    *l = (ListaProduto *)malloc(sizeof(ListaProduto));
    for (int i = 0; i < TAMANHO; i++)
    {
        inserir(l, 0, "", 0.0, i, 0, TAMANHO);
    }
    (*l)->fim = -1;
    (*l)->inicio = 0;
}

void imprimeLista(ListaProduto *l, int inicio, int fim)
{
    if (fim > TAMANHO)
        fim = TAMANHO;
    for (int i = inicio; i < fim; i++)
    {
        printf("(i:%d,cod:%d,nome:%s) ", i, l->produtos[i].cod, l->produtos[i].nome);
    }
    printf("\n");
}

void inserir(ListaProduto **l, int cod, char nome[40], float preco, int indice, int inicio, int fim)
{
    if ((indice + inicio) <= fim)
    {
        Produto *p = (Produto *)malloc(sizeof(Produto));
        strcpy(p->nome, nome);
        p->cod = cod;
        p->preco = preco;
        (*l)->produtos[indice + inicio] = *p;
    }
}

void consultaProduto(ListaProduto *l, int cod, int inicio, int fim)
{
    int contador = 0;
    if (fim > TAMANHO)
        fim = TAMANHO;
    for (int i = inicio; i < fim; i++)
    {
        if (l->produtos[i].cod == cod)
        {
            printf("PRODUTO \n Posicao relativa: (%d)\n Posicao absoluta: (%d)\n codigo:%d \n nome:%s \n preco:%.2f \n", contador, i, l->produtos[i].cod, l->produtos[i].nome, l->produtos[i].preco);
            break;
        }
        contador++;
    }
    printf("\n");
}