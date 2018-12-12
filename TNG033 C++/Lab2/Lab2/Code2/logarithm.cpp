/*********************************************************
* Class Logarithm member functions implementation        *
* TNG033: Lab 2                                          *
**********************************************************/

#include "logarithm.h"
#include "polynomial.h"

//ADD implementation of the member functions for class Logarithm

// Default constructor
Logarithm::Logarithm()
	: b { 2 }, C1 { 0 }, C2 { 1 }
{
	double* a = new double[2]{ 0,1 };

	E = new Polynomial(1, a);

	delete[] a;
}

// Constrctor
Logarithm::Logarithm(const Expression &e, const double c1, const double c2, const int n)
	: b { n }, C1 { c1 }, C2 { c2 }, E { e.clone() } { }

// Copy constructor
Logarithm::Logarithm(const Logarithm &L)
	: b { L.b }, C1 { L.C1 }, C2 { L.C2 }, E { L.E->clone() } { }

// Deconstructor
Logarithm::~Logarithm() {
	delete E;
	E = nullptr;
}

// Assignment operator
Logarithm Logarithm::operator=(const Logarithm &L) {

	delete E;

	b = L.b;
	C1 = L.C1;
	C2 = L.C2;
	E = L.E->clone();

	return *this;

}

// operator()
double Logarithm::operator()(double d) const {
	
	return C1 + C2 * (log((*E).operator()(d)) / log(b));
}

// Display
void Logarithm::display(std::ostream &os) const {

	os << C2 << "*log_" << b << "(" << *E << ")";

	if (!(fabs(C1) < EPSILON)) {
		os << " + " << C1;
	}
}

// Clone
Logarithm* Logarithm::clone() const {

	return new Logarithm{ *this };
}