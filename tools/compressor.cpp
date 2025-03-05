#include "lz77.hpp"

int main(int argc, char* argv[]) {

	// converting char* to std::string
	std::string parameter = argv[1];

	// checking the arguments and if help on parameter is requested
	if(!validArgumentNumber('c', argc)) return 1;
	if(parameter == "-h" || parameter == "--help") { 
		printHelp('c'); 
		return 0; 
	}

	std::cout << "before path check: " << parameter << std::endl;

	std::cout << isFilePathWellFormatted(parameter, ".txt") << std::endl;

	// checking the file path format correctness and its existance
	if(!isFilePathWellFormatted(parameter, ".txt")) return 1;

	std::cout << "after path check" << std::endl;

	// initializing the filestream and the string containing the content
	std::string content;

	// filling the content string
	if(!getFileContent(parameter, content)) return 1;

	// compressing the file
	std::vector<std::pair<int, int>> compressed = compress(content);

	// writing this compressed content inside a file.lz77
	if(!createFileAndSetContent(parameter, compressed)) return 1;

	// successful output return value
	return 0;

}