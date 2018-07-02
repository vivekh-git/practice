#include <iostream>

const bool DEBUG = true;
struct Node {
  int data;
  Node * next;
  Node (int val) : data(val), next(NULL) {}
};

class List {
private:
  Node* _head;
  int _length;

public:
  List() {
    _head = NULL;
    _length = 0;
  }

  ~List() {
    _deallocate(_head);
    _length = 0;
  }

  void _deallocate(Node* &head) {
    if (head) {
      _deallocate(head->next);
      delete head;
	  head = NULL;
    }
  }

  void pushNode_front(int val) {
    Node* n = new Node(val);
    // head can be null, 1 element or many elements;
   if (!_head) {
     _head = n;
   }
   else {
      n->next = _head;
      _head = n;
   }
   _length++;
  }

  int popNode_front() {
    Node* p = _head;
    int ret = -1;
    if (p) {
      _head = p->next;
      ret = p->data;
      delete p;
      p = NULL;
      _length--;
    }
    return ret;
  }

  void _printNode(Node* n) {
    std::cout << n->data << ", ";
  }

  void printList() {
    _printList(_head);
    std::cout << std::endl;
  }

  void _printList(Node* &head) {
    Node* p = head;
    if (p) {
      _printNode(p);
      // recurse
      _printList(p->next);
    }
  }

  void printReverseList() {
    _printReverseList(_head);
    std::cout << std::endl;
  }

  void _printReverseList(Node* &head) {
    Node* p = head;
    if (p) {
      _printReverseList(p->next);
      _printNode(p);
    }
  }

  void printandpopList() {
    int ret = -1;
    std::cout << "popping... " << std::endl;
    while (true) {
      ret = popNode_back();
      if (ret == -1) break;
      std::cout << ret << ", ";
    } 
    std::cout << std::endl;
    std::cout << "done..." << std::endl;
  }

  void addNode_back(int val) {
    Node* n = new Node(val);
    Node* p = _head;
    while (p && p->next) {
      p = p->next; 
    }
    if (p) {
      p->next = n;
    }
    else {
      _head = n;
    }
    _length++;
  }
 
  void pushNode_back(int val) {
    _pushNode_back(_head, val);
    _length++;
  }

  void pushNode_back_sorted(int val) {
    _pushNode_back_sorted(_head, val);
  }

  void _pushNode_back_sorted(Node* &head, int val) {
    if (head && head->data < val) {
      _pushNode_back_sorted(head->next, val);
    }
    else {
      Node* n = new Node(val);
      n->next = head;
      head = n;
    }
  }

  void _pushNode_back(Node* &head, int val) {
    if (head) {
      _pushNode_back(head->next, val);
    }
    else {
      Node* n = new Node(val); 
      n->next = head;
      head = n;
    }
  }

  int popNode_back() {
    _length--;
    return _popNode_back(_head);
  }

  int _popNode_back(Node* &head) {
    if (head && head->next && head->next->next) {
      return _popNode_back(head->next);
    }
    else if (head and head->next) {
      int data = head->next->data;
      Node* tmp = head->next;
      head->next = NULL;
      delete tmp;
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
};


int main() {
  List* num1 = new List;
  List* num2 = new List;
  num1->pushNode_front(4); 
  num1->pushNode_front(3);
  num1->pushNode_front(5);
  num1->pushNode_front(8);
  num2->pushNode_back_sorted(4); 
  num2->printList();
  num2->pushNode_back_sorted(3);
  num2->printList();
  num2->pushNode_back_sorted(8);
  num2->printList();
  num2->pushNode_back_sorted(6);
  num2->printList();
  num2->pushNode_back_sorted(4);
  num2->printList();

  num1->printList();
  num2->printList();
  
  num1->printandpopList(); num2->printandpopList();
  num1->printList();
  num2->printList();
  delete num1;
  delete num2;
  
  return 0;
}
