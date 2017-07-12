#include <iostream>
#include <stdio.h>

using namespace std;
class Solution {
public:
  bool isPowOfTwo(int x) {
    return !(x &  (x-1));
  }
  bool isPowOfTwo2(int x) {
    return x && (!(x & (x-1)));
  }
};

int main() {
  int num1 = 15; 
  Solution sol;
  bool t = sol.isPowOfTwo2(num1);
  if (!num1) {cout << num1 << " is not a power of 2" << endl; }
  else if (t) {cout << num1 << " is power of 2" << endl;}
  else {cout << num1 << " is not a power of 2" << endl;}
  return 0;
}
