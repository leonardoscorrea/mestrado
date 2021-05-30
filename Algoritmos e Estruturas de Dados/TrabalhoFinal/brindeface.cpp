#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0

using namespace std;

typedef struct participante
{
    char l1;
    char l2;
    char l3;
    char l4;
} Participante;

int globalCounter = 0;

vector<Participante> participantes;

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

void show()
{
    if (SHOW_IDENTIFIERS)
    {
        for (int i = 0; i < participantes.size(); i++)
        {
            cout << participantes[i].l1 << ' ' << participantes[i].l2 << ' ' << participantes[i].l3 << ' ' << participantes[i].l4 << '\n';
        }
    }
}

void valida(Participante p);
void iniciaLista()
{
    Participante p;
    p.l1 = 'F';
    p.l2 = 'A';
    p.l3 = 'C';
    p.l4 = 'E';
    valida(p);
}

void valida(Participante p)
{
    if (participantes.size() > 0)
    {
        if (participantes[participantes.size() - 1].l1 == p.l4 && participantes[participantes.size() - 1].l2 == p.l3 && participantes[participantes.size() - 1].l3 == p.l2 && participantes[participantes.size() - 1].l4 == p.l1)
        {
            participantes.pop_back();
            globalCounter++;
            if (participantes.size() == 0)
            {
                iniciaLista();
            }
        }
        else
        {
            participantes.push_back(p);
        }
    }
    else
    {
        participantes.push_back(p);
    }
}

int getInput()
{
    char letra;
    int number;
    string line;
    string suit;
    int counter = 0;

    iniciaLista();

    identifiers("[Quantidade de Participantes]: ");
    std::getline(std::cin, line);
    std::istringstream stream(line);
    if (stream >> number)
    {
        if (number == 0)
            return 0;
    }
    else
        return 0;

    identifiers("[Letras]: ");
    while (std::getline(std::cin, line) && number > counter)
    {
        Participante p;
        std::istringstream stream(line);
        stream >> letra;
        p.l1 = letra;
        stream >> letra;
        p.l2 = letra;
        stream >> letra;
        p.l3 = letra;
        stream >> letra;
        p.l4 = letra;
        valida(p);
        counter++;
    }
    show();
    cout << globalCounter << "\n";
    return 1;
}

int main()
{
    getInput();
    return 0;
}