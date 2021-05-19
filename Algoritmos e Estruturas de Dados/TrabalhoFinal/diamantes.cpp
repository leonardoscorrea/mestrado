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

int valida(string s)
{
    int countOpen = 0;
    int countClose = 0;
    int last = 0;
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '<')
        {
            countOpen++;
        }
        if ((s[i] == '>') && (countOpen > 0))
        {
            countOpen--;
            count++;
        }
    }

    return count;
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
    }
    else
        return 0;

    identifiers("[minas]: ");
    while ((std::getline(std::cin, line)) && count < number)
    {
        std::istringstream stream(line);
        cout << valida(line);
        cout << "\n";
        count++;
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