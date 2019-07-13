#include "FileProcessing.hpp"

std::vector<std::string> &FileProcessing::readFile(const std::string &input_path) {
	std::ifstream file_input_stream(input_path);
	if (file_input_stream) {
		std::cout << "\nInput file is opened\n" << std::endl;

		// read word by word from file to string
		while (file_input_stream >> word) {
			text_on_one_string += word + " ";
		}
		// replace all '-' to space on the string
		replace (text_on_one_string.begin(), text_on_one_string.end(), '-', ' ');

		// and then read and push_back word by word from this string(without '-');
		std::stringstream str_stream(text_on_one_string);
		while (str_stream >> word) {
			vector_with_text.push_back(word);
		}
	} else {
		std::cerr << "Input file isn`t opened" << std::endl;
	}
	std::cout << "\n";
	file_input_stream.close();
	return vector_with_text;
}

void FileProcessing::writeFile(const std::string &output_path) {

	std::ofstream file_output_stream(output_path);
	// start algorithm of searching the abbreviations and get the map with them and them transcript
    map_with_abbrs = searchAlgorithm.search(readFile(file_name_in));

	if (file_output_stream) {
		std::cout << "Output file is opened\n " << std::endl;

		for (const auto &map_pair : map_with_abbrs) {
			file_output_stream << "Transcript: " << map_pair.first << "\n";
			file_output_stream << "Abbreviation: " << map_pair.second << "\n";
			file_output_stream << "\n";
		}
	} else {
		std::cerr << "File isn`t opened" << std::endl;
	}
	std::cout << "\n";
	file_output_stream.close();
}

// setters and getters defination
void FileProcessing::setInputFileName(const std::string &input) {
	file_name_in = input;
}

void FileProcessing::setOutputFileName(const std::string &output) {
	file_name_out = output;
}

const std::string FileProcessing::getInputFileName() {
	return file_name_in;
}

const std::string FileProcessing::getOutputFileName() {
	return file_name_out;
}