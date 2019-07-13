#ifndef ABBREVIATION_ABSTRACTALGORITHM_HPP_
#define ABBREVIATION_ABSTRACTALGORITHM_HPP_

#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using map = std::map<std::string, std::string>;  //alias

class AbstractAlgorithm {
  protected:
	//virtual functions
	virtual map search(std::vector<std::string> &text_from_file) = 0; 
	virtual map searchAlgorithmFunction (std::vector<std::string> &text, const bool &language) = 0;

	virtual ~AbstractAlgorithm() = default; // virtual destructor

	map abbr_map;
	std::string transcript;

};

#endif