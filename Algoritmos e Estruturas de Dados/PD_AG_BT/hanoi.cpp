#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <time.h>

/*
QUADRADO PERFEITO
A definição de um número quadrado perfeito pode ser entendida como: 
um número natural inteiro positivo cuja raiz quadrada é, também, um número natural inteiro positivo.
*/

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0
#define TAMANHO 5

using namespace std;
vector<int> bolasPorVaretas;
int quantidadeBolasTotal, totalVaretas;

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

void CalculaQuantidadeBolas(int numeroBola, int vareta)
{
    if (vareta >= totalVaretas)
        return;
    //se a vareta não tem nenhuma bola, coloca a bola na vareta
    if (bolasPorVaretas[vareta] == 0)
    {
        bolasPorVaretas[vareta] = numeroBola;
        quantidadeBolasTotal++;
        return CalculaQuantidadeBolas(numeroBola + 1, vareta);
    }
    for (int i = 0; i <= vareta; i++)
    {
        //faz raiz quadrada pra ver se a bola que está na vareta somada com a nova bola é um quadrado perfeito
        int raiz = (int)sqrt(bolasPorVaretas[i] + numeroBola);
        //se for um quadrado perfeito coloca a bola na vareta
        if (pow(raiz, 2) == bolasPorVaretas[i] + numeroBola)
        {
            bolasPorVaretas[i] = numeroBola;
            quantidadeBolasTotal++;
            return CalculaQuantidadeBolas(numeroBola + 1, vareta);
        }
    }
    //procura uma vareta vazia ou que forme um quadrado perfeito com a bola em questão
    CalculaQuantidadeBolas(numeroBola, vareta + 1);
}

int getInput()
{
    int number, numeroVaretas;
    string line, line2;
    string suit;
    int menordistancia = 0;
    identifiers("[NUMERO TESTES]: ");
    if (std::getline(std::cin, line))
    {
        std::istringstream stream(line);
        stream >> number;
        if (number <= 0)
            return -1;

        identifiers("[NUMERO DE VARETAS]: ");

        //for (int i = 1; i <= number; i++)
        int i = 0;
        while (std::getline(std::cin, line2) && i < number)
        {
            i++;
            std::istringstream stream2(line2);
            stream2 >> numeroVaretas;
            //cout << "aqui: " << numeroVaretas << "\n";
            quantidadeBolasTotal = 0;
            bolasPorVaretas.erase(bolasPorVaretas.begin(), bolasPorVaretas.end());
            for (int i; i < numeroVaretas; i++)
            {
                bolasPorVaretas.push_back(0);
            }
            totalVaretas = numeroVaretas;
            CalculaQuantidadeBolas(1, 0);
            cout << quantidadeBolasTotal << "\n";
        }
    }
    return 1;
}

int main()
{
    getInput();
    return 0;
}