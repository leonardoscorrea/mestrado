#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0

using namespace std;

//fila prioritaria
typedef struct priorityQueue
{
    int qty;
    vector<int> valores;
    int ponteiro;
    int qtyElementos;
    int ehFila;

    void inicia(int q)
    {
        qty = q;
        qtyElementos = 0;
        ponteiro = 0;
        ehFila = 1;
        for (int i = 0; i < qty; i++)
        {
            valores.push_back(-1);
        }
    }

    void inserir(int val)
    {
        valores[qtyElementos] = val;
        sort(valores.begin(), valores.end(), greater<int>());
        qtyElementos++;
    }

    void removerComValidacao(int val)
    {
        if ((qtyElementos - ponteiro) > 0)
        {
            if (ehFila)
            {
                int aux = valores[ponteiro++];
                valores[ponteiro - 1] = -1;
                if (aux != val)
                {
                    ehFila = 0;
                }
            }
            else
            {
                valores[--ponteiro] = -1;
            }
        }
    }

    void libera()
    {
        free(&valores);
    }

    int verifica()
    {
        return ehFila;
    }

    void showValores()
    {
        if (SHOW_IDENTIFIERS)
        {
            for (int i = 0; i < qty; i++)
            {
                cout << valores[i] << " ";
            }
            cout << "\n";
        }
    }
} PriorityQueue;

//fila
typedef struct queue
{
    int qty;
    vector<int> valores;
    int ponteiro;
    int qtyElementos;
    int ehFila;

    void inicia(int q)
    {
        qty = q;
        qtyElementos = 0;
        ponteiro = 0;
        ehFila = 1;
        for (int i = 0; i < qty; i++)
        {
            valores.push_back(-1);
        }
    }

    void libera()
    {
        free(&valores);
    }

    void inserir(int val)
    {
        valores[qtyElementos] = val;
        qtyElementos++;
    }

    void removerComValidacao(int val)
    {
        if ((qtyElementos - ponteiro) > 0)
        {
            if (ehFila)
            {
                int aux = valores[ponteiro++];
                valores[ponteiro - 1] = -1;
                if (aux != val)
                {
                    ehFila = 0;
                }
            }
            else
            {
                valores[--ponteiro] = -1;
            }
        }
    }

    int verifica()
    {
        return ehFila;
    }

    void showValores()
    {
        if (SHOW_IDENTIFIERS)
        {
            for (int i = 0; i < qty; i++)
            {
                cout << valores[i] << " ";
            }
            cout << "\n";
        }
    }
} Queue;

//pilha
typedef struct stack
{
    int qty;
    vector<int> valores;
    int ponteiro;
    int qtyElementos;
    int ehPilha;

    void inicia(int q)
    {
        qty = q;
        qtyElementos = 0;
        ponteiro = 0;
        ehPilha = 1;
        for (int i = 0; i < qty; i++)
        {
            valores.push_back(-1);
        }
    }

    void libera()
    {
        free(&valores);
    }

    void inserir(int val)
    {
        valores[ponteiro] = val;
        ponteiro++;
    }

    void removerComValidacao(int val)
    {
        if (ponteiro > 0)
        {
            if (ehPilha)
            {
                int aux = valores[--ponteiro];
                valores[ponteiro] = -1;
                if (aux != val)
                {
                    ehPilha = 0;
                }
            }
            else
            {
                valores[--ponteiro] = -1;
            }
        }
    }

    int verifica()
    {
        return ehPilha;
    }

    void showValores()
    {
        if (SHOW_IDENTIFIERS)
        {
            for (int i = 0; i < qty; i++)
            {
                cout << valores[i] << " ";
            }
            cout << "\n";
        }
    }
} Stack;

struct game
{
    int qty;
    vector<int> acao;
    vector<int> valores;
    Stack pilha;
    Queue fila;
    PriorityQueue filaPrioritaria;

    void
    inicia()
    {
        pilha.inicia(qty);
        fila.inicia(qty);
        filaPrioritaria.inicia(qty);
        for (int i = 0; i < qty; i++)
        {
            if (acao[i] == 1)
            {
                pilha.inserir(valores[i]);
                fila.inserir(valores[i]);
                filaPrioritaria.inserir(valores[i]);
            }
            else if (acao[i] == 2)
            {
                pilha.removerComValidacao(valores[i]);
                fila.removerComValidacao(valores[i]);
                filaPrioritaria.removerComValidacao(valores[i]);
            }
        }
    }

    void validaGame()
    {
        if (!pilha.verifica() && !fila.verifica() && !filaPrioritaria.verifica())
        {
            printf("impossible\n");
        }
        else
        {
            if (pilha.verifica())
            {
                if (fila.verifica() || filaPrioritaria.verifica())
                {
                    printf("not sure\n");
                }
                else
                {
                    printf("stack\n");
                }
            }
            else if (fila.verifica())
            {
                if (pilha.verifica() || filaPrioritaria.verifica())
                {
                    printf("not sure\n");
                }
                else
                {
                    printf("queue\n");
                }
            }
            else if (filaPrioritaria.verifica())
            {
                if (pilha.verifica() || fila.verifica())
                {
                    printf("not sure\n");
                }
                else
                {
                    printf("priority queue\n");
                }
            }
        }
        pilha.libera();
        filaPrioritaria.libera();
        fila.libera();
        free(&valores);
        free(&acao);
    }

    void showValores()
    {
        if (SHOW_IDENTIFIERS)
        {
            for (int i = 0; i < qty; i++)
            {
                cout << acao[i] << " ";
            }
            cout << "\n";
        }
    }
};

game mainGame;

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

int getInput()
{
    int number;
    string line;
    string suit;

    identifiers("[Quantidade de Acoes]: ");
    std::getline(std::cin, line);
    std::istringstream stream(line);
    if (stream >> number)
        mainGame.qty = number;
    else
        return 0;

    identifiers("[Acao] [Valor]");
    for (int i = 0; i < mainGame.qty; i++)
    {
        std::getline(std::cin, line);
        std::istringstream stream(line);
        if (stream >> number)
            mainGame.acao.push_back(number);
        if (stream >> number)
            mainGame.valores.push_back(number);
    }

    return 1;
}

int main()
{
    while (getInput())
    {
        mainGame.showValores();
        mainGame.inicia();
        mainGame.validaGame();
    }
    return 0;
}