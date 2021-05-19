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
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            count++;
        if (s[i] == ')')
            count--;
        if (count < 0)
        {
            return 0;
        }
    }
    return ((count == 0) ? 1 : 0);
}

int getInput()
{
    int number;
    string line;
    string suit;

    identifiers("[Expressao matematica]: ");
    while (std::getline(std::cin, line))
    {
        std::istringstream stream(line);
        if (valida(line))
            cout << "correct";
        else
            cout << "incorrect";

        cout << "\n";
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