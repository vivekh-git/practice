#include <iostream>
#include <list>
#include <assert.h>

using namespace std;

class Solution {
public:
  void deleteNthNode(list<int>::iterator p, list<int>& l) {
    list<int>::iterator end = l.end();
    cout << "inside delete func, p - " << *p << endl;
    list<int>::iterator next = p;
    if (p == l.end()) { 
      cout << "iterator positioned at end beyond valid list - cannot delete, exiting" << endl;
      return;
    }
    else if (++next == l.end()) { 
      l.erase(p); 
    }
    else {
      *p = *next;
      l.erase(next);
    }
    return;
  }

  void printList(list<int>& l) {
    cout << "Printing" << endl;
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
      cout << *it << ", ";
    }
    cout << endl;
  }
};

int main() {
   list<int> l; int num = 9;
   for (int i=0; i<num; i++) {
     l.push_back(i);
   }
   Solution sol;

   int delNode=-1;
   list<int>::iterator it = l.begin(); int count = 0;
   while ((it != l.end()) && (count < delNode)) {
     it++; count++;
   }
   if (count != delNode) {
     cout << delNode << " node is not a valid node to be deleted" << endl;
     return 0;
   }
   sol.printList(l);
   cout << "Deleting " << delNode << " th node - " << *it <<  endl;
   sol.deleteNthNode(it, l);
   //l.erase(it);
   sol.printList(l);
   return 0;
}
