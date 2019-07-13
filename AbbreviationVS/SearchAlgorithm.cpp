#include "SearchAlgorithm.hpp"

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

map SearchAlgorithm::searchAlgorithmFunction(std::vector<std::string> &text, const bool &language) {

	abbr_map.clear();

	for (auto it = text.begin(); it != text.end(); ++it) {
		std::vector<std::string>::iterator abbr;
		// abbr get iterator to the word, that suit under the abbreviation
		if (language == 0) {
			abbr = find_if(it, text.end(), rus_abbr_check);
		} else if (language == 1) {
			abbr = find_if(it, text.end(), eng_abbr_check);
		}
		// if the abbreviatons runs out, abbr get iterator for the end of text, and we stop work
		if (abbr != text.end()) {
			// if captured abbreviation has a special symbols after it, we remove it
			if (*(abbr->end() - 1) == ',' || *(abbr->end() - 1) == '.' || *(abbr->end() - 1) == '!' || *(abbr->end() - 1) == '?') {
				abbr->erase(abbr->end() - 1);
		}
			// remove two brackets at the end and at the beginning
			abbr -> erase(abbr -> begin());
			abbr -> erase(abbr -> end() - 1);

			auto save_abbr = abbr;	
			unsigned int size = abbr -> size();
			
			// char deque with the first letters of the transcript words to find out if the amount of letters
			//   abbreviation and the amount of words are not equal
			//      to choose the right beginning to save correct transcript
			std::deque<char> transcript_first_letters;
			for (abbr -= size; abbr != save_abbr; ++abbr) {
				transcript_first_letters.push_back(toupper( abbr -> at(0) ));
				}

			int additional_count = 0;
			while (*transcript_first_letters.begin() != save_abbr->at(0)) {
				++additional_count;
				transcript_first_letters.push_front(toupper(( abbr-size-additional_count) -> at(0) ));
			}

			// return an iterator abbr for *size* and *additional_count* iterations to match abbreviation and transcript
			for (abbr = abbr - size - additional_count; abbr != save_abbr; ++abbr) {
				transcript += (*abbr) + " ";
			}	
				abbr_map.insert( { transcript, *abbr } );
				transcript.clear();
				transcript_first_letters.clear();
			}
		}

	return abbr_map;
}

// a function that runs the search algorithms for different languages and returns a map
map SearchAlgorithm::search(std::vector<std::string> &text_from_file) {

	output_map_rus = searchAlgorithmFunction(text_from_file, 0);
	output_map_eng = searchAlgorithmFunction(text_from_file, 1);

	output_map.insert(output_map_eng.begin(), output_map_eng.end());
	output_map.insert(output_map_rus.begin(), output_map_rus.end());

	return output_map;
}