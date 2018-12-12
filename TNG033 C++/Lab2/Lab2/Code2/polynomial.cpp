/*********************************************************
* Class Polynomial member functions implementation       *
* TNG033: Lab 2                                          *
**********************************************************/

#include "polynomial.h"
#include <string>
#include <iostream>
#include <algorithm>

//ADD implementation of the member functions for class Polynomial
// Constructor
Polynomial::Polynomial(const int n, const double a[])
	: grad{ n }
{
	coefficients = new double[n+1];			// Behövs detta?

	for (int i = 0; i <= n; ++i) {
		coefficients[i] = a[i];
	}
}

// Convertion constructor
Polynomial::Polynomial(double d)
	: grad{ 0 }, coefficients{ new double[1]{d}}
{}

// Copy construcor
Polynomial::Polynomial(const Polynomial &P)
	: grad {P.grad}, coefficients { }
{
	double* temp = new double[P.grad+1];

	for (int i = 0; i <= P.grad; ++i) {
		temp[i] = P.coefficients[i];
	}

	coefficients = temp;

	temp = nullptr;
}

//Destructor
Polynomial::~Polynomial() {
	delete[] coefficients;
	coefficients = nullptr;
}


double Polynomial::operator()(double d) const {
	double sum = 0;

	for (int i = 0; i <= grad; ++i) {			// Ska gå till grad, inte till innan grad
		sum += coefficients[i] * pow(d, i);
	}

	return sum;
}

void Polynomial::display(std::ostream &os) const {

	os << coefficients[0];

	if (grad > 0) {
		os << " + " << coefficients[1] << "x";

		for (int i = 2; i <= grad; ++i) {
			if (coefficients[i] == 1) {
				os << " + x^" << i;
			}
			else {
				os << " + " << coefficients[i] << "x^" << i;
			}
		}
	}
}

// Assignment operator
Polynomial Polynomial::operator=(const Polynomial &P) {
	Polynomial poly{ P };

	grad = poly.grad;
	std::swap(coefficients, poly.coefficients);

	return *this;
}


// Operator + polynomial and double
Polynomial operator+(const Polynomial &p1, const Polynomial &p2) {

	int max_grad = std::max(p1.grad, p2.grad);
	
	double* array = new double[max_grad+1] { 0 };

	Polynomial temp{ max_grad, array };

	int min_grad = std::min(p1.grad, p2.grad);

	for (int i = 0; i <= min_grad; ++i)
	{
		temp.coefficients[i] = p1.coefficients[i] + p2.coefficients[i];
	}

	//Copy any remaining elements in s1, if any
	for (int i = min_grad + 1; i <= p1.grad; ++i)
	{
		temp.coefficients[i] = p1.coefficients[i];
	}

	//Copy any remaining elements in s2, if any
	for (int i = min_grad + 1; i <= p2.grad; ++i)
	{
		temp.coefficients[i] = p2.coefficients[i];
	}

	delete[] array;
	
	return temp;
}

// Acces array []
double& Polynomial::operator[](int k) {

	return coefficients[k];
}

// Access array []
double Polynomial::operator[](int k) const {

	return coefficients[k];
}

Polynomial* Polynomial::clone() const {

	return new Polynomial{ *this };
}