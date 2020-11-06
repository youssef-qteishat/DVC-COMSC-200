#include "Youssef_Qteishat_RationalNumber.h"
#include <iostream>
#include <cmath>
using namespace std;

RationalNumber::RationalNumber(int n, int d) {/* #10 this constructor should define numerator and denominator of rational number and reduce it. 
												All while the denominator is greater than 0 */
	numerator = n;
	denominator = d;
	if (d == 0) { // #11 prevents zero from being inputed by user, redefines it as 1 instead
		denominator = 1;
		cout << "Error: denominator equals zero. setting denominator equal to 1" << endl;
	}
	else if (d < 0){ // #12 prevents denominator from being negative. switches the negative sign to numerator
		denominator = abs(d);
		numerator = n * -1;
	}
	else if (d < 0 && n < 0){
		denominator = abs(d);
		numerator = abs(n);
	}
	int z = getGCD(abs(n), abs(d));
	numerator = numerator / z;
	denominator = numerator / z;
}

int RationalNumber::getGCD(int num1, int num2) { // #13 function for finding the GCD to use in constructor in setting numerator and denominator
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

void RationalNumber::printRational() { /* #14 prints rational of new object. if the denominator is 1 or the numerator is 0, 
										only the numerator will be printed.*/
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
	
	if (this->denominator == r2.denominator) { /* #15 if the denominators are the same, simply add the two numerators 
												and return one of the denominators to get newNumerator and newDenominator */
		newNumerator = this->numerator+ r2.numerator;
		newDenominator = this->denominator;
	}
	else {
		newNumerator = this->numerator * r2.denominator /* #16 if they are not, the two numerators and denominators are multiplied by 
														the other one's denominator in order for the rational numbers to be added*/
			+ r2.numerator * this->denominator;
		newDenominator = this->denominator * r2.denominator;
	}
	RationalNumber sum(newNumerator, newDenominator); // #17 rational number of object sum will be simplified in the constructor
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
	RationalNumber diff(newNumerator, newDenominator); // #18 same as the previous fucntion but that of the object diff
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

	newNumerator = this->numerator * r2.denominator; /* #19 instead of dividing the rational numbers, 
													 we can multiply the first rational number by the reciprical of the other*/
	newDenominator = this->denominator * r2.numerator;

	RationalNumber quotient(newNumerator, newDenominator);
	return quotient; // #20 returns product of rational number and the other's reciprical
}

/* #20 For the overloaded relational, equality, and inequality, they will check for whether the denominators of the two rational number are the same or not
If not, the numerators will be multipled by the other rational number's denominator in order for them to be compared. 
After that, it will return either true or false */
bool RationalNumber::operator>( const RationalNumber& r2) { 

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

bool RationalNumber::operator>=(const RationalNumber& r2) { 

	if (this->denominator == r2.denominator) {
		if (this->numerator >= r2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (this->getNumerator() * r2.denominator >= r2.numerator * this->denominator) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool RationalNumber::operator<(const RationalNumber& r2) {

	if (this->denominator == r2.denominator) {
		if (this->numerator < r2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (this->getNumerator() * r2.denominator < r2.numerator * this->denominator) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool RationalNumber::operator<=(const RationalNumber& r2) { 

	if (this->denominator == r2.denominator) {
		if (this->numerator <= r2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (this->getNumerator() * r2.denominator <= r2.numerator * this->denominator) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool RationalNumber::operator==(const RationalNumber& r2) {

	if (this->denominator == r2.denominator) {
		if (this->numerator == r2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (this->getNumerator() * r2.denominator == r2.numerator * this->denominator) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool RationalNumber::operator!=(const RationalNumber& r2) {

	if (this->denominator == r2.denominator) {
		if (this->numerator != r2.numerator) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		if (this->getNumerator() * r2.denominator != r2.numerator * this->denominator) {
			return true;
		}
		else {
			return false;
		}
	}
}

// #21 these two functions are only used to return the numerator and denominator so it can be printed in printRational()
int RationalNumber::getNumerator() {
	return numerator;
}

int RationalNumber::getDenominator() {
	return denominator;
}
