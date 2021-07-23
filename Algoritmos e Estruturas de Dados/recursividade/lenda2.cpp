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

int proximoSuicidar(int numeroPessoas, int passo)
{
    if (numeroPessoas == 1)
        return 1;
    else
        return (proximoSuicidar(numeroPessoas - 1, passo) + passo - 1) % numeroPessoas + 1;
}

void imprimeVetor(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

vector<int> inicializaVetor(int tamanho)
{
    vector<int> v;
    for (int i = 1; i <= tamanho; i++)
    {
        v.push_back(i);
    }
    return v;
}

int getInput()
{
    int number, pessoas, passo;
    string line;
    string suit;

    identifiers("[quantidade de testes]: ");
    if (std::getline(std::cin, line))
    {
        std::istringstream stream(line);
        stream >> number;
    }

    identifiers("[pessoas] [passo]: ");
    for (int i = 0; i < number; i++)
    {
        std::getline(std::cin, line);
        std::istringstream stream(line);
        stream >> pessoas;
        stream >> passo;

        //cout << pessoas << " = " << passo << " = " << proximoSuicidar(pessoas, passo) << "\n";
        cout << "Case " << i + 1 << ": " << proximoSuicidar(pessoas, passo) << "\n";
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