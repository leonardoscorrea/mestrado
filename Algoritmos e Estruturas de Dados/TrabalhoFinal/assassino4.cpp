#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0

using namespace std;

typedef std::map<string, int> lista;

lista assassinos;
lista assassinados;

void inserir(string assassino, string assassinado)
{
    ++assassinos[assassino];
    ++assassinados[assassinado];
}

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

void verifica()
{
    cout << "HALL OF MURDERERS"
         << "\n";
    for (map<string, int>::iterator i = assassinos.begin(); i != assassinos.end(); ++i)
    {
        int checkAssassinado = assassinados[i->first];
        if (!checkAssassinado)
        {
            cout << i->first << ' ' << i->second << "\n";
        }
    }
}

int getInput()
{
    string nameAssassino;
    string nameAssassinado;
    string line;
    string suit;

    identifiers("[Assassino] [assassinado]: ");
    while (std::getline(std::cin, line))
    {
        std::istringstream stream(line);
        stream >> nameAssassino;
        stream >> nameAssassinado;

        inserir(nameAssassino, nameAssassinado);
    }
    verifica();
    return 1;
}

int main()
{
    getInput();
    return 0;
}