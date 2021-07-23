#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <time.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0
#define TAMANHO 5

using namespace std;

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

int getInput()
{
    int number, pessoas, grupos, resultado;
    string line, line2;
    string suit;
    int menordistancia = 0;
    identifiers("[NUMERO PESSOAS] [NUMERO GRUPOS]: ");
    while (std::getline(std::cin, line))
    {
        resultado = 0;
        std::istringstream stream(line);
        stream >> pessoas;
        stream >> grupos;
        vector<int> distanciaPessoas, distanciaAnterior;
        distanciaPessoas.push_back(0);
        distanciaAnterior.push_back(0);
        identifiers("[PESSOA 1] [PESSOA 1] .. [PESSOA N-1]: ");
        std::getline(std::cin, line2);
        std::istringstream stream2(line2);
        for (int i = 1; i < pessoas; i++)
        {
            stream2 >> number;
            distanciaPessoas.push_back(number);
            distanciaAnterior.push_back(distanciaPessoas[i] - distanciaPessoas[i - 1]);
        }

        sort(distanciaAnterior.begin(), distanciaAnterior.end(), greater<int>());
        for (int i = grupos - 1; i < pessoas; i++)
            resultado += distanciaAnterior[i];
        cout << resultado << "\n";
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