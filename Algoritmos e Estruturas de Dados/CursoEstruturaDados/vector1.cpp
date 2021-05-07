#include <iostream>
#include <vector> //Biblioteca para usar o vector
#include <algorithm>

using namespace std;

int main(){
	vector<int> V; //Criação do variável vector

	V.push_back(10); //Adiciono o elemento 10 no final do vector V
	V.push_back(7); //Adiciono o elemento 7 no final do vector V
	V.push_back(21); //Adiciono o elemento 21 no final do vector V

	for(int i=0;i<(int)V.size();i++){ //Passo por cada elemento do vector V
		cout<<V[i]<<"\n"; //Imprimir cada elemento do vector V
	}
	//V.resize(10); //Muda o tamanho do vector V para 10.
	//V.pop_back(); //Apaga o ultimo elemento do vector V.
	//V.clear(); //Remove todos os elementos do vector V.
	sort(V.begin(), V.end()); //Ordena todo o vector V, deixando os elementos na seguinte ordem {2, 4, 5, 10}.
	
	for(int i=0;i<(int)V.size();i++){ //Passo por cada elemento do vector V
		cout<<V[i]<<"\n"; //Imprimir cada elemento do vector V
	}

}
