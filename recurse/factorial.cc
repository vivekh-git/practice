#include <iostream>
#include <string>
using namespace std;

int factorial(int n) {
  // base case
  if (n == 1) 
    return 1;
  else 
    return n * factorial(n-1);
}

int bunnyEars(int bunnies) {
  // base case
  if (bunnies == 0)
    return 0;
  else 
    return 2 + bunnyEars(bunnies-1);
}

int fibonacci(int n) {
  // base case
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return fibonacci(n-1) + fibonacci(n-2);
}

int countX(string str) {
  // base case
  if (str.length() <= 0)
    return 0;
  else if (str.at(0) == 'x')
    return 1 + countX(str.substr(1));
  else
    return countX(str.substr(1));
}

bool array6(int nums[], int index, int len) {
  // base case
	cout << "entering array6" << endl;
  if (index == len)
    return false;
  else if (nums[index] == 6)
    return true || array6(nums, index+1, len);
  else
    return false || array6(nums, index+1, len);
}


int main () {
  //cout << factorial(5) << endl;
  //cout << bunnyEars(2) << endl;
  cout << fibonacci(8) << endl;
  cout << countX("xhixhix") << endl;
  int nums[] = {1,6,3,6};
  cout << array6(nums, 0, 4) << endl;
}
