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

void fibonacciPisano(int valor)
{
    double n, x, y, valorFinal;
    n = (double)valor;
    x = (1 + sqrt(5)) / 2.0;
    y = (1 - sqrt(5)) / 2.0;
    valorFinal = (pow(x, n) - pow(y, n)) / sqrt(5);
    unsigned long long int z = ((unsigned long long int)(valor * valorFinal)) / valor;
    cout << "Fib(" << n << ") = " << z << "\n";
}

unsigned long long int fibonacci(int valor)
{
    if (valor == 0)
        return 0;
    if (valor == 1 || valor == 2)
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
        std::getline(std::cin, line);
        std::istringstream stream(line);
        stream >> number2;
        if (number2 < 30)
            cout << "Fib(" << number2 << ") = " << fibonacci(number2) << "\n";
        else
            fibonacciPisano(number2);
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