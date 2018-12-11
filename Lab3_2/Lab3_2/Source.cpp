#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>


using Pair_ = std::pair<std::string, std::vector<std::string>>;


void display_string(const std::string &s) {

	std::cout << s << " ";
}



void display(Pair_ s) {

	if (s.second.size() > 1) {
		std::sort(std::begin(s.second), std::end(s.second));
		std::for_each(std::begin(s.second), std::end(s.second), display_string);
		std::cout << " --> " << s.second.size() << " words" << "\n";
	}

}


// The actual program ~
int main() {


	auto subTable = std::map<std::string, std::vector<std::string>>{ }; //subject table

	//std::ifstream in{ "uppgift2_kort.txt" };
	std::ifstream inFile{ "../Code3/uppgift2/uppgift2_kort.txt" };

	if (!inFile.is_open())
	{
		std::cerr << "Could not open file\n";
		return 1;
	}


	std::string s, c;
	int counter = 0;

	while (inFile >> s) {

		c = s;

		std::sort(s.begin(), s.end());

		subTable[s].push_back(c);

		++counter;
	}

	std::cout << "Number of words = " << counter << "\n\n-- Anagrams --\n";

	std::for_each(std::begin(subTable), std::end(subTable), display);

	std::cout << "\n\n";
	
	return 0;
}