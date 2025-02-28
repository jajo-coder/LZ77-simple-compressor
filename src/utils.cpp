#include <"lz77.hpp">

void printHelp(const std::string command) {

	if(command == "c") {
		// compress tool usage explanation
		std::cout << "format: ./compressor [param]" << std::endl;
		std::cout << "the [param] can be either a .txt file path or an help request like '-h' or '--help" << std::endl;
	}
		else {
			// decompress tool usage explanation
			std::cout << "format: ./decompressor [param]" << std::endl;
			std::cout << "the [param] can be either a .lz77 file path or an help request like '-h' or '--help" << std::endl;
		}
}

bool validArgumentNumber(const std::string command, int argc) {

	// checking the command line parameters 
	// we should have only one, the name of the file in test directory
	if(argc - 1 > 1) {
		std::cerr << "error: the sintax of the command is wrong" << std::endl;
		printHelp(command);
		return 1;
	}

}

bool isFilePathWellFormatted(const std::string filename, const std::string matchExtension) {

	// checking if the file path is correct
	std::ifstream file(filename);
    if(!file.good()) return false;

    // checking if the extension is the desired one
    return getFileExtension(filename) == matchExtension;

}

std::string getFileExtension(const std::string filename) {
	return filename.substr(filename.find_first_of('.'));
}

std::string getFileContent(const std::ifstream file) {

	// reading the file and appending the content to the stream
	std::string content;
	char ch;
	while(file.get(ch)) content.push_back(ch);

	return content;

}

bool createFileAndSetContent(const std::string originalFilename, const std::string content) {

	// getting the filename to determine matching output filename and extension
	// file.txt -> file.lz77
	// file.lz77 -> file_decompressed.txt
	std::string newFilename = originalFilename.substr(0, originalFilename.find_first_of('.'));
	if(getFileExtension(originalFilename) == ".txt") newFilename += ".lz77";
		else newFilename += ".txt";

}