#include <iostream>

using namespace std;

class Solution {
public:
  void swap(int& x, int& y) {
    x = x + y;
    y = x - y;
    x = x - y;
    return;
  }
  void swap(char& ch1, char& ch2) {
     ch1 = ch1 ^ ch2;
     ch2 = ch1 ^ ch2;
     ch1 = ch1 ^ ch2;
     return;
  }
  void reverse(char* str) {
    int len = strlen(str);
    char* head = str;
    char* end = str+len-1;
    while (head < end) {
      swap(*head, *end);
      head++; end--;
    }
    return;
  }
};


int main() {
  char str[] = "this is vivek";
  cout << "str is - " << str << endl;
  Solution sol;
  sol.reverse(str);
  cout << "reversed str is - " << str << endl;
 
  return 0;
} 
