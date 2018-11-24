#ifndef ABBREVIATION_SEARCHALGORITHM_HPP_
#define ABBREVIATION_SEARCHALGORITHM_HPP_

#include "AbstractAlgorithm.hpp"

class SearchAlgorithm : public AbstractAlgorithm {
  public:
	map search(std::vector<std::string> &text_from_file) override;
	map searchAlgorithmFunction(std::vector<std::string> &text, const bool &language) override;
  private:
	map output_map;
	map output_map_rus;
	map output_map_eng;
};
#endif 