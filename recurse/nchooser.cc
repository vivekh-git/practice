#include <iostream>
using namespace std;

int C(int n, int k) {
  if (k == 0 || k == n)
    return 1;
  else 
    return C(n-1, k-1) + C(n-1, k);
}

int main () {
  cout << "C(5,1)=" << C(5,1) << endl;
  cout << "C(8,3)=" << C(8,3) << endl;
  return 0;
}
