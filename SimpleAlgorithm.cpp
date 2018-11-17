////////////////////////////////////////////////////////////////////////
////////////////////ÏÐÎÑÒÅÉØÈÅ//////ÀÁÁÐÅÂÈÀÒÓÐÛ////////////////////////
////////////////////////////////////////////////////////////////////////

#include "SimpleAlgorithm.hpp"

// boolean predicate for algorithm
bool rus_abbr_check(const std::string &word) {
	bool bool_check = false;
	const char first_symbol = word[0];
	const char second_symbol = word[1];

	if (first_symbol == '(' && second_symbol >= 'À' && second_symbol <= 'ß')
		bool_check = true;
	
	return bool_check;
}

// boolean predicate for algorithm
bool eng_abbr_check(const std::string &word) {
	bool bool_check = false;
	const char first_symbol = word[0];
	const char second_symbol = word[1];

	if (first_symbol == '(' && second_symbol >= 'A' && second_symbol <= 'Z')
		bool_check = true;

	return bool_check;
}

void SimpleAlgorithm::searchSimpleAbbr(std::vector<std::string> &text,const bool &language) {
	abbr_map.clear();

	for (auto it = text.begin(); it != text.end(); it++) {
		std::vector<std::string>::iterator abbr;
		// abbr get iterator to the word, that suit under the abbreviation
		if (language == 0)
			abbr = find_if(it, text.end(), rus_abbr_check);
		else if(language == 1)
			abbr = find_if(it, text.end(), eng_abbr_check);

		// if the abbreviatons runs out, abbr get iterator for the end of text, and we stop work
		if (abbr != text.end()) {  
			// if captured abbreviation has a special symbols after it, we remove it
			if (*(abbr->end() - 1) == ',' || *(abbr->end() - 1) == '.' || *(abbr->end() - 1) == '!' || *(abbr->end() - 1) == '?')
				abbr->erase(abbr->end() - 1);

			// remove two brackets at the end and at the beginning
			abbr->erase(abbr->begin());
			abbr->erase(abbr->end() - 1);

			auto save_abbr = abbr;	
			unsigned int size = abbr->size();

			// return an iterator abbr for /size/ iterations to match abbreviation and transcript
			for (abbr -= size; abbr != save_abbr; abbr++) { 
				transcript += (*abbr) + " ";
			}
				abbr_map.insert({ transcript, *abbr });
				transcript.clear();
			}
		}

	for (const auto &pair : abbr_map){
		std::cout << "Transcript: " << pair.first << std::endl;
		std::cout << "Abbreviation: " << pair.second << std::endl;
		std::cout << std::endl;
	}
}

void SimpleAlgorithm::search() {
	
	text = file_proc.readFile("text.txt");

	std::cout << "\nVector size: " << text.size() << std::endl;
	std::cout << "\n-------------------------------------------" << std::endl;

	std::cout << "Russian: \n" << std::endl;
	searchSimpleAbbr(text, 0);

	std::cout << "\n-------------------------------------------" << std::endl;
	std::cout << "English: \n" << std::endl;
	searchSimpleAbbr(text, 1);
}











/*
void SimpleAlgorithm::searchEng(std::vector<std::string> &text) {
std::map<std::string, std::string> abbr_map;
std::string transcript;

for (auto it = text.begin(); it != text.end(); it++) {

auto abbr = find_if(it, text.end(), eng_abbr_check);

if (abbr != text.end()) {

if (*(abbr->end() - 1) == ',' || *(abbr->end() - 1) == '.' || *(abbr->end() - 1) == '!' || *(abbr->end() - 1) == '?')
abbr->erase(abbr->end() - 1);

abbr->erase(abbr->begin());
abbr->erase(abbr->end() - 1);

auto save_abbr = abbr;
unsigned int size = abbr->size();

for (abbr -= size; abbr != save_abbr; abbr++) {
transcript += (*abbr) + " ";
}
abbr_map.insert({ transcript, *abbr });
transcript.clear();
}
}

for (const auto &pair : abbr_map) {
std::cout << "Transcript: " << pair.first << std::endl;
std::cout << "Abbreviation: " << pair.second << std::endl;
std::cout << std::endl;
}
}
*/