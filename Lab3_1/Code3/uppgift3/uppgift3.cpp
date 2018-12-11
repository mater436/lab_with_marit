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

/*******************************
* 1. Declarations              *
********************************/

using PAIR = std::pair<std::string, std::set<std::string>>;
using Map_type = std::map<std::string, std::set<std::string>>;


/********************************
* 2. Add class PrettyPrint here *
*********************************/


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
    //PrettyPrinter pp(std::cout, 2, ',');

    /*** Part 2 **************
     * Pretty print a vector *
     *************************/
    std::cout << "Part 1 & 2" << "\n\n";

    std::vector<int> v = {1, 2, 3, 4, 5};

    //pp.print("vector v", std::begin(v), std::end(v));

    /*** Part 3 **********************************
     * Pretty print using the container function *
     *********************************************/
    std::cout << "\nPart 3\n\n";

    //pp.print("vector v", v);

    /*** Part 4 ************
     * Pretty print a map  *
     ***********************/
    std::cout << "\nPart 4\n\n";

    std::map<int, std::string> m = {{1, "first"}, {2, "second"}, {3, "third"}};

    //pp.print("map m", m);

    /*** Part 5 **************************
     * Pretty print an anagram container *
     *************************************/
     std::cout << "\nPart 5\n\n";

    // replace this one with the actual output from exercise 2
    Map_type s = {{"first", {"f", "i", "r", "s", "t"}},
                  {"second", {"s", "e", "c", "o", "n", "d"}}};

    //pp.print("Anagram map", s);

    std::cout << "\n";

    // this is the anagram map created from uppgift2_kort.txt
    s = {{"adegimnr", {"dreaming", "margined", "midrange"}},
         {"aekl", {"kale", "lake", "leak"}},
         {"aelrs", {"earls", "lares", "laser", "rales", "reals", "seral"}},
         {"cehiknt", {"kitchen", "thicken"}},
         {"ceilmopr", {"compiler", "complier"}},
         {"hist", {"hist", "hits", "shit", "this"}}};

    //pp.print("Anagram map", s);

    return 0;
}
