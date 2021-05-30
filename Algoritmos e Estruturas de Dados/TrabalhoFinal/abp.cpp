#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0

using namespace std;

typedef struct dado
{
    int valor;
} Dado;

typedef struct arvore
{
    Dado dado;
    struct arvore *arvoreDireita;
    struct arvore *arvoreEsquerda;
} Arvore;

Arvore *criar();
void apresentaArvore(Arvore *a, char *metodo);
int arvoreVazia(Arvore *a);
void inserir(Arvore **a, int valor);
int procurar(Arvore *a, int valor);
void remover(Arvore **a, int valor);

Arvore *criar()
{
    return NULL;
}

string retorno;

void imprimePre(Arvore *a)
{
    if (!arvoreVazia(a))
    {
        retorno += (char)(a->dado.valor);
        imprimePre(a->arvoreEsquerda);
        imprimePre(a->arvoreDireita);
    }
}

void imprimeIn(Arvore *a)
{
    if (!arvoreVazia(a))
    {
        imprimeIn(a->arvoreEsquerda);
        retorno += (char)(a->dado.valor);
        imprimeIn(a->arvoreDireita);
    }
}

void imprimePos(Arvore *a)
{
    if (!arvoreVazia(a))
    {
        imprimePos(a->arvoreEsquerda);
        imprimePos(a->arvoreDireita);
        retorno += (char)(a->dado.valor);
    }
}

void imprimirArvore(Arvore *a, char *metodo)
{
    if (strcmp(metodo, "pre") == 0)
    {
        if (!arvoreVazia(a))
        {
            printf("%d ", a->dado.valor);
            imprimirArvore(a->arvoreEsquerda, metodo);
            imprimirArvore(a->arvoreDireita, metodo);
        }
    }
    else if (strcmp(metodo, "pos") == 0)
    {
        if (!arvoreVazia(a))
        {
            imprimirArvore(a->arvoreEsquerda, metodo);
            imprimirArvore(a->arvoreDireita, metodo);
            printf("%d ", a->dado.valor);
        }
    }
    else
    {
        if (!arvoreVazia(a))
        {
            imprimirArvore(a->arvoreEsquerda, metodo);
            printf("%d ", a->dado.valor);
            imprimirArvore(a->arvoreDireita, metodo);
        }
    }
}

int arvoreVazia(Arvore *a)
{
    return a == NULL;
}

void inserir(Arvore **a, int valor)
{
    if (*a == NULL)
    {
        *a = (Arvore *)malloc(sizeof(Arvore));
        (*a)->arvoreEsquerda = NULL;
        (*a)->arvoreDireita = NULL;
        (*a)->dado.valor = valor;
    }
    else
    {
        if (valor < (*a)->dado.valor)
        {
            inserir(&(*a)->arvoreEsquerda, valor);
        }
        if (valor > (*a)->dado.valor)
        {
            inserir(&(*a)->arvoreDireita, valor);
        }
    }
}

void apresentaArvore(Arvore *a, char *metodo)
{
    printf("Metodo %s\n", metodo);
    imprimirArvore(a, metodo);
    printf("\n");
}

int procurar(Arvore *a, int valor)
{

    if (arvoreVazia(a))
    {
        return 0;
    }

    return a->dado.valor == valor || procurar(a->arvoreEsquerda, valor) || procurar(a->arvoreDireita, valor);
}

Arvore *MaiorDireita(Arvore **a)
{
    if ((*a)->arvoreDireita != NULL)
        return MaiorDireita(&(*a)->arvoreDireita);
    else
    {
        Arvore *aux = *a;
        if ((*a)->arvoreEsquerda != NULL)
            *a = (*a)->arvoreEsquerda;
        else
            *a = NULL;
        return aux;
    }
}

Arvore *MenorEsquerda(Arvore **a)
{
    if ((*a)->arvoreEsquerda != NULL)
        return MenorEsquerda(&(*a)->arvoreEsquerda);
    else
    {
        Arvore *aux = *a;
        if ((*a)->arvoreDireita != NULL)
            *a = (*a)->arvoreDireita;
        else
            *a = NULL;
        return aux;
    }
}

void remover(Arvore **a, int valor)
{
    if (*a == NULL)
    {
        printf("Valor %d nao existe na arvore\n", valor);
        return;
    }
    if (valor < (*a)->dado.valor)
        remover(&(*a)->arvoreEsquerda, valor);
    else if (valor > (*a)->dado.valor)
        remover(&(*a)->arvoreDireita, valor);
    else
    {
        Arvore *pAux = *a;
        if (((*a)->arvoreEsquerda == NULL) && ((*a)->arvoreDireita == NULL))
        {
            free(pAux);
            (*a) = NULL;
        }
        else
        {
            if ((*a)->arvoreEsquerda == NULL)
            {
                (*a) = (*a)->arvoreDireita;
                pAux->arvoreDireita = NULL;
                free(pAux);
                pAux = NULL;
            }
            else
            {
                if ((*a)->arvoreDireita == NULL)
                {
                    (*a) = (*a)->arvoreEsquerda;
                    pAux->arvoreEsquerda = NULL;
                    free(pAux);
                    pAux = NULL;
                }
                else
                {
                    pAux = MaiorDireita(&(*a)->arvoreEsquerda);
                    pAux->arvoreEsquerda = (*a)->arvoreEsquerda;
                    pAux->arvoreDireita = (*a)->arvoreDireita;
                    (*a)->arvoreEsquerda = (*a)->arvoreDireita = NULL;
                    free((*a));
                    *a = pAux;
                    pAux = NULL;
                }
            }
        }
    }
}

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

Arvore *a = criar();

void imprimeRetorno()
{
    for (int i = 0; i < retorno.size(); i++)
    {
        cout << retorno[i] << ((i == retorno.size() - 1) ? "" : " ");
    }
    cout << "\n";
}

int getInput()
{
    string comando;
    char valor;
    string line;
    string suit;

    identifiers("[Expressao matematica]: ");
    while (std::getline(std::cin, line))
    {
        std::istringstream stream(line);
        stream >> comando;
        if (stream >> valor)
        {
            if (comando == "I")
            {
                inserir(&a, (int)valor);
            }
            else if (comando == "P")
            {
                if (procurar(a, (int)valor) > 0)
                {
                    cout << valor << " existe" << '\n';
                }
                else
                {
                    cout << valor << " nao existe" << '\n';
                }
            }
        }
        else
        {
            retorno = "";
            if (comando == "INFIXA")
            {
                imprimeIn(a);
            }
            else if (comando == "PREFIXA")
            {
                imprimePre(a);
            }
            else if (comando == "POSFIXA")
            {
                imprimePos(a);
            }
            imprimeRetorno();
        }
    }
    return 1;
}

int main()
{
    //getInput();
    /*
    inserir(&a, (int)'d');
    inserir(&a, (int)'b');
    inserir(&a, (int)'a');
    inserir(&a, (int)'c');
    inserir(&a, (int)'e');
    inserir(&a, (int)'g');
    inserir(&a, (int)'f');
    imprimePre(a);
    cout << '\n';
    imprimeIn(a);
    cout << '\n';
    imprimePos(a);
    cout << '\n';
    remover(&a, (int)'e');
    imprimePos(a);
    cout << '\n';

    cout << procurar(a, (int)'f') << " " << procurar(a, (int)'z') << "\n";*/
    //apresentaArvore(a, "pos");
    //apresentaArvore(a, "central");
    getInput();
    return 0;
}