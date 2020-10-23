ifndef YOUSSEF_QTEISHAT_INTEGERSET_H
#define YOUSSEF_QTEISHAT_INTEGERSET_H


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class IntegerSet {
public:
	IntegerSet(); //1. first constructor works with sets that user inputs
	IntegerSet(int[], int); // 2. second constructor that takes in array and its size to inilize the set object
	
	void inputSet();
	void insertElement(int); // 3. inserts elemenet by setting index of element to true
	void deleteElement(int); // 4. deletes element by setting index of element to false
	void printSet();

	IntegerSet unionOfSets(IntegerSet); // 5. joins two sets, given that there are no duplicates, and defines it as a new set
	IntegerSet intersectionOfSets(IntegerSet); // 6. finds where both values of A and B are true and returns it as a set set
	bool isEqualTo(IntegerSet); // 7. determines whether to sets are identical to oneanother

private:
	vector<bool> set; // 8. vector of bool value sthat will be inilized as false

};
#endif
