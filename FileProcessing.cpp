#include "FileProcessing.hpp"

std::vector<std::string> FileProcessing::readFile(const std::string &path) {
	std::ifstream file_input_stream(path);
	if (file_input_stream) {
		std::cout << "File is opened\nText: " << std::endl;

		// read word by word from file to string
		while (file_input_stream >> word) {
			text_on_one_string += word + " ";
		}
		// replace all '-' to space on the string
		replace(text_on_one_string.begin(), text_on_one_string.end(), '-', ' ');

		// and then read and push_back word by word from this string(without '-');
		std::stringstream str_stream(text_on_one_string);
		while (str_stream >> word) {
			std::cout << word << " ";
			vector_with_text.push_back(word);
		}
	}
	else {
		std::cerr << "File isn`t opened" << std::endl;
	}
	std::cout << "\n";
	file_input_stream.close();
	return vector_with_text;
}