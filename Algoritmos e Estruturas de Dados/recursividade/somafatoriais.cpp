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

unsigned long long int fatorial(int valor)
{
    if (valor <= 1)
        return 1;
    return valor * fatorial(valor - 1);
}

int getInput()
{
    unsigned long long int number, number2;
    string line;
    string suit;

    identifiers("[numero1] [numero2]: ");
    while (std::getline(std::cin, line))
    {
        std::istringstream stream(line);
        stream >> number;
        stream >> number2;

        cout << (fatorial(number) + fatorial(number2)) << "\n";
    }
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