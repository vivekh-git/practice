#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
const bool DEBUG = true;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class List {
public:
  List() {
    head = new ListNode;
  }
  Push_back(int x) {
    
  }

private:
  ListNode* head;
};

void print_list(list<ListNode>& l) {
  cout << "Printing list-- ";
  for (list<ListNode>::iterator it = l.begin(); it != l.end(); it++) {
    cout << it->val << " ";
  }
  cout << endl;
}

class Solution {
public:
    list<ListNode>* addTwoNumbers(list<ListNode>& l1, list<ListNode>& l2) {
      list<ListNode>* lr = new list<ListNode>;

      print_list(l1); print_list(l2);
      list<ListNode>::iterator it1=l1.begin();
      list<ListNode>::iterator it2=l2.begin();
      int carry = 0; int sum=0; int digit =0; int e1=0; int e2=0;
      while (it1 != l1.end() || it2 != l2.end()) {
        sum = 0; digit = 0; e1=0; e2 = 0;
        if (it1 != l1.end()) { e1 = it1-> val; }
        if (it2 != l2.end()) { e2 = it2-> val; }
        if (DEBUG) { cout << "e1-" << e1 << ", e2-" << e2 << endl;}
        sum = e1 + e2 + carry;;
        digit = sum % 10;
        carry = sum / 10;
        if (DEBUG) { cout << "sum-" << sum << ", digit-" << digit << ", carry-" << carry << endl; }
	lr->push_back(digit);
        it1++; it2++;
      }
      print_list(*lr);
      return lr;
    }
};


int main() {
  // input
  list<ListNode> l1, l2;

  int num1 = 342;
  int num2 = 465;

  int digit = num1 % 10; num1=num1 / 10;
  while (digit) {
    l1.push_back (digit);
    digit = num1 % 10; num1=num1/10;
  }

  digit = num2 % 10; num2=num2/10;
  while (digit) {
    l2.push_back (digit);
    digit = num2 % 10; num2=num2/10;
  }

  print_list(l1); print_list(l2);

  Solution sol;
  list<ListNode>* lr = new list<ListNode>;
  lr = sol.addTwoNumbers(l1, l2);
  print_list(*lr);
  delete lr;
  lr = NULL;
  return 0;
}
