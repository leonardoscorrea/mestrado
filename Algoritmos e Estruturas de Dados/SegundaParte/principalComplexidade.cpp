#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
#include "complexidade.hpp"

using namespace std;

int main()
{
    int soma = somaElementosAcimaDiagonalPrincipal(4, 65);
    cout << "valor da soma: " << soma << "\n";
    criaVetor();
    adicionaValorVetor(5);
    adicionaValorVetor(6);
    adicionaValorVetor(3);
    cout << "Tempo de ordenação em vetor aleatório 3 registros: ";
    ordenaVetor();
    criaVetorPredefinido(10000, 0, 50000);
    cout << "Tempo de ordenação em vetor ordenado: ";
    ordenaVetor();
    criaVetorPredefinido(10000, 1, 50000);
    cout << "Tempo de ordenação em vetor decrescente: ";
    ordenaVetor();
    criaVetorPredefinido(10000, 2, 50000);
    cout << "Tempo de ordenação em vetor aleatório: ";
    ordenaVetor();
    criaVetor();
    adicionaValorVetor(5);
    adicionaValorVetor(6);
    adicionaValorVetor(3);
    cout << "Tempo de ordenação por inserção em vetor aleatório 3 registros: ";
    ordenaVetorInsercao();
    criaVetorPredefinido(100, 0, 50000);
    cout << "Tempo de ordenação por inserção em vetor ordenado(100): ";
    ordenaVetorInsercao();
    criaVetorPredefinido(100, 1, 50000);
    cout << "Tempo de ordenação por inserção em vetor decrescente(100): ";
    ordenaVetorInsercao();
    criaVetorPredefinido(100, 2, 50000);
    cout << "Tempo de ordenação por inserção em vetor aleatório(100): ";
    ordenaVetorInsercao();
    criaVetorPredefinido(1000, 0, 50000);
    cout << "Tempo de ordenação por inserção em vetor ordenado(1000): ";
    ordenaVetorInsercao();
    criaVetorPredefinido(1000, 1, 50000);
    cout << "Tempo de ordenação por inserção em vetor decrescente(1000): ";
    ordenaVetorInsercao();
    criaVetorPredefinido(1000, 2, 50000);
    cout << "Tempo de ordenação por inserção em vetor aleatório(1000): ";
    ordenaVetorInsercao();
    criaVetorPredefinido(10000, 0, 50000);
    cout << "Tempo de ordenação por inserção em vetor ordenado(10.000): ";
    ordenaVetorInsercao();
    criaVetorPredefinido(10000, 1, 50000);
    cout << "Tempo de ordenação por inserção em vetor decrescente(10.000): ";
    ordenaVetorInsercao();
    criaVetorPredefinido(10000, 2, 50000);
    cout << "Tempo de ordenação por inserção em vetor aleatório(10.000): ";
    ordenaVetorInsercao();
    criaVetorPredefinido(50000, 0, 50000);
    cout << "Tempo de ordenação por inserção em vetor ordenado(50.000): ";
    ordenaVetorInsercao();
    criaVetorPredefinido(50000, 1, 50000);
    cout << "Tempo de ordenação por inserção em vetor decrescente(50.000): ";
    ordenaVetorInsercao();
    criaVetorPredefinido(50000, 2, 50000);
    cout << "Tempo de ordenação por inserção em vetor aleatório(50.000): ";
    ordenaVetorInsercao();
    return 0;
}