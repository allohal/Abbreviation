#include <iostream>
#include <fstream>

#include "FileProcessing.hpp"
#include "SimpleAlgorithm.hpp"

int main() {
	setlocale(LC_ALL, "Russian");

	FileProcessing fp;
	std::vector<std::string> vect;
	vect = fp.readFile("text.txt");

	
	SimpleAlgorithm simple;
	simple.search(vect);



	return 0;
}