#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0
#define TAMANHO 5

using namespace std;

int matriz[TAMANHO][TAMANHO];

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

int fatorial(int valor)
{
    if (valor <= 1)
        return valor;
    return valor * fatorial(valor - 1);
}

void iniciaMatriz()
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            matriz[i][j] = 0;
        }
    }
}

int getInput()
{
    iniciaMatriz();

    /*int number;
    string line;
    string suit;

    identifiers("[Valor para calcular o fatorial]: ");
    std::getline(std::cin, line);
    std::istringstream stream(line);
    if (stream >> number)
    {
        if (number == 0)
            cout << 0 << "\n";
        else
            cout << fatorial(number) << "\n";
    }
    else
        return 0;*/
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