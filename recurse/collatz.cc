#include <iostream>

using namespace std;
int collatz(int n) {
  if (n < 1) return -1;
  int steps = 1;
  
  if (n == 1) 
   return 0;
  else if (n % 2 == 0)
   return steps + collatz(n/2);
  else 
   return steps + collatz(3*n+1);

}


int main() {
  cout << " 1 -> " << collatz(1) << endl;
  cout << " 2 -> " << collatz(2) << endl;
  cout << " 3 -> " << collatz(3) << endl;
  cout << " 4 -> " << collatz(4) << endl;
  cout << " 5 -> " << collatz(5) << endl;
  cout << " 6 -> " << collatz(6) << endl;
  cout << " 7 -> " << collatz(7) << endl;

  return 0;
}
