//
// Created by lipin on 13.07.2019.
//

#ifndef ABBREVIATIONCL_ABSTRACTALGORITHM_H
#define ABBREVIATIONCL_ABSTRACTALGORITHM_H

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


#endif //ABBREVIATIONCL_ABSTRACTALGORITHM_H
