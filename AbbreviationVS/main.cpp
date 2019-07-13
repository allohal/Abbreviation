#include "FileProcessing.hpp"

int main() {
	setlocale(LC_ALL, "Russian");

	FileProcessing open_file;

	// input of the input and output file`s name
	std::cout << "Enter correct input file`s name: ";
	std::cin >> open_file.file_name;
	open_file.setInputFileName(open_file.file_name);

	std::cout << "\nEnter correct output file`s name: ";
	std::cin >> open_file.file_name;
	open_file.setOutputFileName(open_file.file_name);

	// run the algorithm to write to the file
	open_file.writeFile(open_file.getOutputFileName());

	return 0;
}