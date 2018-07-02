#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

void deleteDups(list<int>& l) {
	unordered_map<int, int> dup_count;

	for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
		if (dup_count.find(*it) != dup_count.end()) {
			// map contains node - delete the dup
			l.erase(it);
		}
		else { // map do not contain, no dup
 			dup_count[*it] = 1;
		}
	}
}



int main() {
	list<int> l1; 
	cout << "Enter first number" << endl;
	int val;
	while (true) {
		cin >> val;
		if (val == -1) break;
		l1.push_back(val);
	}
	
	
	cout << "first list" << endl;
	for (std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) {
		cout << *it << endl;
	}
	
	deleteDups(l1);
		
	cout << "de-dup list" << endl;
	for (std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) {
		cout << *it << endl;
	}
   
	return 0;
}
