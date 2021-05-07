#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char** argv) {

    std::string line;
    int number;
    std::vector<int> numbers;

    std::cout << "Enter numbers separated by spaces: ";
    std::getline(std::cin, line);
    std::istringstream stream(line);
    while (stream >> number)
        numbers.push_back(number);

	for(int i=0;i<(int)numbers.size();i++){ //Passo por cada elemento do vector V
		std::cout<<numbers[i]<<"\n"; //Imprimir cada elemento do vector V
	}

}
