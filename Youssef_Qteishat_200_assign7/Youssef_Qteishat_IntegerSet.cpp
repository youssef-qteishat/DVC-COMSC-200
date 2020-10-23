#include "Youssef_Qteishat_IntegerSet.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

IntegerSet::IntegerSet() {

	for (int i = 0; i <= 100; i++) {
		set.push_back(0); // 9. uses set_back to populat empty set with 0 values, which are false
	}
}

IntegerSet::IntegerSet(int intArray[], int SIZE) { // 10. iterates through pre-existing array and poulates set with true or false values
	
	for (int i = 0; i <= 100; i++) {

		set.push_back(0); // 11. uses push_back to poplualte vector
	}

	int arrayVal;
	for (int i = 0; i <= SIZE; i++) {

		arrayVal = intArray[i];

		if ((arrayVal >= 0) && (arrayVal <= 102)) {

			set.at(arrayVal) = true;
		}
	}
}

void IntegerSet::inputSet() {
	int input; // 12. what user inputs when prompted 
	do {

		cout << "Enter an element (enter -1 when finished): ";
		cin >> input;
		if ((input >= 0) && (input <= 100)) {

			this->set.at(input) = true; /* 13. use hidden tis pointer to point to current function making call.
			This insures that the set vector is only populated for the object that called it. */
		}
		else if (input != -1) {

			cout << "Invalid insert attempted!" << endl;
		}
	} while (input != -1); /* 14. as soon as input is out side of the range 0 to 100 and is -1, 
		the program stops prompting the user to input values in the vector*/

	cout << "Entry Complete." << endl;
}

void IntegerSet::printSet() {
	cout << "{ ";
	for (int i = 0; i < set.size(); i++) {
		
		if (set.at(i) == true) {

			cout << i << " ";
		}
	}
	cout << "}";
	
}

void IntegerSet::insertElement(int setIndex) { // 15. adds element by changing value at index setIndex to true, therfore it would be part of the set

	this->set.at(setIndex) = true;
}

void IntegerSet::deleteElement(int setIndex) { // 16. deletes element by changing value to false, which means it wont be included in the set

	this->set.at(setIndex) = false;
}

IntegerSet IntegerSet::unionOfSets(IntegerSet Obj) {

	IntegerSet unionObj; // 17. in main this object would be IntegerSet c

	for (int i = 0; i < this->set.size(); i++) {

		if (this->set.at(i) == true) {

			unionObj.set.at(i) = this->set.at(i);
		}	
	}

	for (int i = 0; i < Obj.set.size(); i++) {

		if (Obj.set.at(i) == true) {

			unionObj.set.at(i) = Obj.set.at(i); /* 18. uses tempObj in place of IntegerSet b in main().
													if value at index i = true, the valu is added to the unionObj set vector */
		}
	}
	return unionObj;
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet Obj) {

	IntegerSet intersectObj;

	for (int i = 0; i <= 100; i++) { // 19. iterate through both sets without checking whther it is true

		if ((this->set.at(i)) && (Obj.set.at(i)) == true) {

			intersectObj.set.at(i) = this->set.at(i); /* 20. if both sets for IntegerSet a and b are eqaul,
														set for IntegerSet c only has to equal one of the sets */
		}	
	}
	return intersectObj;
}

bool IntegerSet::isEqualTo(IntegerSet Obj) {

	for (int i = 0; i <= 100; i++) {
		
		if ((this->set.at(i)) != (Obj.set.at(i))) {

			return false;
		}
	}
	return true;
}
