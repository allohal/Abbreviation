////////////////////////////////////////////////////////////////////////
////////////////////ПРОСТЕЙШИЕ//////АББРЕВИАТУРЫ////////////////////////
////////////////////////////////////////////////////////////////////////

#include "SimpleAlgorithm.hpp"
#include <algorithm>
#include <string>
#include <map>

bool predRus(std::string &a) {
	return (a[0] == '(' && a[1] >= 'А' && a[1] <= 'Я');
}
bool predEng(std::string &a) {
	return (a[0] == '(' && a[1] >= 'A' && a[1] <= 'Z');
}



void SimpleAlgorithm::searchRus(std::vector<std::string> &v) {
	std::map<std::string, std::string> m;
	auto m_it = m.begin();
	std::string word_abbr;

	for (auto it = v.begin(); it != v.end(); it++) {
		
		auto it2 = find_if(it, v.end(), predRus);

		for (auto it3 = it2-(it2->size()-2); it3 != it2; it3++) {
			word_abbr += (*it3) + " ";
		}

		m.insert({ *it2, word_abbr });
		word_abbr="";
	}
	for (auto c : m){
		std::cout << "first:" << c.first << std::endl;
	std::cout << "second:" << c.second << std::endl;
}
}

void SimpleAlgorithm::searchEng(std::vector<std::string> &v) {
std::map<std::string, std::string> m;
auto m_it = m.begin();
std::string word_abbr;

for (auto it = v.begin(); it != v.end(); it++) {
	auto it2 = find_if(it, v.end(), predEng);
	for (auto it3 = it2 - (it2->size() - 2); it3 != it2; it3++) {
		word_abbr += (*it3) + " ";
	}

	m.insert({ *it2, word_abbr });
	word_abbr = "";
}
for (auto c : m) {
	std::cout << "first:" << c.first << std::endl;
	std::cout << "second:" << c.second << std::endl;
}
}












/*void SimpleAlgorithm::searchRus(std::vector<std::string> &v) {
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		auto it = find_if(iter, v.end()-1, predRus);

		abbr = *it;
		abbr.erase(abbr.begin());     //удаление скобки (
		abbr.pop_back();              //удаление скобки )

		wordsCount = abbr.size();

		std::string transcription;

		for (auto i = it - wordsCount; i < it; i++) {
			transcription += *i + " ";
		}
		std::cout << transcription << std::endl;
		std::cout << abbr << " " << wordsCount << std::endl; //занести в БД
	}
};
*/
/*void SimpleAlgorithm::searchEng(std::vector<std::string> &v) {
	for (auto it = v.begin(); it <v.end() - 1; ) {
		it = find_if(it + 1, v.end()-1, [](std::string a) -> bool {       //поиск аббревиатуры "(ххх)"
			return a[0] == '(' && a[1] >= 'A' && a[1] <= 'Z';
		});

		abbr = *it;
		abbr.erase(abbr.begin());     //удаление скобки (
		abbr.pop_back();              //удаление скобки )

		wordsCount = abbr.size();

		std::string transcription;

		for (auto i = it - wordsCount; i < it; i++) {
			transcription += *i + " ";
		}
		std::cout << transcription << std::endl;
		std::cout << abbr << " " << wordsCount << std::endl; //занести в БД

	}
};*/

void SimpleAlgorithm::search(std::vector<std::string> &v) {
	std::cout << "Vector size: " << v.size() << std::endl;
	std::cout << "\n-------------------------------------------" << std::endl;
	std::cout << "Russian: " << std::endl;
	searchRus(v);
	std::cout << "\n-------------------------------------------" << std::endl;
	std::cout << "English: " << std::endl;
	searchEng(v);
}