#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Solution {
public:
  int kthtolast(list<int>& l, int k) {
    int ret = 0; int counter = 0;
    list<int>::iterator last = --(l.end());
    //recurse1(l.begin(), last, k, counter, ret);
    //ret = recurse2(l.begin(), last, k);
    //ret = runnerK(l, k);
    ret = pushToStack(l, k);
    return ret;
  }


  int runnerK(list<int>& l, int k) {
    list<int>::iterator start = l.begin();
    list<int>::iterator runner = l.begin();
    list<int>::iterator last = --(l.end());

    int count = 1; // since we are starting counting from 1 from the end
    while (count < k) {
      runner ++;
      count ++;
    }

    while (runner != last) {
      runner++; start++;
    }
    return *start;
  }


  int pushToStack(list<int>& l, int k) {
    vector<int> st;
    int len = 0;
    for (list<int>::iterator it = l.begin(); it!=l.end(); it++) {
      st.push_back(*it);
      len++;
    }
    return st.at(len-k);
  }


  int recurse2(list<int>::iterator it, list<int>::iterator last, int k) {
    cout << "calling recurse2" << endl;
    if (it == last) {
      cout << "reaching last stack, returning 0 " << endl;
      return 1;  
    }
    ++it;
    int counter = recurse2(it, last, k);
    --it; counter++;
    if (counter == k) {
      cout << k << " th element from last = " << *it << endl;
    }
    return counter;
  }

  void recurse1(list<int>::iterator it, list<int>::iterator last, int k, int& counter, int& ret) {
    cout << "calling recurse1" << endl;
    if (it == last) {
      counter++;
      cout << "reaching last stack, counter = " << counter << endl;
      return;
    }
    ++it;
    recurse1(it, last, k, counter, ret);
    --it;
    cout << "incrementing counter" << endl;
    counter++;
    cout << "counter - " << counter << ",  k = " << k << endl;
    if (counter == k) {
      ret = *it;
      cout << "it is " << *it << endl;
    }
    return;
  }

  void printlist(list<int>& l) {
    cout << "Printing"<< endl;
    for (list<int>::iterator it = l.begin(); it != l.end(); it++) {
      cout << *it << ", " ;
    }
    cout << endl;
  }
};


int main() {
  list<int> li; int num = 10;
  for (int i = 1; i < num; i++) {
    li.push_back(i);
  }

  Solution sol;
  sol.printlist(li);

  int k = 3;
  int ret = sol.kthtolast(li, k);
  cout << k << " th element from last is - " <<  ret << endl;
  //cout << "length of list is - " << ret << endl;
  return 0;
}
