#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstdlib> 

// functions for src/compress.cpp
std::vector<std::pair<int, int>> compress(const std::string&);

// functions for src/decompress.cpp
std::string decompress(const std::vector<std::pair<int, int>>);

// functions for src/utils.cpp
void printHelp(char);
bool validArgumentNumber(char, int);
bool isFilePathWellFormatted(const std::string&, const std::string&);
bool getFileContent(const std::string&, std::string&);
std::string getFileExtension(const std::string&);
bool fileCanBeOpenedCorrectly(const std::string&, bool);
bool createFileAndSetContent(const std::string&, const std::vector<std::pair<int, int>>&);
bool createFileAndSetContent(const std::string&, const std::string&);
std::string getStringFromCompressedContent(const std::vector<std::pair<int, int>>&);
std::vector<std::pair<int, int>> getCompressedObjectFromString(const std::string&);