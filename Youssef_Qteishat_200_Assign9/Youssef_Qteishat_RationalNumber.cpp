#include "Youssef_Qteishat_RationalNumber.h"
#include <iostream>
#include <cmath>
using namespace std;

RationalNumber::RationalNumber(int n, int d) {/* this constructor should define numerator and denominator of rational number and reduce it. 
												All while the denominator is greater than 0 */
	numerator = n;
	denominator = d;
	if (d == 0) { // prevents zero from being inputed by user, redefines it as 1 instead
		denominator = 1;
		cout << "Error: denominator equals zero. setting denominator equal to 1" << endl;
	}
	else if (d < 0){ // prevents denominator from being negative. switches the negative sign to numerator
		denominator = abs(d);
		numerator = n * -1;
	}
	int z = getGCD(abs(n), abs(d));
	numerator = n / z;
	denominator = d / z;
}

int RationalNumber::getGCD(int num1, int num2) { // function for finding the GCD to use in constructor in setting numerator and denominator
	int gcd = 1;
	if (num1 == num2) {
		gcd = num1;
	}
	else {
		for (int i = 1; i <= num1 && i <= num2; i++) {
			if (num1 % i == 0 && num2 % i == 0) {
				gcd = i;
			}
		}
	}
	return gcd;
}

void RationalNumber::printRational() { /* prints rational of new object. if the denominator is 1 or the numerator is 0, 
											only the numerator will be printed. */
	if (this->getDenominator() != 1 && this->getNumerator() != 0) {
		cout << this->getNumerator() << "/"
			<< this->getDenominator();
	}
	else {
		cout << this->getNumerator();
	}
}

RationalNumber RationalNumber::operator+(RationalNumber r2) {
	int newNumerator, newDenominator;
	
	if (this->denominator == r2.denominator) {
		newNumerator = this->numerator+ r2.numerator;
		newDenominator = this->denominator;
	}
	else {
		newNumerator = this->numerator * r2.denominator
			+ r2.numerator * this->denominator;

		newDenominator = this->denominator * r2.denominator;
	}
	RationalNumber sum(newNumerator, newDenominator); // rational number of object sum will be simplified in the constructor
	return sum;
}

RationalNumber RationalNumber::operator-( RationalNumber r2) {
	int newNumerator, newDenominator;

	if (this->denominator == r2.denominator) {
		newNumerator = this->numerator - r2.numerator;
		newDenominator = this->denominator;
	}
	else {
		newNumerator = this->numerator * r2.denominator
			- r2.numerator * this->denominator;

		newDenominator = this->denominator * r2.denominator;
	}
	RationalNumber diff(newNumerator, newDenominator); // same as the previous fucntion but that of the object diff
	return diff;
}

RationalNumber RationalNumber::operator*(RationalNumber r2) {
	int newNumerator, newDenominator;

	newNumerator = this->numerator * r2.numerator;
	newDenominator = this->denominator * r2.denominator;

	RationalNumber product(newNumerator, newDenominator);
	return product;
}

RationalNumber RationalNumber::operator/(RationalNumber r2) {
	int newNumerator, newDenominator;

	//instead of dividing the rational numbers, we can multiply the first rational number by the reciprical of the other
	newNumerator = this->numerator * r2.denominator;
	newDenominator = this->denominator * r2.numerator;

	RationalNumber quotient(newNumerator, newDenominator);
	return quotient;
}

const RationalNumber RationalNumber::operator=(RationalNumber& r2) {
	int newNumerator, int newDenominator;
	this->numerator = r2.numerator;
	this->denominator = r2.denominator;
	newNumerator = this->numerator;
	newDenominator = this->denominator;

	RationalNumber new(newNumerator, newDenominator);
}

bool RationalNumber::operator>( const RationalNumber& r2) { /* given that we are overloading in the class,
															we can directly access numerator and denominator without get functions.*/

	if (this->denominator == r2.denominator) { 
		if (this->numerator > r2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (this->getNumerator() * r2.denominator > r2.numerator * this->denominator) {
			return true;
		}
		else{ 
			return false;
		}
	}
}

int RationalNumber::getNumerator() {
	return numerator;
}

int RationalNumber::getDenominator() {
	return denominator;
}
