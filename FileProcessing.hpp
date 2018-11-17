#ifndef ABBREVIATION_FILEPROCESSING_HPP_
#define ABBREVIATION_FILEPROCESSING_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

class FileProcessing {
public:
	std::vector<std::string> readFile(const std::string &path);

	std::vector<std::string> vector_with_text;

private:
	std::string word;
	std::string text_on_one_string;
};

#endif