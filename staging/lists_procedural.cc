#include <iostream>

using namespace std;
const bool DEBUG = true;
struct Node {
  int data;
  Node * next;
  Node (int val) : data(val), next(NULL) {}
};


void pushNode_front(Node* &root, int num) {
	Node * n = new Node(num);
	n->next = root;
	root = n;
}

void pushNode_back(Node* &root, int num) {
	Node* runner = root;
	while (runner && runner->next) {
		runner = runner->next;
	}
	Node* n = new Node(num);
	if (runner) {
	    runner->next = n;
	}
	else {
		runner = n;
	}
}


void addNode_back(Node* &root, int num) {
	if (root) {
	    pushNode_back(root->next, num);
	}
	else {
		Node* n = new Node(num);
		n->next = root;
		root = n;
	}
}

int popNode_back(Node* &root) {
	if (! root) {
		return -1;
	}
	else if (root->next) {
		return popNode_back(root->next);
	}
	else {
		int d = root->data;
		delete root;
		root = NULL;
		return d;
	}
}

int popNode_front(Node* &root) {
	if (root) {
		int d = root->data;
		Node* n = root;
		root = root->next;
		delete n;
		n = NULL;
		return d;
	}
	else {
		return -1;
	}
}

void printandpopList(Node* &root) {
	if (root) {
		int n = popNode_front(root);
		cout << n << " ";
		printandpopList(root);
	}
}

void printList(Node* root) {
	if (root) {
		cout << root->data << " ";
		printList(root->next);
	}
}

void printRList(Node* root) {
	if (root) {
		printRList(root->next);
		cout << root->data << " ";
	}
}

void deallocate(Node* &root) {
	if (root) {
		deallocate(root->next);
		delete root;
		root = NULL;
	}
}


int main() {
  Node* num1 = new Node(2);
  pushNode_back(num1, 4); 
  pushNode_back(num1, 3);
  pushNode_back(num1, 5);
  pushNode_back(num1, 8);

  Node* num2 = new Node(5);
  pushNode_front(num2, 6);
  pushNode_front(num2, 4);

  cout << "printing num1" << endl;
  printList(num1); cout << endl;
  cout << "printing num2" << endl;
  printList(num2); cout << endl;

  cout << "printing reverse num1" << endl;
  printRList(num1); cout << endl;
  cout << "printing reverse num2" << endl;
  printRList(num2); cout << endl;

  deallocate(num1);
  
  printandpopList(num1);
  printandpopList(num2); cout << endl;
  cout << "printing num1" << endl;
  printList(num1);
  cout << "printing num2" << endl;
  printList(num2);
  
  return 0;
}