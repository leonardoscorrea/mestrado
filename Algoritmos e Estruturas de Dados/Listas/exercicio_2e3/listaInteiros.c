#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "listaInteiros.h"

#define TAMANHO 100

typedef struct registro
{
    int valor;
} registro;

typedef struct lista
{
    registro registros[TAMANHO];
    int inicio;
    int fim;
} Lista;

void inicializarLista(Lista **l)
{
    *l = (Lista*) malloc(sizeof(Lista));
    (*l)->fim = -1;
    (*l)->inicio = 0;
}

void imprimeLista(Lista *l){
    for(int i = 0; i <= l->fim; i++){
        printf("%d ",l->registros[i].valor);
    }
    printf("\n");
}

void inserirInicio(Lista **l, int valor)
{
    registro* r = (registro*) malloc(sizeof(registro));
    r->valor = valor;
    if((*l)->fim < 0){
        (*l)->fim = 0;
    } else {
        for(int i = (*l)->fim; i >= (*l)->inicio; i--){
            (*l)->registros[i+1] = (*l)->registros[i];
        }
        (*l)->fim++;
    }
    (*l)->registros[(*l)->inicio] = *r;

}
void inserirFim(Lista *l, int valor)
{
}
void inserir(Lista *l, int chave, int valor)
{
}

void inserirAposValor(Lista **l, int valorProcurar, int valorInserir){
    int indice = buscarValor((*l),valorProcurar);
    if(indice > 0){
        for(int i = (*l)->fim; i > indice; i--){
            (*l)->registros[i+1] = (*l)->registros[i];
        }
        (*l)->fim++;
        registro* r = (registro*) malloc(sizeof(registro));
        r->valor = valorInserir;
        (*l)->registros[indice+1] = *r;
    }
}

void atualizar(Lista *l, int chave, int valor)
{
}
void deletar(Lista *l, int chave)
{
}

int buscarValor(Lista *l, int valor){
    for(int i = 0; i <= l->fim; i++){
        if(l->registros[i].valor == valor){
            return i;
        }
    }
    return -1;
}