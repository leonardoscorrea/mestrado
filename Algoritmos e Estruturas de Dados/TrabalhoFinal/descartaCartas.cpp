#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0

using namespace std;

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

void valida(int qtd)
{
    vector<int> pilha;
    vector<int> descarte;
    int count = 0;
    int ponteiro = 0;
    for (int i = 1; i <= qtd; i++)
    {
        pilha.push_back(i);
    }

    for (int i = 1; i < qtd; i++)
    {
        descarte.push_back(pilha[ponteiro++]);
        pilha[ponteiro - 1] = -1;
        if (ponteiro >= qtd)
            ponteiro = 0;

        if (pilha[ponteiro] == -1)
        {
            while (pilha[ponteiro] == -1)
            {
                ponteiro++;
                if (ponteiro >= qtd)
                    ponteiro = 0;
            }
        }

        ponteiro++;

        if (ponteiro >= qtd)
            ponteiro = 0;

        while (pilha[ponteiro] == -1)
        {
            ponteiro++;
            if (ponteiro >= qtd)
                ponteiro = 0;
        }
    }

    cout << "Discarded cards: ";
    for (int i = 0; i < qtd - 1; i++)
    {
        cout << descarte[i] << ((i != qtd - 2) ? ", " : "\n");
    }

    cout << "Remaining card: " << pilha[ponteiro] << "\n";

    pilha.erase(pilha.begin(), pilha.begin() + qtd);
}

int getInput()
{
    int number;
    string line;
    string suit;
    int count = 0;

    identifiers("[Quantidade de Jogadas]: ");
    std::getline(std::cin, line);
    std::istringstream stream(line);
    if (stream >> number)
    {
        if (number == 0)
            return 0;
        valida(number);
    }
    else
        return 0;

    return 1;
}

int main()
{

    while (getInput())
    {
        //getInput();
    }
    return 0;
}