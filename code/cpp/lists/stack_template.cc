#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

template <class T> class Stack {
public:
	Stack();
	~Stack();
	void Push(T data);
	T Pop();
	T Peek();
	T Size();
private:
	list<T> _slist;
};

template <class T> Stack<T>::Stack() {
   // do nothing	
}

template <class T> Stack<T>::~Stack() {
	// do nothing
}

template <class T> void Stack<T>::Push(T data) {
	_slist.push_back(data);
}

template <class T> T Stack<T>::Size() {
   return _slist.size();	
}

template <class T> T Stack<T>::Pop() {
	if (!_slist.empty()) {
		T tmp = _slist.back();
	    _slist.pop_back();
	    return tmp;
	}
	else {
		cout << "poping from empty list not allowed" << endl;
		exit (0);
	}
}

template <class T> T Stack<T>::Peek() {
	if (!_slist.empty()) {
		return _slist.back();	
	}
	else {
		cout << "peeking empty list" << endl;
		exit (0);
	}
}
	

int main () {
	Stack<int> A;
	A.Push(1); A.Push(2); A.Push(3);
	cout << A.Peek() << endl;
	cout << A.Pop() << endl;
	cout << A.Pop() << endl;
	cout << A.Pop() << endl;
	cout << A.Pop() << endl;
  return 0;
}
