#ifndef YOUSSEF_QTEISHAT_RATIONALNUMBER_H
#define YOUSSEF_QTEISHAT_RATIONALNUMBER_H

#include <iostream>
#include <cmath>
using namespace std;

class RationalNumber {

public:
	RationalNumber(int, int); /* #1 constructor that takes in numerator and denominator and reduces fraction.
								it also prevents zero and negative values for denominator */
	int getNumerator(); // #2 returns numerator
	int getDenominator(); // #3 returns denominator
	void printRational(); // #4 prints reduced rational number.

	// #5 addition, subtraction, multiplication, and division operators will overloaded as member fucntions with return type RationalNumber 
	RationalNumber operator+( RationalNumber); 
	RationalNumber operator-(RationalNumber);
	RationalNumber operator*(RationalNumber);
	RationalNumber operator/(RationalNumber);

	// #6 similar process for overloaded relational operators, instead they return a boolean value
	bool operator>(const RationalNumber&);
	bool operator>=(const RationalNumber&);
	bool operator<(const RationalNumber&);
	bool operator<=(const RationalNumber&);

	// #7 same process for the overloaded equality and inequlity operators
	bool operator==(const RationalNumber&);
	bool operator!=(const RationalNumber&);
	
private:
	int numerator, denominator; // #8 parameters for constructor to create function
	int getGCD(int, int); /* #9 instead of finding the GCD in the constructor, we will define function to find it.
						  this will make the code more concise*/
};
#endif
