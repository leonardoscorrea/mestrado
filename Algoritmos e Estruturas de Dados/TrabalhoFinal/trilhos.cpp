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
        ponteiro = 0;
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
                if (ponteiro > 0)
                {
                    valores[--ponteiro] = -1;
                }
            }
        }
    }

    void libera()
    {
        //free(&valores);
        valores.erase(valores.begin(), valores.begin() + qty);
        qty = 0;
        qtyElementos = 0;
        ponteiro = 0;
        ehFila = 1;
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
        //free(&valores);
        valores.erase(valores.begin(), valores.begin() + qty);
        qty = 0;
        qtyElementos = 0;
        ponteiro = 0;
        ehFila = 1;
    }

    void inserir(int val)
    {
        valores[qtyElementos] = val;
        qtyElementos++;
    }

    int pull()
    {
        if (qtyElementos > 0)
        {
            int aux = valores[ponteiro++];
            valores[ponteiro - 1] = -1;
            return aux;
        }
        else
        {
            return -1;
        }
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
                if (ponteiro > 0)
                {
                    valores[--ponteiro] = -1;
                }
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
        //free(&valores);
        valores.erase(valores.begin(), valores.begin() + qty);
        qty = 0;
        qtyElementos = 0;
        ponteiro = 0;
        ehPilha = 1;
    }

    void inserir(int val)
    {
        valores[ponteiro] = val;
        qtyElementos++;
        ponteiro++;
    }

    int pull()
    {
        if (qtyElementos > 0)
        {
            int aux = valores[--ponteiro];
            valores[ponteiro] = -1;
            qtyElementos--;
            return aux;
        }
        else
        {
            return -1;
        }
    }

    int getHead()
    {
        if (qtyElementos > 0)
        {
            return valores[ponteiro - 1];
        }
        else
        {
            return -1;
        }
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
                if (ponteiro > 0)
                {
                    valores[--ponteiro] = -1;
                }
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
    vector<int> gabarito;
    vector<int> valores;
    Stack pilha;
    Queue fila;
    int pGabarito;

    void
    inicia()
    {
        fila.inicia(qty);
        pilha.inicia(qty);
        pGabarito = 0;
        for (int i = 1; i <= qty; i++)
        {
            fila.inserir(i);
            valores.push_back(-1);
        }
    }

    void validaGame()
    {

        int vagao = fila.pull();
        int count = 0;
        while (vagao > 0 && count < qty)
        {
            if (vagao == gabarito[pGabarito])
            {
                valores[pGabarito++] = vagao;
            }
            else if (vagao == pilha.getHead())
            {
                valores[pGabarito++] = pilha.pull();
            }
            else
            {
                pilha.inserir(vagao);
            }

            vagao = fila.pull();
            while (gabarito[pGabarito] == pilha.getHead())
            {
                valores[pGabarito++] = pilha.pull();
            }

            count++;
        }

        vagao = pilha.pull();
        while (vagao > 0)
        {
            valores[pGabarito++] = vagao;
            vagao = pilha.pull();
        }

        int iqual = 1;
        for (int i = 0; i < qty; i++)
        {
            if (valores[i] != gabarito[i])
            {
                iqual = 0;
                break;
            }
        }

        cout << ((iqual) ? "Yes" : "No");

        //pilha.libera();
        //fila.libera();
        gabarito.erase(gabarito.begin(), gabarito.begin() + qty);
        //valores.erase(valores.begin(), valores.begin() + qty);
    }

    void showValores()
    {
        if (SHOW_IDENTIFIERS)
        {
            for (int i = 0; i < qty; i++)
            {
                cout << gabarito[i] << " ";
            }
            for (int i = 0; i < qty; i++)
            {
                cout << valores[i] << " ";
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

    identifiers("[Quantidade de Vagoes]: ");
    std::getline(std::cin, line);
    std::istringstream stream(line);
    if (stream >> number)
    {
        if (number == 0)
            return 0;
        mainGame.qty = number;
    }
    else
        return 0;

    identifiers("[Acao] [Valor]");
    int stop = 1;
    while (stop)
    {
        mainGame.inicia();
        std::getline(std::cin, line);
        std::istringstream stream(line);
        while (stream >> number)
        {

            if (number == 0)
            {
                stop = 0;
                break;
            }
            mainGame.gabarito.push_back(number);
        }
        if (stop)
        {
            mainGame.validaGame();
        }
        cout << "\n";
    }

    return 1;
}

int main()
{
    while (getInput())
    {
        //getInput();
        //mainGame.showValores();
        //mainGame.inicia();
        //mainGame.validaGame();
    }
    return 0;
}