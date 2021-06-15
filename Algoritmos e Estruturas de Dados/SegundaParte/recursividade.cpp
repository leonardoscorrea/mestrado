#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "recursividade.hpp"

using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    else
        return (fibonacci(n - 1) + fibonacci(n - 2));
}

int _2n(int n)
{
    if (n == 0)
        return 1;
    else
        return 2 * _2n(n - 1);
}

int _an(int a, int n)
{
    if (n == 0)
        return 1;
    else
        return a * _an(a, n - 1);
}

int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

int fn(int n)
{
    if (n == 0)
        return 3;
    return 2 * fn(n - 1) + 3;
}

int multInt(int v1, int v2)
{
    if (v2 == 1)
        return v1;
    return v1 + multInt(v1, v2 - 1);
}

int verificaPolindromo(std::string s, int inicio, int fim)
{
    if (inicio >= fim)
        return 1;
    return (s[inicio] != s[fim]) ? 0 : verificaPolindromo(s, inicio + 1, fim - 1);
}

int polindromo(std::string s)
{
    return verificaPolindromo(s, 0, s.length() - 1);
}

int verificaCaractere(char c, std::string s, int inicio, int fim)
{
    if (inicio > fim)
        return 0;
    return ((s[inicio] == c) ? 1 : 0) + verificaCaractere(c, s, inicio + 1, fim);
}

int contaCaractere(char c, std::string s)
{
    return verificaCaractere(c, s, 0, s.length() - 1);
}

int soma(std::string s, int inicio, int fim)
{
    if (inicio > fim)
        return 0;
    return ((int)s[inicio] - (int)'0') + soma(s, inicio + 1, fim);
}

int somaDigitos(int numero)
{
    stringstream ss;
    std::string n;
    ss << numero;
    ss >> n;
    return soma(n, 0, n.length() - 1);
}

std::string invertInt(std::string s, int inicio, int fim)
{
    if (inicio > fim)
        return "";
    return s[fim] + invertInt(s, inicio, fim - 1);
}

int inverteInteiro(int numero)
{
    stringstream ss;
    std::string n;
    ss << numero;
    ss >> n;
    return std::stoi(invertInt(n, 0, n.length() - 1));
}

int imprimeLista(int inicio, int fim)
{
    if (inicio == fim)
        return fim;

    cout << inicio;
    int i = imprimeLista((inicio < fim) ? inicio + 1 : inicio - 1, fim);
    if (i > 0)
        cout << i;
    else
        cout << "\n";
    return -1;
}

int maximoDivisor(int a, int b)
{
    if (b == 0)
        return a;
    return maximoDivisor(b, a % b);
}

int maior(std::vector<int> v, int inicio, int fim)
{
    if (inicio > fim)
        return -1;
    int proximo = maior(v, inicio + 1, fim);
    return (v[inicio] > proximo) ? v[inicio] : proximo;
}

int maiorElemento(std::vector<int> v)
{
    return maior(v, 0, v.size() - 1);
}

int buscaRecursiva(std::vector<int> v, int valor, int inicio, int fim)
{
    if (inicio == fim - 1)
        return fim;
    int meio = (inicio + fim) / 2;
    if (v[meio] < valor)
        return buscaRecursiva(v, valor, meio, fim);
    else
        return buscaRecursiva(v, valor, inicio, meio);
}

int buscaElementoVetor(std::vector<int> v, int elemento)
{
    return buscaRecursiva(v, elemento, 0, v.size() - 1);
}