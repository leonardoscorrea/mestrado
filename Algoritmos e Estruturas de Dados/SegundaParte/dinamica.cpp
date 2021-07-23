#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <time.h>
#include "dinamica.hpp"

using namespace std;

typedef struct linha
{
    std::vector<int> valores;
} Linha;

typedef struct matriz
{
    std::vector<Linha> linhas;
} Matriz;

Linha vetor;
int tamanhoVetor = 0;

void imprimeVetor()
{
    for (int i = 0; i < tamanhoVetor; i++)
        cout << vetor.valores[i] << " ";
    cout << "\n";
}

void criaVetor()
{
    vetor.valores.erase(vetor.valores.begin(), vetor.valores.begin() + tamanhoVetor);
    tamanhoVetor = 0;
}

void criaVetorPredefinido(int tamanho, int tipo, int chaveAleatoriedade)
{
    vetor.valores.erase(vetor.valores.begin(), vetor.valores.begin() + tamanhoVetor);
    tamanhoVetor = tamanho;
    if (tipo == 0) //vetor ordenado
    {
        for (int i = 0; i < tamanho; i++)
            vetor.valores.push_back(i);
    }
    else if (tipo == 1) //vetor decrescente
    {
        int valor = tamanho;
        for (int i = 0; i < tamanho; i++)
            vetor.valores.push_back(valor--);
    }
    else // aleatório
    {
        srand(time(NULL));
        for (int i = 0; i < tamanho; i++)
            vetor.valores.push_back(rand() % chaveAleatoriedade);
    }
}

void adicionaValorVetor(int valor)
{
    vetor.valores.push_back(valor);
    tamanhoVetor++;
}

int corteHastes(int valor)
{
    if (valor <= 0)
        return 0;
    int maximo = 0;
    for (int i = 0; i < valor; i++)
    {
        maximo = std::max(maximo, vetor.valores[i] + corteHastes(valor - i - 1));
    }
    return maximo;
}

int corteButtomUp(int valor)
{
    std::vector<int> aux;
    aux.push_back(0);
    for (int i = 1; i <= valor; i++)
    {
        int x = -1;
        for (int j = 1; j <= i; j++)
        {
            x = std::max(x, vetor.valores[j] + aux[i - j]);
        }
        aux.push_back(x);
    }
    return aux[valor];
}