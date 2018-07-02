#include <stdio.h>
#include <iostream>
#include <list>

using namespace std;

void addLists(list<int>::iterator it1, list<int>::iterator end1, 
                   list<int>::iterator it2, list<int>::iterator end2, int carry, 
				   list<int>* result) {
    if ((it1 == end1) && (it2 == end2) && carry == 0) { // both lists empty
		cout << "both lists empty and carry zero" << endl;
		return;
	}
	
	int val = carry;
	if (it1 != end1) { // l1 not empty
		val = val + *it1;
	}
	if (it2 != end2) {  // l2 not empty
		val = val + *it2;
	}
	cout << "digit " << val % 10 << endl;
	result->push_back(val % 10);
	
	//recurse
	int c = 0;
	if (val > 10) c = 1;
	addLists(it1 == end1 ? end1 : ++it1,
	         end1,
	         it2 == end2 ? end2 : ++it2,  
			 end2, 
			 c, 
			 result);
    return;
}


int main() {
	list<int> l1, l2;
	cout << "Enter first number" << endl;
	int val;
	while (true) {
		cin >> val;
		if (val == -1) break;
		l1.push_back(val);
	}
	
	cout << "Enter second number" << endl;
	int val2;
	while (true) {
		cin >> val2;
		if (val2 == -1) break;
		l2.push_back(val2);
	}
	
	cout << "first list" << endl;
	for (std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) {
		cout << *it << endl;
	}
	
	cout << "second list" << endl;
	for (std::list<int>::iterator it = l2.begin(); it != l2.end(); it++) {
		cout << *it << endl;
	}
	
	cout << "Doing the addition" << endl;
	list<int> result;
	addLists(l1.begin(), l1.end(), l2.begin(), l2.end(), 0, &result);
	cout << "result list" << endl;
	if (!result.empty()) {
	  for (std::list<int>::iterator it = result.begin(); it != result.end(); it++) {
		cout << *it << endl;
	  }
    }
	else {
		cout << "result is null" << endl;
	}
	return 0;
}
