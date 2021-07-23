#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <time.h>
#include "complexidade.hpp"

using namespace std;

typedef struct linha
{
    std::vector<int> valores;
} Linha;

typedef struct matriz
{
    std::vector<Linha> linhas;
} Matriz;

int somaValoresMatriz(Matriz m, int tamanhoMatriz)
{
    int soma = 0;
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            soma += m.linhas[i].valores[j];
    return soma;
}

void imprimeMatriz(Matriz m, int tamanhoMatriz)
{
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        for (int j = 0; j < tamanhoMatriz; j++)
            cout << m.linhas[i].valores[j] << " ";
        cout << "\n";
    }
}

int somaElementosAcimaDiagonalPrincipal(int tamanhoMatriz, int chaveAleatoriedade)
{
    Matriz m;
    srand(time(NULL));
    for (int i = 0; i < tamanhoMatriz; i++)
    {
        Linha l;
        for (int j = 0; j < tamanhoMatriz; j++)
            l.valores.push_back(rand() % chaveAleatoriedade);
        m.linhas.push_back(l);
    }
    imprimeMatriz(m, tamanhoMatriz);
    return somaValoresMatriz(m, tamanhoMatriz);
}

Linha vetor;
int tamanhoVetor = 0;

int buscaSimples(int valor)
{
    for (int i = 0; i < tamanhoVetor; i++)
    {
        if (vetor.valores[i] == valor)
        {
            return i;
        }
    }
    return -1;
}

int buscaBinariaRecursiva(int inicio, int fim, int num)
{
    if (inicio <= fim)
    {
        int mid = (inicio + fim) / 2;
        if (vetor.valores[mid] == num)
            return mid;
        if (vetor.valores[mid] > num)
            return buscaBinariaRecursiva(inicio, mid - 1, num);
        if (vetor.valores[mid] < num)
            return buscaBinariaRecursiva(mid + 1, fim, num);
    }
    return -1;
}

int buscaBinaria(int valor)
{
    return buscaBinariaRecursiva(0, vetor.valores.size() - 1, valor);
}

int buscaProximo(int valor)
{
    for (int i = 0; i < tamanhoVetor; i++)
    {
        if (vetor.valores[i] == valor)
        {
            return vetor.valores[i];
        }
        else if (vetor.valores[i] > valor)
        {
            if (i == tamanhoVetor - 1)
            {
                return vetor.valores[i];
            }
            else if (abs(vetor.valores[i - 1] - valor) < abs(vetor.valores[i] - valor))
            {
                return vetor.valores[i - 1];
            }
            else
            {
                return vetor.valores[i];
            }
        }
    }
    return -1;
}

void imprimeVetor()
{
    for (int i = 0; i < tamanhoVetor; i++)
        cout << vetor.valores[i] << " ";
    cout << "\n";
}

void bubble()
{
    int troca = 1, i = 0;
    while ((i < tamanhoVetor) && (troca))
    {
        troca = 0;
        for (int j = i + 1; j < tamanhoVetor; j++)
        {
            if (vetor.valores[j] < vetor.valores[i])
            {
                troca = 1;
                int valor = vetor.valores[i];
                vetor.valores[i] = vetor.valores[j];
                vetor.valores[j] = valor;
            }
        }
        i++;
    }
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

void ordenaVetor()
{
    if (tamanhoVetor > 0)
    {
        const clock_t begin_time = clock();
        //imprimeVetor();
        bubble();
        //imprimeVetor();
        //std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
        std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << "s\n";
    }
}

void ordenaPorInsercao()
{
    int j, valor;
    for (int i = 1; i < tamanhoVetor; i++)
    {
        valor = vetor.valores[i];
        j = i - 1;
        while (j >= 0 && vetor.valores[j] > valor)
        {
            vetor.valores[j + 1] = vetor.valores[j];
            j--;
        }
        vetor.valores[j + 1] = valor;
    }
}

void ordenaVetorInsercao()
{
    if (tamanhoVetor > 0)
    {
        const clock_t begin_time = clock();
        //imprimeVetor();
        ordenaPorInsercao();
        //imprimeVetor();
        //std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC;
        std::cout << float(clock() - begin_time) / CLOCKS_PER_SEC << "s\n";
    }
}
