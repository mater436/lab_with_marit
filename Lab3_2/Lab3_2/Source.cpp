#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>


using Pair_ = std::pair<std::string, int>;

std::ostream& operator<<(std::ostream& os, const Pair_ &p) //used by std::copy to copy table to cout
{
	os << p.first << ": " << p.second;

	return os;
}

void display(const Pair_ &s) {

	std::cout << s.first << " " << s.second << "\n";

}

void display_string(const std::string &s) {

	std::cout << s << "\n";
}

void is_subject() {

}

void check_subject(std::vector<std::string> &V) {
	std::vector<std::string> S;

	std::copy_if(std::begin(V), std::end(V), std::back_inserter(S), is_subject();

	std::for_each(std::begin(S), std::end(S), display);
}

int main() {


	auto subTable = std::map<std::string, int>{ }; //frequency table

	//std::ifstream in{ "uppgift1_kort.txt" };
	std::ifstream inFile{ "../Code3/uppgift2/uppgift2_kort.txt" };

	if (!inFile.is_open())
	{
		std::cerr << "Could not open file\n";
		return 1;
	}


	std::string s;
	int counter = 0;
	std::vector<std::string> words;

	while (inFile >> s) {

		//std::transform(std::begin(s), std::end(s), std::begin(s), ::tolower);
		//std::copy_if(std::begin(s), std::end(s), std::back_inserter(c), not_char);

		words.push_back(s);

		std::sort(s.begin(), s.end());

		subTable[s]++;

		++counter;
		//c = "";
	}

	std::for_each(std::begin(subTable), std::end(subTable), check_subject(words));

	std::for_each(std::begin(subTable), std::end(subTable), display);

	std::cout << "\n\n";

	std::for_each(std::begin(words), std::end(words), display_string);
	
	return 0;
}