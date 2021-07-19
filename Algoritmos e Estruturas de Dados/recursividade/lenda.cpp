#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <bits/stdc++.h>

#define SHOW_IDENTIFIERS 0
#define SHOW_WIN_BY_GAME 0

using namespace std;

void identifiers(string s)
{
    if (SHOW_IDENTIFIERS)
    {
        std::cout << s << "\n";
    }
}

vector<int> lenda(vector<int> valores, int inicio, int fim, int passo, int incremento)
{
    if (valores.size() == 1)
    {
        return valores;
    }
    else if (valores.size() > passo)
    {
        for (int i; i < (valores.size() / passo); i++)
        {
            int start = inicio + passo * i;
            int end = start + passo - 1;
            lenda(valores, start, end, passo, incremento);
        }
    }
    else
    {
    }
    //b.insert(b.end(), a.begin(), a.end());
}

int josephus(int n, int k)
{
    if (n == 1)
        return 0;
    if (k == 1)
        return n - 1;
    if (k > n)
        return (josephus(n - 1, k) + k) % n;
    int cnt = n / k;
    int res = josephus(n - cnt, k);
    res -= n % k;
    if (res < 0)
        res += n;
    else
        res += res / (k - 1);
    return res;
}

void lenda2(vector<int> valores, int passo, int incremento)
{
    int x, inc = 0, j = 1;
    if (valores.size() == 1)
    {
        cout << valores[0] << "\n";
    }
    else
    {
        vector<int> rem;
        x = (j * passo) - 1 - incremento;
        while (x < valores.size())
        {
            //cout << "indice: " << x << "\n";
            rem.push_back(x);
            j++;
            x = (j * passo) - 1 - incremento;
            if (x >= valores.size())
            {
                inc = valores.size() - (((j - 1) * passo) - 1 - incremento) - 1;
                //cout << "incremento: " << inc << "\n";
            }
        }
        //
        sort(rem.begin(), rem.end(), greater<int>());

        for (int i = 0; i < rem.size(); i++)
        {
            valores.erase(valores.begin() + rem[i]);
        }
        //cout << "tamanho: " << valores.size() << "\n";
        lenda2(valores, passo, inc);
    }
}

int outra(int n, int m)
{
    int x;
    for (int i = 1; i <= n; i++)
    {
        x = m * i;                           // se n fosse infinito seria a i-esima pessoa a ser morta
        while (x > n)                        // ajusta x enquanto x > n
            x = (m * (x - n) - 1) / (m - 1); // arredonda para baixo!
        printf("%d, ", x);
    }
    return x;
}

int outra2(int pessoaMorrer, int qtdPessoa, int passo)
{
    int suicidou = passo * pessoaMorrer;
    if (pessoaMorrer == qtdPessoa)
    {
        while (suicidou > qtdPessoa)
            suicidou = (passo * (suicidou - qtdPessoa) - 1) / (passo - 1);
        return suicidou;
    }

    while (suicidou > qtdPessoa)
        suicidou = (passo * (suicidou - qtdPessoa) - 1) / (passo - 1);

    //return */
    return outra2(pessoaMorrer++, qtdPessoa, passo);
}

void imprimeVetor(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

vector<int> inicializaVetor(int tamanho)
{
    vector<int> v;
    for (int i = 1; i <= tamanho; i++)
    {
        v.push_back(i);
    }
    return v;
}

int getInput()
{
    int number, pessoas, passo;
    string line;
    string suit;

    identifiers("[quantidade de testes]: ");
    if (std::getline(std::cin, line))
    {
        std::istringstream stream(line);
        stream >> number;
    }

    identifiers("[pessoas] [passo]: ");
    for (int i; i < number; i++)
    {
        std::getline(std::cin, line);
        std::istringstream stream(line);
        stream >> pessoas;
        stream >> passo;
        //lenda2(inicializaVetor(pessoas), passo, 0);

        cout << pessoas << " = " << passo << " = " << outra2(1, pessoas, passo) << "\n";
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