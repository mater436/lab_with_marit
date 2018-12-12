/*********************************************************
* Class Expression member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "expression.h"

#include <iostream>
#include <string>
#include <sstream>

//ADD implementation of the member functions for class Expression
std::ostream& operator<<(std::ostream &os, const Expression &E) {
	
	E.display(os); //dynamic binding occurs

	return os;
}


bool Expression::isRoot(double x) const {
	if (fabs((*this)(x)) < EPSILON) {
		return true;
	}

	return false;
}
