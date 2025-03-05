#include "lz77.hpp"

std::string decompress(const std::vector<std::pair<int, int>> v) {

	// initializing the string containing the result
	std::string s;

	// reading the vector and appending chars
	for(auto pair : v) {
		// checking if the current pair is of the kind (0, character)
		if(pair.first == 0) s.push_back(pair.second);
			else for(int i = 0; i < pair.first; i++) s.push_back(s.at(pair.second));
	}

	return s;

}