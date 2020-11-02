#include "Youssef_Qteishat_RationalNumber.h"
#include <iostream>
#include <cmath>
using namespace std;

RationalNumber::RationalNumber(int n, int d): numerator(n), denominator(d) {
	while (d > 0) {
		int z = getGCD(n, d);

		numerator /= z;
		denominator /= z;
	}
}

int RationalNumber::getGCD(int num1, int num2) {
	int gcd;
	if (num2 > num1) {

		int temp = num2;
		num2 = num1;
		num1 = temp;
	}
	for (int i = 1; i <= num2; ++i) {
		if ((num1 % i == 0) && (i == 0)) {
			gcd = i;
		}
	}
	return gcd;
}

int RationalNumber::getNumerator() {
	return numerator;
}

int RationalNumber::getDenominator() {
	return denominator;
}