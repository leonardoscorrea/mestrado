#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0

using namespace std;

typedef struct lista
{
    int qty;
    string name;
} ListaAssassinos;

vector<ListaAssassinos> assassinos;
vector<string> assassinados;

struct find_ass
{
    string name;
    find_ass(string name) : name(name) {}
    bool operator()(const ListaAssassinos &m) const
    {
        return m.name == name;
    }
};

bool compareAlphabet(const ListaAssassinos &a, const ListaAssassinos &b)
{
    return a.name < b.name;
}

void inserir(string assassino, string assassinado)
{
    //nome do assassino nao esta na lista de assassinados
    if (std::find(assassinados.begin(), assassinados.end(), assassinado) == assassinados.end())
    {
        assassinados.push_back(assassinado);
    }
    if (std::find(assassinados.begin(), assassinados.end(), assassino) == assassinados.end())
    {

        std::vector<ListaAssassinos>::iterator it = std::find_if(assassinos.begin(), assassinos.end(), find_ass(assassino));
        if (it != assassinos.end())
        {

            it->qty++;
        }
        else
        {
            ListaAssassinos ass;
            ass.name = assassino;
            ass.qty = 1;
            assassinos.push_back(ass);
        }
        std::vector<ListaAssassinos>::iterator it2 = std::find_if(assassinos.begin(), assassinos.end(), find_ass(assassinado));
        if (it2 != assassinos.end())
        {
            assassinos.erase(it2);
        }
    }
}

void removeAssassinados()
{
    for (int i = 0; i < assassinados.size(); i++)
    {

        std::vector<ListaAssassinos>::iterator it = std::find_if(assassinos.begin(), assassinos.end(), find_ass(assassinados[i]));
        if (it != assassinos.end())
        {
            assassinos.erase(it);
        }
    }
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
    for (int i = 0; i < assassinos.size(); i++)
    {
        cout << assassinos[i].name << " " << assassinos[i].qty << "\n";
    }
}

int getInput()
{
    string nameAssassino;
    string nameAssassinado;
    string line;
    string suit;

    identifiers("[Expressao matematica]: ");
    while (std::getline(std::cin, line))
    {
        std::istringstream stream(line);
        stream >> nameAssassino;
        stream >> nameAssassinado;

        inserir(nameAssassino, nameAssassinado);
    }
    //removeAssassinados();
    sort(assassinos.begin(), assassinos.end(), compareAlphabet);
    verifica();
    return 1;
}

int main()
{
    getInput();
    return 0;
}