#include <"lz77.hpp">

std::vector<std::pair<int, int>> compress(const std::string& s) {

	// initializing the output vector
	std::vector<std::pair<int, int>> res;

	// variable useful to manage substring checks
	int substart = -1;

	// iterating through each character of the string s
	for(int i = 0; i < s.size(); i++) {

		// checking for repetitive patterns in res
		int j = (substart == -1) ? 0 : substart;
		bool found = false;

		// searching for the i-th char of s in the vector
		while(j < s.size()) {
			if(s.at(i) == s.at(j)) {
				found = true;
				substart = (substart == -1) ? j : substart;
				break;
			}
			j++;
		}

		if(!found) {

			// case where character has not been found: we compute the length of the substring using substart
			int sublen = s.substr(substart, j).size();

			// if the lenght is one than we only have to make a new instance of a new char like (0, character)
			std::pair<int, int> newPair;

			if(len == 1) {
				newPair = std::make_pair(0, s.at(i));
				res.push_back(newPair);
			}
				else {
					// otherwise we have a new instance of a substring
					newPair = std::make_pair(sublen, substart);
					res.push_back(newPair);
				}

			// resetting the substart from the start of the string
			substart = -1;

		}

	}

}