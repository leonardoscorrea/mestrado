#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
#include "gulosos.hpp"

using namespace std;

int main()
{

    int valor = 30;
    int tamanho = 2;

    criaVetor();
    adicionaValorVetor(30, 20);
    adicionaValorVetor(78, 30);
    adicionaValorVetor(78, 35);
    adicionaValorVetor(50, 10);

    cout << "valor do algoritmo mochilaFracionaria = " << mochilaFracionaria(valor, tamanho) << "\n";
    cout << "!! RESPOSTA PARA 2 !! \n O algoritmo do problema do troco NAO funcionaria para modas nos valores de 0,06 - 0,04 e 0,01 pois quando fosse subtrair a quantidade de moedas necessárias para o troco o resultado seria negativo. \n";
    return 0;
}