#include <iostream>
#include <fstream>
#include <string>
 
int main() {
	std::string line;
	std::istream& is = std::cin;
 
	while(std::getline(is, line)) {
		std::cout << line << std::endl;
	}
	return 0;
}