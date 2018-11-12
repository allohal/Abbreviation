#include "FileProcessing.hpp"

std::vector<std::string> FileProcessing::readFile(const std::string &path) {
	std::ifstream fin(path);
	if (fin) {
		std::cout << "File is opened" << std::endl;
		std::cout << "Text: " << std::endl;
		while (fin >> str) {
			std::cout << str;
			words.push_back(str);
		}
	}
	else {
		std::cout << "File isn`t opened" << std::endl;
	}
	std::cout << "\n";
	fin.close();
	return words;
}