#include <"lz77.hpp">

int main(int argc, char* argv[]) {

	// checking the arguments and if help on parameter is requested
	if(!validArgumentNumber("c", argc)) return 1;
	if(argv[1] == "-h" || argv[1] == "--help") { 
		printHelp("c"); 
		return 0; 
	}

	// checking the file path format correctness and its existance
	if(!isFilePathWellFormatted(argv[1], ".lz77")) return 1;

	// initializing the filestream and the string containing the content
	std::string content;

	// filling the content string
	if(!getFileContent(argv[1], content)) return 1;

	// compressing the file
	decompressed = decompress(content);

	// writing this compressed content inside a file.lz77
	if(!createFileAndSetContent(argv[1], decompressed)) return false;

	// successful output return value
	return 0;

}