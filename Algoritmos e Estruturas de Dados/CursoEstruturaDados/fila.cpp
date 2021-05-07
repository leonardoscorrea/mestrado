#include <iostream>
#include <vector> //Biblioteca para usar o vector
#include <algorithm>
#include <sstream>

#define SHOW_IDENTIFIERS 0

using namespace std;
int numberOfMembers = 0, qtyTakeOut = 0;
vector<int> members, membersTakeOut;


void showMembers(){
    int first = 1;
    for(int i=0;i<(int)members.size();i++){
        if(first){
            cout<<members[i];
            first = 0;
		} else {
            cout<<' '<<members[i];
        }
	}
}

void identifiers(string s){
    if(SHOW_IDENTIFIERS){
        std::cout << s;
    }
}

void getInput(){
    std::string line;
    int number;


    identifiers("Número de pessoas: ");
    std::getline(std::cin, line);
    numberOfMembers = std::stoi(line);

    identifiers("Identificadores das pessoas da fila: ");
    std::getline(std::cin, line);
    std::istringstream stream(line);
    while (stream >> number)
        members.push_back(number);

	identifiers("Número de pessoas a deixar a fila: ");
    std::getline(std::cin, line);
    qtyTakeOut = std::stoi(line);

    identifiers("Identificadores das pessoas que devem deixar a fila: ");
    std::getline(std::cin, line);
    std::istringstream stream2(line);
    while (stream2 >> number)
        membersTakeOut.push_back(number);
}

void removeElement(int value){
    members.erase(find(members.begin(),members.end(),value));
}

void takeoutMembers(){
    for(int i=0;i<(int)membersTakeOut.size();i++){
		removeElement(membersTakeOut[i]);
	}
}





int main(){
	vector<int> V;
	getInput();
	takeoutMembers();
	showMembers();
    return 0;
}
