#ifndef ABBREVIATION_ABSTRACTALGORITHM_HPP_
#define ABBREVIATION_ABSTRACTALGORITHM_HPP_

////////////////////////////////////////////////////////////////////////
///////////////¿¡—“–¿ “Õ€…///ƒÀﬂ///œŒ»— ¿///¿¡¡–≈¬»¿“”–/////////////////
////////////////////////////////////////////////////////////////////////

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include "FileProcessing.hpp"


class AbstractAlgorithm {
protected:
	std::map<std::string, std::string> abbr_map;
	std::string transcript;

	FileProcessing file_proc;
	std::vector<std::string> text;

	virtual void search() = 0;
};

#endif