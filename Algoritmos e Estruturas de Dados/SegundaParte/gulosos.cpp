#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <time.h>
#include "gulosos.hpp"

using namespace std;

typedef struct item
{
    int valor;
    int peso;
} Item;

typedef struct linha
{
    std::vector<Item> valores;
} Linha;

Linha vetor;
int tamanhoVetor = 0;

void imprimeVetor()
{
    for (int i = 0; i < tamanhoVetor; i++)
        cout << vetor.valores[i].valor << " ";
    cout << "\n";
}

void criaVetor()
{
    vetor.valores.erase(vetor.valores.begin(), vetor.valores.begin() + tamanhoVetor);
    tamanhoVetor = 0;
}

void adicionaValorVetor(int valor, int peso)
{
    Item i;
    i.valor = valor;
    i.peso = peso;
    vetor.valores.push_back(i);
    tamanhoVetor++;
}

bool regraOrdenacao(Item i1, Item i2)
{
    double racional1 = (double)i1.valor / i1.peso;
    double racional2 = (double)i2.valor / i2.peso;
    return racional1 > racional2;
}

double mochilaFracionaria(int valor, int tamanho)
{
    sort(vetor.valores.begin(), vetor.valores.end(), regraOrdenacao);
    int pesoAux = 0;
    double valorFinal = 0.0;
    for (int i = 0; i < tamanho; i++)
    {
        if (pesoAux + vetor.valores[i].peso <= valor)
        {
            pesoAux += vetor.valores[i].peso;
            valorFinal += vetor.valores[i].valor;
        }
        else
        {
            int aux = valor - pesoAux;
            valorFinal += vetor.valores[i].valor * ((double)aux / vetor.valores[i].peso);
            break;
        }
    }
    return valorFinal;
}