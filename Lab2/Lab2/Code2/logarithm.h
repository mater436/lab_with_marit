/*************************
* Class Logarithm        *
* TNG033: Lab 2          *
**************************/


#ifndef LOGARITHM_H
#define LOGARITHM_H

#include <iostream>

#include "expression.h"

class Logarithm : public Expression
{
	public:

    // Default constructor
	Logarithm();

	// Constrctor
	Logarithm(const Expression &e, const double c1, const double c2, const int n);

	// Copy constructor
	Logarithm(const Logarithm &L);

	// Deconstructor
	~Logarithm();

	// Assignment
	Logarithm operator=(const Logarithm &L);

	// operator()
	double operator()(double d) const override;

	// Display
	void display(std::ostream &os) const override;

	// Clone
	Logarithm* clone() const override;

	private: 

		int b;
		double C1;
		double C2;
		Expression* E;

};

#endif
