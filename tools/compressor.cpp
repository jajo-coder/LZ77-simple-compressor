#include <"lz77.hpp">

int main(int argc, char* argv[]) {

	// checking the command line parameters 
	// we should have only one, the name of the file in test directory
	if(argc - 1 > 1) {
		std::cout << "error: the sintax of the command is wrong" << std::endl;
		printHelp();
		return 1;
	}

	// 
}

void printHelp() {

	std::cout << "format: ./compressor [param]" << std::endl;
	std::cout << "the [param] can be either a file path or an help request like '-h' or '--help" << std::endl;

}