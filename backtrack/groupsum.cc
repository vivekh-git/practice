#include <iostream>
#include <vector>
using namespace std;

bool groupNoAdj(int start, int nums[], int arrlen, int target) {
  if (start >= arrlen) { // base case
    return (target == 0);
  }
  else if (target < 0) {
	  return false; // backtracking
  }
  else {
    // recurse with item included
    if (groupNoAdj(start+2, nums, arrlen, target-nums[start])) return true;
    // recurse with item not included - 6 cannot be excluded
    if (groupNoAdj(start+1, nums, arrlen, target)) return true;
  }
  return false;
}

bool groupSum(int start, int nums[], int arrlen, int target) {
  if (start >= arrlen) {   // base case
   	 	cout << endl;
    	return (target == 0);
  }
  else if (target < 0) {
	  	return false;  // backtracking
  }
  else {
    cout << nums[start] << ", ";
    if (groupSum(start+1, nums, arrlen, target-nums[start])) return true;
    cout << target << ", ";
    if (groupSum(start+1, nums, arrlen, target)) return true;
  }
  return false;
}

bool groupSum2(vector<int> sofar, int start, int arrlen, int rest[], int target) {
  // base case
  if (start == arrlen) {
    // if sum of so far == target - return true else return false
    cout << "printing array..."<< endl;
    int sum = 0;
    for (int i=0; i < sofar.size(); i++) {
      cout << sofar[i] << ", ";
      sum = sum + sofar[i];
      if (sum == target) {
         return true; 
      }
    }
    cout << "sum = " << sum << " , ending array.. " << endl;
  }
  else {
    // recurse with item included in set
    vector<int> next = sofar;
    next.push_back(rest[start]);
    if (groupSum2(next, start+1, arrlen, rest, target)) return true;
    // recurse with item not included in set
    if (groupSum2(sofar, start+1, arrlen, rest, target)) return true;
  }
  return false;
}

bool GroupSum2(int start, int arrlen, int numArr[], int target) {
  vector<int> sofar {};
  return groupSum2(sofar, start, arrlen, numArr, target);
}

int main() {
  int nums[] = {1,4,6,8,10};
  bool b =  groupNoAdj(0, nums, 5, 18);
  cout << "target 14 found in [ 2 4 6 8]" << b << endl; 

/*
  cout << "target 12 found in [2 4 6 8]" << groupNoAdj(0, {2,4,6,8}, 4, 12) << endl;
  cout << "target 8 found in [2 4 6 8]" << groupNoAdj(0, {2,4,6,8}, 4, 12) << endl;
  cout << "target 10 found in [2 4 6 8]" << groupNoAdj(0, {2,4,6,8}, 4, 12) << endl;
  cout << "target 6 found in [2 4 6 8]" << groupNoAdj(0, {2,4,6,8}, 4, 12) << endl;
  cout << "target 10 found in [2 4 6 8]" << groupNoAdj(0, {2,4,6,8}, 4, 12) << endl;
  cout << "target 14 found in [2 4 6 8]" << groupNoAdj(0, {2,4,6,8}, 4, 12) << endl;
*/
  return 0;
}
