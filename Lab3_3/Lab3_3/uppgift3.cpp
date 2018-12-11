/*****************************************
* Lab 4: uppgift 3                       *
* PrettyPrinter for containers           *
* Author: Martin Falk                    *
******************************************/

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iterator>

/*******************************
* 1. Declarations              *
********************************/

using PAIR = std::pair<std::string, std::set<std::string>>;
using Map_type = std::map<std::string, std::set<std::string>>;


/********************************
* 2. Add class PrettyPrint here *
*********************************/


/*template <typename U>
void display(const U &t) {
	std::cout << t << "\n";
}*/

class PrettyPrinter {

public:

	PrettyPrinter(std::ostream &o, int i, char s) : os{ o }, in{ i }, sep{ s } {};




	template <typename T>
	void print(std::string name, T i1, T i2) {
		os << name << " = {\n";
		//std::ostream_iterator<T> outIt(std::cout, "\n");
		//std::for_each(i1, i2, display);
		while(i1 != i2) {
			os << std::string(" ", in) << *i1;

			if (++i1 != i2) {
				os << sep;
			}

			os << "\n";
		}

		os << "}\n\n";
	};

	template <typename P>
	void print(std::string name, P container) {
		print(name, std::begin(container), std::end(container));
	};


	

private:
	std::ostream &os;
	int in;
	char sep;
};

template <typename D>
std::ostream& operator<<(std::ostream &op, std::set<D> &set) {
	op << "{ ";
	std::ostream_iterator<D> outIt(op, ", ");
	std::copy(std::begin(set), std::end(set), outIt);
	op << " }";
	return op;
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream &op, std::pair<T1, T2> &pair) {
	op << "{ " << pair.first << ", " << pair.second << " }";
	return op;
}



/*****************************************
* 3. Add stream insertion operators here *
******************************************/


/*******************************
* 4. Main function             *
********************************/

int main()
{
    /*** Part 1 ***************
     * Create a pretty printer *
     **************************/
    PrettyPrinter pp(std::cout, 2, ',');

    /*** Part 2 **************
     * Pretty print a vector *
     *************************/
    std::cout << "Part 1 & 2" << "\n\n";

    std::vector<int> v = {1, 2, 3, 4, 5};

    pp.print("vector v", std::begin(v), std::end(v));

    /*** Part 3 **********************************
     * Pretty print using the container function *
     *********************************************/
    std::cout << "\nPart 3\n\n";

    pp.print("vector v", v);

    /*** Part 4 ************
     * Pretty print a map  *
     ***********************/
    std::cout << "\nPart 4\n\n";

    std::map<int, std::string> m = {{1, "first"}, {2, "second"}, {3, "third"}};

    pp.print("map m", m);

    /*** Part 5 **************************
     * Pretty print an anagram container *
     *************************************/
     std::cout << "\nPart 5\n\n";

    // replace this one with the actual output from exercise 2
    Map_type s = {{"first", {"f", "i", "r", "s", "t"}},
                  {"second", {"s", "e", "c", "o", "n", "d"}}};

    pp.print("Anagram map", s);

    std::cout << "\n";

    // this is the anagram map created from uppgift2_kort.txt
    s = {{"adegimnr", {"dreaming", "margined", "midrange"}},
         {"aekl", {"kale", "lake", "leak"}},
         {"aelrs", {"earls", "lares", "laser", "rales", "reals", "seral"}},
         {"cehiknt", {"kitchen", "thicken"}},
         {"ceilmopr", {"compiler", "complier"}},
         {"hist", {"hist", "hits", "shit", "this"}}};

    pp.print("Anagram map", s);

    return 0;
}
