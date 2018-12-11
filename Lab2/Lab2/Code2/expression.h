/*************************
* Class Expression       *
* TNG033: Lab 2          *
**************************/

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <string>

const double EPSILON = 1.0e-5;


class Expression
{
public:
	//Constructor
	Expression() = default;				// Ska constructors vara protected?

	//Destructor
	virtual ~Expression() = default;

	//Copy constructor
	Expression(Expression &E) = default;

	bool isRoot(double x) const;

	virtual double operator()(double d) const = 0;

	friend std::ostream& operator<<(std::ostream &os, const Expression &e);

	// Kallar på copy constructor
	virtual Expression* clone() const = 0;

	Expression& operator=(Expression &e) = delete;

protected:

	// Displayar saker
	virtual void display(std::ostream &os) const = 0;
};


#endif
