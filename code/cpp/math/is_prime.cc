#include <iostream>

using namespace std;

bool is_prime(int n) {
  if (n <2) { cout << "invalid number" << endl; return false;}
  if (n == 2 || n == 3) { return true; }
  for (int i = 2; i< n; i++) {
    if ((n % i) == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  cout << "enter number: ";
  cin >> n;
  cout << n << " -- is_prime is -- " << is_prime(n) << endl;
  return 0;
}
