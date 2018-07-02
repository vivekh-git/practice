#include <iostream>

using namespace std;
const bool DEBUG = true;
struct ListNode {
  int data;
  ListNode * next;
  ListNode (int val) : data(val), next(NULL) {}
};

void pushNode_back(ListNode* &head, int val) {
  // use recursion
  if (head) {
    pushNode_back(head->next, val);
  }
  else {
    ListNode* n = new ListNode(val);
    n->next = head;
    head = n;
  }
}

int popNode_back(ListNode* &head) {
	if (!head) {
		return -1;
	}
	else if (head->next) {
		return popNode_back(head->next);
	}
	else {
		int d = head->data;
		delete head;
		head = NULL;
		return d;
	}
}

/*
int popNode_back(ListNode* &head) {
  if (head && head->next && head->next->next) {
    return popNode_back(head->next);
  }
  else if (head && head->next) {
    int data = head->next->data;
    ListNode* d = head->next;
    delete d;
    head->next = NULL;
    return data;
  }
  else if (head) {
    int data = head->data;
    delete head;
    head = NULL;
    return data;
  }
  return -1;
}
*/

void pushNode_front(ListNode* &head, int val) {
  ListNode* newEntry = new ListNode(val);
  newEntry->next = head;
  head = newEntry;
}

int popNode_front(ListNode* &head) {
  if (head) {
    int data = head->data;
    ListNode* d = head;
    head = head->next;
    delete d;
	d = NULL;
    return data;
  }
  else {
    return -1;
  }
}

void printNode(ListNode* n) {
  cout << n->data << ", ";
}

void printList(ListNode* head) {
    // use recursion
    if (head) {
      printNode(head);
      printList(head->next);
    }
}

void printRList(ListNode* head) {
    // use recursion
    if (head) {
      printRList(head->next);
      printNode(head);
    }
}

int countList(ListNode* head) {
  if (! head) return 0;
  return 1 + countList(head->next);
}

void deallocate(ListNode* head) {
  if (head) {
    deallocate(head->next);
    delete head; 
  }
}

void printandpopList(ListNode* &head) {
  cout << "popping out.." << endl;
  int ret = -1;
  while (head != NULL) {
    ret =  popNode_back(head);
    cout << ret << ", ";
  }
  cout << endl;
} 

int main() {
  ListNode* num1 = new ListNode(2);
  pushNode_back(num1, 4); 
  pushNode_back(num1, 3);
  pushNode_back(num1, 5);
  pushNode_back(num1, 8);

  ListNode* num2 = new ListNode(5);
  pushNode_back(num2, 6);
  pushNode_back(num2, 4);

  cout << "printing num1" << endl;
  printList(num1); cout << endl;
  cout << "printing num2" << endl;
  printList(num2); cout << endl;

  cout << "printing reverse num1" << endl;
  printRList(num1); cout << endl;
  cout << "printing reverse num2" << endl;
  printRList(num2); cout << endl;

  printandpopList(num1);
  printandpopList(num2);
  cout << "printing num1" << endl;
  printList(num1);
  cout << "printing num2" << endl;
  printList(num2);

  return 0;
}
