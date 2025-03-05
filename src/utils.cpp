#include "lz77.hpp"

void printHelp(char command) {

	if(command == 'c') {
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

bool validArgumentNumber(char command, int argc) {

	// checking the command line parameters 
	// we should have only one, the name of the file in test directory
	if(argc - 1 > 1) {
		std::cerr << "error: the sintax of the command is wrong" << std::endl;
		printHelp(command);
		return false;
	}

	return true;

}

bool isFilePathWellFormatted(const std::string& filename, const std::string& matchExtension) {
    std::cout << "Checking file: " << filename << std::endl;

    // Check if the file exists and can be opened
    std::ifstream file(filename);
    std::cout << std::flush;
    if (!file.good()) {
        std::cerr << "Error: The file does not exist or the filename is not well formatted: " << filename << std::endl;
        return false;
    }
    file.close();

    std::cout << "File opened successfully." << std::endl;

    // Check if the extension matches
    std::string extension = getFileExtension(filename);
    bool retValue = (extension == matchExtension);
    if (!retValue) {
        std::cerr << "Error: The extension does not match the desired one (" << matchExtension << "). Found: " << extension << std::endl;
    }

    return retValue;
}

/*
bool isFilePathWellFormatted(const std::string& filename, const std::string& matchExtension) {

	std::cout << "hi there" << std::endl;

	// checking if the file path is correct
	std::ifstream file(filename);
    if(!file.good()) {
    	std::cerr << "error: the file does not exist or the filename is not well formatted" << std::endl;
    	return false;
    }
    file.close();

    std::cout << "hi here" << std::endl;

    // checking if the extension is the desired one
    bool retValue = getFileExtension(filename) == matchExtension;
    if(!retValue) std::cerr << "error: the extension does not match with the desired one (" << matchExtension << ")" << std::endl;
    std::cerr << filename << std::endl;

    return retValue;

}
*/

std::string getFileName(const std::string& filename) {
	return filename.substr(filename.find_last_of('/'));
}

std::string getFileExtension(const std::string& filename) {
	return filename.substr(filename.find_first_of('.'));
}

bool getFileContent(const std::string& filename, std::string& content) {

	// initializing the filestream and content
	std::ifstream file(filename);
	content = "";

	// checking if there are any errors in file opening
	if(!fileCanBeOpenedCorrectly(filename, false)) return false;

	// reading the file and appending the content to the stream
	char ch;
	while(file.get(ch)) content.push_back(ch);

	file.close();
	return true;

}

bool fileCanBeOpenedCorrectly(const std::string& filename, bool writeMode) {

	// variable storing the output value
	bool output;

	// after opening the file in the correct way (read/write) i check if it opens correctly
	if(writeMode) {

		std::ofstream file(filename, std::ios::app);
        if(!file.is_open()) output = false;
        	else output = true;

        file.close();

    } 
	    else {

	        std::ifstream file(filename);
	        if(!file.is_open()) output = false;
	        	else output = true;

	        file.close();

	    }

	std::cerr << "error: file opening failed" << std::endl;
	return output;

}

bool createFileAndSetContent(const std::string& originalFilename, const std::vector<std::pair<int, int>>& content) {

	// getting the filename to determine matching output filename and extension
	// file.txt -> file.lz77
	// file.lz77 -> file_decompressed.txt
	std::string newFilename = "./test/" + getFileName(originalFilename);
	if(getFileExtension(originalFilename) == ".txt") newFilename += ".lz77";
		else newFilename += "_decompressed.txt";

	// creating the new file and checking if there are any problems in opening it
	std::ofstream file(newFilename);

	// checking if there are any errors in file opening
	if(!fileCanBeOpenedCorrectly(newFilename, false)) return false;

	// writing the content in the file
	file << getStringFromCompressedContent(content);

	// closing the file
	file.close();

	// successful output return value
	return true;

}

bool createFileAndSetContent(const std::string& originalFilename, const std::string& content) {

	// getting the filename to determine matching output filename and extension
	// file.txt -> file.lz77
	// file.lz77 -> file_decompressed.txt
	std::string newFilename = "./test/" + getFileName(originalFilename);
	if(getFileExtension(originalFilename) == ".txt") newFilename += ".lz77";
		else newFilename += "_decompressed.txt";

	// creating the new file and checking if there are any problems in opening it
	std::ofstream file(newFilename);

	// checking if there are any errors in file opening
	if(!fileCanBeOpenedCorrectly(newFilename, false)) return false;

	// writing the content in the file
	file << content;

	// closing the file
	file.close();

	// successful output return value
	return true;

}

std::string getStringFromCompressedContent(const std::vector<std::pair<int, int>>& content) {

	// getting the corresponding string from compressed content
	std::string contentString = "";

	for(auto pair : content)
		contentString += std::to_string(pair.first) + "," + std::to_string(pair.second) + ";";


	return contentString;
}


std::vector<std::pair<int, int>> getCompressedObjectFromString(const std::string& content) {

	// initializing the object that will contain the compressed content
	std::vector<std::pair<int, int>> v;

	// divinding the string in pairs
	size_t semicolIndex = 0;

	while(semicolIndex != content.size() - 1) {

		// finding the index of the semicolumn after the data of the next pair
		size_t nextSemicolIndex = content.find(semicolIndex);

		// getting the substring of the current pair
		std::string pairString = content.substr(semicolIndex + 1, nextSemicolIndex - 1);

		// generating the new pair and appending it to the vector
		int commaIndex = pairString.find(',');
		int firstValue = std::stoi(pairString.substr(0, commaIndex - 1));
		int secondValue = std::stoi(pairString.substr(commaIndex + 1));

		std::pair<int, int> pair = std::make_pair(firstValue, secondValue);
		v.push_back(pair);
	}

	return v;

}