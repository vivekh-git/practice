#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

class Stack {
public:
	Stack();
	~Stack();
	void Push(int data);
	int Pop();
	int Peek();
	int Size();
private:
	list<int> _slist;
};

Stack::Stack() {
   // do nothing	
}

Stack::~Stack() {
	// do nothing
}

void Stack::Push(int data) {
	_slist.push_back(data);
}

int Stack::Size() {
   return _slist.size();	
}

int Stack::Pop() {
	int tmp = 0;
	if (!_slist.empty()) {
		tmp = _slist.back();
	    _slist.pop_back();
	    return tmp;
	}
	else {
		cout << "poping from empty list not allowed" << endl;
		exit (0);
	}
	return tmp;
}

int Stack::Peek() {
	if (!_slist.empty()) {
		return _slist.back();	
	}
	else {
		cout << "peeking empty list" << endl;
		exit (0);
	}
}
	

int main () {
	Stack A;
	A.Push(1); A.Push(2); A.Push(3);
	cout << A.Peek() << endl;
	cout << A.Pop() << endl;
	cout << A.Pop() << endl;
	cout << A.Pop() << endl;
	cout << A.Pop() << endl;
  return 0;
}
