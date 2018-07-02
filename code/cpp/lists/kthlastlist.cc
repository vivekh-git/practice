#include <stdio.h>
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

void kthlast(list<int>::iterator head, list<int>::iterator end, int k, int& counter, int& kthelement, int& find) {
	cout << "headbegin: " << *head << ", k: " << k << ", counter: " << counter << endl;
	
	if (head == end) {
		return;
	}
	
	kthlast(std::next(head), end, k, counter, kthelement, find);
	
	counter = counter + 1;
	if (counter == k) {
		// reached kth element
		kthelement = *head;
		find = 1;
	}
	cout << "head: " << *head << ", k: " << k << ", counter: " << counter << endl;
	return;
}

typedef struct node {
	int val;
	node* prev;
	node* next;
} node;


int main() {
	list<int> l1; 
	cout << "Enter  list" << endl;
	int val;
	while (true) {
		cin >> val;
		if (val == -1) break;
		l1.push_back(val);
	}
	
	
	cout << "list" << endl;
	for (std::list<int>::iterator it = l1.begin(); it != l1.end(); it++) {
		cout << *it << endl;
	}
	
	int k;
	cout << "enter k: " << endl;
	cin >> k;
	
	int kthelement; int counter = 0; int find =0;
	kthlast(l1.begin(), l1.end(), k, counter,  kthelement, find);
	if (find) {
		cout << "kth element from last: " << kthelement << endl;
	} 
	else {
		cout << "error - invalid k: " << k << endl;
	}
	return 0;
}
