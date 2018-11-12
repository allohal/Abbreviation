#pragma once
////////////////////////////////////////////////////////////////////////
////////////////////œ–Œ—“≈…ÿ»≈//////¿¡¡–≈¬»¿“”–€////////////////////////
////////////////////////////////////////////////////////////////////////

#include "AbstractAlgorithm.hpp"

class SimpleAlgorithm : public AbstractAlgorithm {
public:
	void search(std::vector<std::string>& v);

private:
	int wordsCount;
	std::string abbr;
	void searchRus(std::vector<std::string>& v);
	void searchEng(std::vector<std::string>& v);
};