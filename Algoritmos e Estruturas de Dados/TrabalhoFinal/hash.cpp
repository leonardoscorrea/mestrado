#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0

using namespace std;

map<int, int> valores;
struct no
{
    int posicao;
    vector<int> valores;
};

typedef struct no No;

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}
template <typename K, typename V>
void printMap(map<K, V> const &m)
{
    for (auto const &pair : m)
    {
        cout << "{" << pair.first << "," << pair.second << "}"
             << "\n";
    }
}

int getInput()
{
    int number, addressTable, hashKeys;
    string line, line2;
    string suit;
    int count = 0, primeiro = 1;

    identifiers("[Quantidade de Jogadas]: ");
    std::getline(std::cin, line);
    std::istringstream stream(line);
    if (stream >> number)
    {
        if (number == 0)
            return 0;
        else
            count = number;
    }
    else
        return 0;

    for (int i = 0; i < count; i++)
    {
        if (primeiro)
        {
            primeiro = 0;
        }
        else
        {
            cout << "\n";
        }
        std::getline(std::cin, line);
        std::istringstream stream(line);
        stream >> addressTable;
        stream >> hashKeys;
        //cout << "enderecos: " << addressTable << " chaves: " << hashKeys << "\n";
        vector<No> mapper;
        for (int i = 0; i < addressTable; i++)
        {
            No n;
            n.posicao = i;
            mapper.push_back(n);
        }

        std::getline(std::cin, line2);
        std::istringstream stream2(line2);
        while (stream2 >> number)
        {

            //cout << "chave: " << number << " mod: " << (number % addressTable) << "\n";
            mapper[(number % addressTable)].valores.push_back(number);
            //valores[(number % addressTable)] = number;
        }
        //int x = 88 % 13;
        //cout << "valor: " << x << "\n";
        //printMap(valores);
        for (int i = 0; i < mapper.size(); i++)
        {
            cout << mapper[i].posicao << " -> ";
            for (int j = 0; j < mapper[i].valores.size(); j++)
            {
                cout << mapper[i].valores[j] << " -> ";
            }
            cout << " \\"
                 << "\n";
        }
    }

    return 1;
}

int main()
{

    while (getInput())
    {
    }
    return 0;
}