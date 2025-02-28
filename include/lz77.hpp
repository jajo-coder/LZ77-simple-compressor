#include <iostream>
#include <fstream>
#include <vector>
#include <utility>

// functions for src/compress.cpp
std::vector<std::pair<int, int>> compress(const std::string&);

// functions for src/decompress.cpp
void decompress(const std::vector<std::pair<int, int>>);

// functions for src/clah.cpp
bool validArgumentNumber(const std::string, int);
void printHelp(const std::string);
bool isFilePathWellFormatted(const std::string, const std::string);
std::string getFileContent(const std::ifstream file);