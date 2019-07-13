cmake_minimum_required(VERSION 3.12)
project(AbbreviationCL)

set(CMAKE_CXX_STANDARD 14)

add_executable(AbbreviationCL main.cpp include/FileProcessing.h include/AbstractAlgorithm.h include/SearchAlgorithm.h source/FileProcessing.cpp source/SearchAlgorithm.cpp)