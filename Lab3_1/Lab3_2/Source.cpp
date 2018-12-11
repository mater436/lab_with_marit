#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>


//Returns true if space, false if not space
bool not_char(const char c) {
	return !(c == ' ' || c == ',' || c == '.' || c == '?' || c == '"' || c == ':' || c == '(' || c == ')' || c == ';');
}

//using Table_Entry = std::pair<std::string, std::set<int>>; aida gör något med detta men asså
using Pair_ = std::pair<std::string, int>;

void display(const Pair_ &s) {

	std::cout << s.first << " " << s.second << "\n";

}

bool more_than(const Pair_ &e1, const Pair_ &e2)
{
	return (e1.second > e2.second);
}

std::ostream& operator<<(std::ostream& os, const Pair_ &p) //used by std::copy to copy table to cout
{
	os << p.first << ": " << p.second;

	return os;
}

int main() {

	auto freqTable = std::map<std::string, int>{ }; //frequency table

	//std::ifstream in{ "uppgift1_kort.txt" };
	std::ifstream inFile{ "../Code3/uppgift1/uppgift1_kort.txt" };


	if (!inFile.is_open())
	{
		std::cerr << "Could not open file\n";
		return 1;
	}

	std::string s, c;
	int counter = 0;

	while (inFile >> s) {

		std::transform(std::begin(s), std::end(s), std::begin(s), ::tolower); 
		std::copy_if(std::begin(s), std::end(s), std::back_inserter(c), not_char);

		freqTable[c]++;

		++counter;
		c = "";
	}

	//

	std::cout << "Number of words in file: " << counter << "\n";

	std::cout << "Number of unique words in file: " << freqTable.size() << "\n";

	//Make s in capitals
	//std::transform(std::begin(s), std::end(s), std::begin(s), ::tolower);

	std::for_each(std::begin(freqTable), std::end(freqTable), display);

	std::cout << "\n\n" << "Table sorted by occurences: \n";

	std::vector<Pair_> V(freqTable.size());

	std::copy(std::begin(freqTable), std::end(freqTable), std::begin(V));

	std::sort(std::begin(V), std::end(V), more_than);

	std::for_each(std::begin(V), std::end(V), display);

	/*
	1. Läsa in filen, CHECK!
	2. Dela upp orden vid mellanslag, punkt osv
	3. Göra alla ord till små bokstäver
	4. Lägg in alla ord, om ett ord förekommer flera gånger öka counter för det ordet
	5. Skriv ut orden med counter i alfabetisk ordning
	*/

	return 0;
}