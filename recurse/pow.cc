#include <iostream>
using namespace std;

int pow(int base, int exp) {
  if (exp == 0)
    return 1;
  else {
    int half = pow(base, exp/2);
    if (exp %2 == 0)  
      return half * half;
    else
      return base * half * half;
  }
}

int main() {
  cout << "pow(2,0)" << pow(2,0) << endl;
  cout << "pow(2,1)" << pow(2,1) << endl;
  cout << "pow(2,2)" << pow(2,2) << endl;
  cout << "pow(2,3)" << pow(2,3) << endl;
  cout << "pow(2,4)" << pow(2,4) << endl;
  cout << "pow(2,5)" << pow(2,5) << endl;
  return 0;
}
