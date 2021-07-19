#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0

using namespace std;

int contadorGlobal = 0;

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

unsigned long long int fibonacci(int valor)
{
    contadorGlobal += 1;
    if (valor == 0)
        return 0;
    if (valor == 1)
        return 1;

    return fibonacci(valor - 1) + fibonacci(valor - 2);
}

int getInput()
{
    unsigned long long int number, number2;
    string line;
    string suit;

    identifiers("[quantidade de testes]: ");
    if (std::getline(std::cin, line))
    {
        std::istringstream stream(line);
        stream >> number;
    }

    identifiers("[valor de fibonacci]: ");
    for (int i; i < number; i++)
    {
        contadorGlobal = 0;
        std::getline(std::cin, line);
        std::istringstream stream(line);
        stream >> number2;
        unsigned long long int resultado = fibonacci(number2);
        cout << "fib(" << number2 << ") = " << contadorGlobal - 1 << " calls = " << resultado << "\n";
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