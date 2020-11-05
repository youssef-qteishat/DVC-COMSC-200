#ifndef YOUSSEF_QTEISHAT_RATIONALNUMBER_H
#define YOUSSEF_QTEISHAT_RATIONALNUMBER_H

#include <iostream>
#include <cmath>
using namespace std;

class RationalNumber {

public:
	RationalNumber(int, int); /* constructor that takes in numerator and denominator and reduces fraction.
								it also prevents zero and negative values for denominator */
	int getNumerator(); // returns numerator
	int getDenominator(); // returns denominator
	void printRational(); // prints reduced rational number.

	// addition, subtraction, multiplication, and division operators will overloaded as friend fucntions with return type RationalNumber 
	RationalNumber operator+( RationalNumber); 
	RationalNumber operator-(RationalNumber);
	RationalNumber operator*(RationalNumber);
	RationalNumber operator/(RationalNumber);
	const RationalNumber operator=(const RationalNumber&);

	// the relational operators will be overloaded as constant fucntions and will return a boolean value
	bool operator>(const RationalNumber&);

	friend bool operator>=(const RationalNumber&, const RationalNumber&);
	friend bool operator<(const RationalNumber&, const RationalNumber&);
	friend bool operator<=(const RationalNumber&, const RationalNumber&);

	// and the same applies to the equality and inequality operators
	friend bool operator==(const RationalNumber&, const RationalNumber&);
	friend bool operator!=(const RationalNumber&, const RationalNumber&);

	
private:
	int numerator, denominator; // parameters for constructor to create function
	int getGCD(int, int); /* instead of calculating the GCD in the constructor,
							were going to define a fucntion to find it instead */
};
#endif
