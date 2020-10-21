#ifndef YOUSSEF_QTEISHAT_INTEGERSET_H
#define YOUSSEF_QTEISHAT_INTEGERSET_H


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class IntegerSet {
public:
	IntegerSet();
	
	IntegerSet unionOfSets(IntegerSet); // joins two sets, given that there are no duplicates, and defines it as a new set
	IntegerSet intersectionOfSets(IntegerSet); // finds where both values of A and B are true and returns it as a set set
	void insertElement(); // inserts elemenet by setting index of element to true
	void deleteElement(); // deletes element by setting index of element to false
	void printSet();
	IntegerSet isEqualTo(IntegerSet); // determines whether to sets are equal. Used to create third theoretical set

	IntegerSet(int [], int); // second constructor that takes in array and its size to inilize the set object
	

private:
	vector<bool> set; // 
	int intArray[]; // array used to inilize set object

};
#endif
