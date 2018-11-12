#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "vector"

class FileProcessing {
public:
	std::vector <std::string> readFile(const std::string &path);
private:
	std::string str;
	std::vector<std::string> words;
};