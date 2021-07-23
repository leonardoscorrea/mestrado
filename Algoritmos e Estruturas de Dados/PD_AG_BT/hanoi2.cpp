#include <iostream>
#include <cmath>

// over //
using namespace std;
int array[51];
int total, N; //contador_steps=0;

void calcula(int v, int p)
{
    //contador_steps++;
    if (p == N)
        return;

    if (array[p] == 0)
    {
        array[p] = v;
        total++;
        //  contador_steps++;
        return calcula(v + 1, p);
    }
    for (int i = 0; i <= p; i++)
    {
        int raiz = (int)sqrt(array[i] + v); // verifica se a soma das bolas formam um numero de quadrado perfeito//
        if (pow(raiz, 2) == array[i] + v)
        {
            array[i] = v;
            total++;
            // contador_steps++;
            return calcula(v + 1, p);
        }
    }
    calcula(v, p + 1);
}

int main()
{
    int testes;
    cin >> testes;
    for (int i = 0; i < testes; i++)
    {
        cin >> N;
        for (int i = 0; i < 50; i++)
            array[i] = 0; //preenche o vetor 'array' com o valor 0//
        total = 0;
        // contador_steps=0;
        calcula(1, 0);
        cout << total << endl;
        // cout <<"Execucoes: "<< contador_steps<<endl;
    }
    return 0;
}