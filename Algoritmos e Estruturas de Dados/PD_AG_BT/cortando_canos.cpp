#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <time.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0
#define TAMANHO 5

using namespace std;

typedef struct item
{
    int comprimento;
    int valor;
} Item;

int tamanhoCano;
int numeroItens;
vector<Item> teste;

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

void imprimeItens()
{
    for (int i = 0; i < teste.size(); i++)
    {
        cout << "comprimento: " << teste[i].comprimento << " valor: " << teste[i].valor << "\n";
    }
}

int maiorValor()
{
    vector<int> lucro;
    for (int i = 0; i <= tamanhoCano; i++)
    {
        lucro.push_back(0);
        for (int j = 0; j < numeroItens; j++)
        {
            if (teste[j].comprimento <= i)
            {
                lucro[i] = std::max(lucro[i], lucro[i - teste[j].comprimento] + teste[j].valor);
            }
        }
    }
    return lucro[tamanhoCano];
}

int getInput()
{

    int number;
    string line;
    string suit;

    identifiers("[QUANTIDADE DE PEDIDOS] [TAMANHO DO CANO]: ");
    std::getline(std::cin, line);
    std::istringstream stream(line);
    stream >> numeroItens;
    stream >> tamanhoCano;
    for (int i = 0; i < numeroItens; i++)
    {
        identifiers("[TAMANHO DO CANO SOLICITADO] [VALOR]: ");
        if (std::getline(std::cin, line))
        {
            Item i;
            std::istringstream stream(line);
            stream >> number;
            i.comprimento = number;
            stream >> number;
            i.valor = number;
            teste.push_back(i);
        }
    }
    //imprimeItens();
    cout << maiorValor() << "\n";
    return 1;
}

int main()
{
    //while (getInput())
    //{
    getInput();
    //mainGame.showValores();
    //mainGame.inicia();
    //mainGame.validaGame();
    //}
    return 0;
}