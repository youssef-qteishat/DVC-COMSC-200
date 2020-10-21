#include "Youssef_Qteishat_IntegerSet.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

IntegerSet::IntegerSet() {

	vector<bool>set(101, 0); // defines a empty set as vector with size 101 with all zeroes
}
IntegerSet::IntegerSet(int intArray[], int SIZE) { // sets through pre-existing array and poulates set with true or false values
	for (int i = 0; i <= SIZE; i++) {
		
		int n = intArray[i];
		if ((n > 0) && (n < 100)) {
			set[n] = true;
		}
	}
IntegerSet::unionOfSets(IntegerSet setObj) {
	
}
	// add if statment to check for negative values to ignore
	// true = 1, false = 0, or write "true" or "false"
	// insertElement sets index of element to true
	// deleteElement sets index to flase
	// printSet prints the only true elements
	// no duplicates in sets
	// unionToSets brings to sets together, returns new objects
	// intersectsToSets finds where A and B are true and returns that index
	// the intArray represents the index numbers of vector

}