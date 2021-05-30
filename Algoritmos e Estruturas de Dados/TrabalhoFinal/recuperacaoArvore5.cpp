#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0

using namespace std;

int contador;

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

void imprimePOS(string prefixado, string infixado, int inicio, int fim)
{
    /*
    pre: D B A C E G F
    in:  A B C D E F G
    inicio 0
    fim 6
    */
    if (inicio <= fim)
    {
        contador++;
        //raiz = posicao 3 = D
        int raiz = infixado.find(prefixado[contador]); //buscaRaiz
        //imprimePOS de 0 a 2 (A B C)
        imprimePOS(prefixado, infixado, inicio, raiz - 1); //imprime arvore esquerda
        //imprimePOS de 4 a 6 (E F G)
        imprimePOS(prefixado, infixado, raiz + 1, fim); //imprime arvore direita
        //imprime raiz D
        cout << infixado[raiz]; // imprime raiz
    }
}

int getInput()
{
    int number;
    string line;
    string arvorePre;
    string arvoreInf;

    identifiers("[arvore prefixo] [arvore infixo]: ");
    while ((std::getline(std::cin, line)))
    {
        contador = -1;
        std::istringstream stream(line);
        stream >> arvorePre;
        stream >> arvoreInf;
        int indexFim = arvorePre.size() - 1;
        imprimePOS(arvorePre, arvoreInf, 0, indexFim);
        cout << "\n";
    }
    return 1;
}

int main()
{
    getInput();
    return 0;
}