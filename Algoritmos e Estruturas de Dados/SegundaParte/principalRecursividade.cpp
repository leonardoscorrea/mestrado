#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
#include "recursividade.hpp"

using namespace std;

int main()
{
    cout << "Fibonacci: " << fibonacci(7) << "\n";
    cout << "valor de 2^n: " << _2n(3) << "\n";
    cout << "valor de a^n: " << _an(3, 2) << "\n";
    cout << "soma de valores: " << sum(5) << "\n";
    cout << "valor de fn: " << fn(4) << "\n";
    cout << "multiplicacao recursiva: " << multInt(3, 4) << "\n";
    cout << (polindromo("renner") ? "Eh Polindromo" : "Nao eh Polindromo") << "\n";
    cout << (polindromo("qualquer") ? "Eh Polindromo" : "Nao eh Polindromo") << "\n";
    cout << "conta caractere: " << contaCaractere('u', "qualquer") << "\n";
    cout << "soma digitos: " << somaDigitos(12345) << "\n";
    cout << "inverte valor inteiro: " << inverteInteiro(12345) << "\n";
    cout << "imprime lista crescente \n";
    imprimeLista(1, 3);
    cout << "imprime lista decrescente \n";
    imprimeLista(3, 1);
    cout << "maximo divisor comum: " << maximoDivisor(10, 15) << "\n";
    std::vector<int> v;
    v.push_back(5);
    v.push_back(7);
    v.push_back(2);
    cout << "maior elemento: " << maiorElemento(v) << "\n";
    std::vector<int> v2;
    for (int i = 1; i < 100; i += 2)
    {
        v2.push_back(i);
    }
    cout << "busca elemento recursivo: " << buscaElementoVetor(v2, 7) << "\n";
    return 0;
}