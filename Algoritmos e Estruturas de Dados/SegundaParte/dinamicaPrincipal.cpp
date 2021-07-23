#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
#include "dinamica.hpp"

using namespace std;

int main()
{

    criaVetor();
    adicionaValorVetor(2);
    adicionaValorVetor(3);
    adicionaValorVetor(5);
    adicionaValorVetor(7);
    adicionaValorVetor(10);
    adicionaValorVetor(15);
    imprimeVetor();
    cout << "corteHastes: " << corteHastes(7) << "\n";
    cout << "corteButtomUp: " << corteButtomUp(3) << "\n";
    return 0;
}