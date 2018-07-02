#include <iostream>

struct Node {
  int data;
  Node* prev;
  Node* next;
  Node(): prev(NULL), next(NULL) {};
  Node(int val) : data(val), prev(NULL), next(NULL) {};
};

void pushback(Node* &head, int val) {
  if (head->next) { // recurse
    pushback(head->next, val);
  }
  else {  // base case
    Node* n = new Node(val);
    head->next = n;
    n->prev = head;
  }  
}

void pushfront(Node* &head, int val) {
  Node* n = new Node(val);
  if (!head) {
    head = n;
  }
  else {
    head->prev = n;
    n->next = head;
    head = n; 
  }
}

void printlist(Node* &head) {
  if (head) {
    std::cout << head->data << ", ";
    printlist(head->next);
  }
}

void plist(Node* &head) {
  std::cout << "printing list" << std::endl;
  printlist(head);
  std::cout << std::endl;
}

void printRlist(Node* &head) {
  if (head) {
    printRlist(head->next);
    std::cout << head->data << ", ";
  }
}

void prlist(Node* &head) {
  std::cout << "printing reverse list" << std::endl;
  printRlist(head);
  std::cout << std::endl;
}

int popfront(Node* &head) {
  if (!head) return -1;
  int ret = head->data;
  if (head->next) {
    Node* del = head;
    head->next->prev = NULL;
    head = head->next;
    delete del; 
    return ret;
  }
  else {
    delete head;
    head = NULL;
    return ret;
  }
}

int popback(Node* &head) {
  if (!head) {
    return -1;
  }
  else if (head->next) {
    return popback(head->next);
  }
  else {
    int ret = head->data;
    if (head->prev) {
      Node* p = head->prev;
      p->next = NULL;
    }
    delete head;
    head = NULL;
    return ret;
  }
}

int main() {
  Node* head = new Node(1);
  pushback(head, 5); 
  pushback(head, 7); 
  pushback(head, 8); 
  pushback(head, 10);
  plist(head);

  pushfront(head, 2);
  pushfront(head, 3);
  pushfront(head, 4);
  pushfront(head, 5);
  plist(head);
  prlist(head);

  std::cout << popfront(head) << ", ";
  std::cout << popfront(head)  << ", ";
  std::cout << popfront(head) << ", ";
  std::cout << popfront(head) << ", ";
  std::cout << popback(head) << ", ";
  std::cout << popback(head) << ", ";
  std::cout << popback(head) << ", ";
  std::cout << popback(head) << ", ";
  std::cout << popfront(head) << ", ";
  std::cout << popfront(head) << ", ";
  std::cout << std::endl;
  plist(head);
  prlist(head);
  
  return 0;
}
