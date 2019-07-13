//
// Created by lipin on 13.07.2019.
//

#ifndef ABBREVIATIONCL_SEARCHALGORITHM_H
#define ABBREVIATIONCL_SEARCHALGORITHM_H

#include "AbstractAlgorithm.h"

class SearchAlgorithm : public AbstractAlgorithm {
public:
    map search(std::vector<std::string> &text_from_file) override;
    map searchAlgorithmFunction(std::vector<std::string> &text, const bool &language) override;
private:
    map output_map;
    map output_map_rus;
    map output_map_eng;
};

#endif //ABBREVIATIONCL_SEARCHALGORITHM_H
