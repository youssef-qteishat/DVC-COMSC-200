#ifndef YOUSSEF_QTEISHAT_RATIONALNUMBER_H
#define YOUSSEF_QTEISHAT_RATIONALNUMBER_H

#include <iostream>
#include <cmath>
using namespace std;

class RationalNumber {

public:
	RationalNumber(int, int); /* constructor that takes in numerator and denominator and reduces fraction.
								it also prevents zero and negative values for denominator */
	int getGCD(int, int); /* instead of calculating the GCD in the constructor, 
							were going to define a fucntion to find it instead */
	int getDenominator();
	int getNumerator();

private:
	int numerator, denominator; // parameters for constructor to create function

};
#endif
