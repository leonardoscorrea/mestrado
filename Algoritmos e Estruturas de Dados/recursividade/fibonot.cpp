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

bool ValidaValor(long long int x)
{

    long long int s;
    s = sqrt(x);
    return (s * s == x);
}

bool ehFibonacci(long long int c)
{
    return (ValidaValor(5 * pow(c, 2) + 4) || ValidaValor(5 * pow(c, 2) - 4));
}

int getInput()
{
    int number;
    string line;
    string suit;

    identifiers("[numero do elemento fibonot]: ");
    std::getline(std::cin, line);
    std::istringstream stream(line);
    if (stream >> number)
    {
        if (number == 0)
            cout << 0 << "\n";
        else
        {
            int contador = 0;
            int valor = 0;
            for (int i = 4; contador != number; i++)
            {
                if (!ehFibonacci(i))
                {
                    contador++;
                    valor = i;
                }
            }
            cout << valor << "\n";
        }
    }
    else
        return 0;
    return 1;
}

int main()
{
    getInput();
    return 0;
}