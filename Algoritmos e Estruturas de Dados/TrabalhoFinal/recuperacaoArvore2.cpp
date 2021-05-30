#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0

using namespace std;

map<char, int> ordem;
struct arvore
{
    char valor;
    struct arvore *direita;
    struct arvore *esquerda;
};

typedef struct arvore Arvore;

Arvore *arvoreFinal;

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

void criaOrdem(string infixada)
{
    //nas arvores infixadas imprimesse na ordem de peso de uma arvore
    for (int i = 0; i < infixada.size(); i++)
    {
        ordem[infixada[i]] = i;
    }
}

Arvore *insereNo(Arvore *arv, char valor)
{
    if (!arv)
    {
        arv = (Arvore *)malloc(sizeof(Arvore));
        arv->valor = valor;
        arv->direita = NULL;
        arv->esquerda = NULL;
    }
    else
    {
        if (ordem[arv->valor] < ordem[valor])
        {
            arv->direita = insereNo(arv->direita, valor);
        }
        else
        {
            arv->esquerda = insereNo(arv->esquerda, valor);
        }
    }
    return arv;
}

void criaArvore(string arvorePre)
{
    for (int i = 0; i < arvorePre.size(); i++)
    {
        arvoreFinal = insereNo(arvoreFinal, arvorePre[i]);
    }
}

void imprimeNo(Arvore *no)
{
    if (!no)
        return;
    imprimeNo(no->esquerda);
    imprimeNo(no->direita);
    cout << no->valor;
}

void imprimeArvore()
{
    imprimeNo(arvoreFinal);
}

int valida(string s)
{
    int countOpen = 0;
    int countClose = 0;
    int last = 0;
    int count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '<')
        {
            countOpen++;
        }
        if ((s[i] == '>') && (countOpen > 0))
        {
            countOpen--;
            count++;
        }
    }

    return count;
}

Arvore *limpaArvore(Arvore *arvore)
{
    if (!arvore)
        return NULL;
    limpaArvore(arvore->esquerda);
    limpaArvore(arvore->direita);
    free(arvore);
    arvore = NULL;
    return arvore;
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
        std::istringstream stream(line);
        stream >> arvorePre;
        stream >> arvoreInf;
        criaOrdem(arvoreInf);
        criaArvore(arvorePre);
        imprimeArvore();
        limpaArvore(arvoreFinal);
        ordem.clear();
        arvoreFinal = NULL;
        cout << "\n";
    }
    return 1;
}

int main()
{
    getInput();
    return 0;
}