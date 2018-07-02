#include <iostream>
#include <vector>

using namespace std;


bool split(int sum, int start, int rest[], int arrlen, int totalsum) {
  //int arrlen = rest.length;
  // base case
  if (start == arrlen) {
    //for (vector<int>::iterator it = sofar.begin(); it != sofar.end(); it++) {
    //  cout << *it << ", ";
    //}
    //cout << endl;
    if (totalsum == 2 * sum)
      return true;
    return false;
  }
  else {
    // recurse with item included in set
    // dont include multiple of 3
    int incr = rest[start];
    if ((rest[start] % 5 != 0) && (rest[start] % 3 == 0)) {
      incr = 0; // dont include in the set
    }
    if (split(sum+incr, start+1, rest, arrlen, totalsum)) return true;
    // recurse with item not included in set, 
    // dont exclude multiple of 5
    if ((rest[start] % 5 != 0) &&
         split(sum, start+1, rest, arrlen, totalsum)) return true;
  }
  return false;
}

bool split53(int nums[], int arrlen) {
   // call RHelper in a recursive way or from a loop
  int sum = 0; int totalsum = 0;
  for (int i = 0; i < arrlen; i++)  totalsum += nums[i];
  return split(sum, 0, nums, arrlen, totalsum);
}

int main() {
  int nums[] = {3, 5, 2}; int arrlen = 3;
  bool b = split53(nums, arrlen);
  cout << "[3 5 8] - dividing into 2 groups with equal with sum with 5 multiples and 3 multiples in different groups = " << b << endl;
  return 0;
}
