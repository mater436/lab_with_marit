/*************************
* Class Polynomial       *
* TNG033: Lab 2          *
**************************/

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

#include "expression.h"


class Polynomial : public Expression
{
public:
	// Constructor
	Polynomial(const int n, const double a[]);

	// Convertion constructor
	Polynomial(double d);

	// Copy construcor
	Polynomial(const Polynomial &P);

	//Destructor
	~Polynomial();

	double operator()(double d) const override;

	void display(std::ostream &os) const override;

	// Assignment operator
	Polynomial operator=(const Polynomial &P);

	// Operator + polynomial and double
	friend Polynomial operator+(const Polynomial &p1, const Polynomial &p2);

	// Access array []
	double& operator[](int k);

	// Access array [] of const
	double operator[](int k) const;

	Polynomial* clone() const override;

private:

	int grad;
	double* coefficients;
	
};


#endif
