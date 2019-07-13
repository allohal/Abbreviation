//
// Created by lipin on 13.07.2019.
//

#ifndef ABBREVIATIONCL_FILEPROCESSING_H
#define ABBREVIATIONCL_FILEPROCESSING_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "SearchAlgorithm.h"

class FileProcessing {
public:
    std::vector<std::string> &readFile(const std::string &input_path);
    void writeFile(const std::string &output_path);

    // setters and getters declaration
    void setInputFileName(const std::string &input_file_name);
    void setOutputFileName(const std::string &output_file_name);
    const std::string getOutputFileName();
    const std::string getInputFileName();

    std::string file_name;

private:
    SearchAlgorithm searchAlgorithm;  //for composition relation with SearchAlgorithm

    map map_with_abbrs;
    std::string file_name_out;
    std::string file_name_in;
    std::string word;
    std::string text_on_one_string;
    std::vector<std::string> vector_with_text;
};

#endif //ABBREVIATIONCL_FILEPROCESSING_H
