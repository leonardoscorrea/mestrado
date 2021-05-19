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
    int count = qtd;
    int ponteiro = 0;
    for (int i = 1; i <= qtd; i++)
    {
        pilha.push_back(i);
    }
    if (qtd > 1)
    {
        for (int i = 1; i < qtd; i++)
        {
            descarte.push_back(pilha[ponteiro++]);
            pilha.erase(pilha.begin() + (ponteiro - 1));
            /*for (int i = 0; i < count - 1; i++)
        {
            cout << pilha[i] << ((i != count - 2) ? ", " : "\n");
        }*/
            count--;
            sort(pilha.begin(), pilha.end());
            if (ponteiro == count + 1)
                ponteiro = 1;
            else if (ponteiro >= count)
                ponteiro = 0;
        }

        cout << "Discarded cards: ";
        for (int i = 0; i < qtd - 1; i++)
        {
            cout << descarte[i] << ((i != qtd - 2) ? ", " : "\n");
        }
    }
    else
    {
        cout << "Discarded cards: "
             << "\n";
    }
    cout << "Remaining card: " << pilha[0] << "\n";

    pilha.erase(pilha.begin(), pilha.begin());
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