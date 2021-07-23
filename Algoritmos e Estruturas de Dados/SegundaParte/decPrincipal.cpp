#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
#include "dec.hpp"

using namespace std;

int main()
{

    criaVetor();
    adicionaValorVetor(2);
    adicionaValorVetor(3);
    adicionaValorVetor(5);
    adicionaValorVetor(7);
    adicionaValorVetor(10);
    adicionaValorVetor(15);
    imprimeVetor();
    cout << "indice de uma busca simples pelo valor 3 em um vetor: " << buscaSimples(3) << "\n";
    cout << "indice de uma busca binária pelo valor 3 em um vetor: " << buscaBinaria(3) << "\n";
    cout << "busca valor proximo a um número (9 no exemplo): " << buscaProximo(9) << "\n";
    clock_t begin_time = clock();
    criaVetor();
    for (int i = 0; i < pow(10, 9); i++)
    {
        adicionaValorVetor(i);
    }
    std::cout << "Tempo de execucao para criacao do vetor 10^9: " << float(clock() - begin_time) / CLOCKS_PER_SEC << "s\n";
    begin_time = clock();
    cout << "indice de uma busca binária pelo valor 10^3 em um vetor: " << buscaBinaria(pow(10, 3)) << "\n";
    std::cout << "Tempo de execucao para busca binaria no vetor 10^9 pelo valor 10^3: " << float(clock() - begin_time) / CLOCKS_PER_SEC << "s\n";
    begin_time = clock();
    cout << "indice de uma busca simples pelo valor 10^3 em um vetor: " << buscaSimples(pow(10, 3)) << "\n";
    std::cout << "Tempo de execucao para busca simes no vetor 10^9 pelo valor 10^3: " << float(clock() - begin_time) / CLOCKS_PER_SEC << "s\n";
    return 0;
}