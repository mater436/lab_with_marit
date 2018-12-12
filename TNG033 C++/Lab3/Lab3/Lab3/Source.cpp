#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>


//Returns true if space, false if not space
bool not_space(char c)
{
	return (c != ' ' && c != '\n' && c != '\t' && c != '.' && c != ',');
}


int main() {

	//std::ifstream in{ "uppgift1_kort.txt" };
	auto in = std::ifstream{ "../../Code3/uppgift1/uppgift1_kort.txt" };

	if (!in.is_open())
	{
		std::cerr << "Could not open file\n";
		return 1;
	}

	std::map<std::string, int> freqTable;

	std::string s;

	std::string line;

	getline(in, line);

	std::copy_if(std::begin(line), std::end(line), std::back_inserter(s), not_space);

	std::cout << s << "\n";

	//Make s in capitals
	std::transform(std::begin(s), std::end(s), std::begin(s), ::tolower);

	std::cout << s << "\n";



	/*
	1. Läsa in filen, CHECK!
	2. Dela upp orden vid mellanslag, punkt osv
	3. Göra alla ord till små bokstäver
	4. Lägg in alla ord, om ett ord förekommer flera gånger öka counter för det ordet
	5. Skriv ut orden med counter i alfabetisk ordning
	*/

	return 0;
}