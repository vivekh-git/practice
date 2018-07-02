#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int findKthLargest(vector<int>& arr, int k) {
  sort(arr.begin(), arr.end());
  int s = arr.size();
  
  cout << "sorted vector" << endl;
  for (vector<int>::iterator it=arr.begin(); it!=arr.end(); it++) {
	  cout << *it << " ";
  }
  cout << endl;
  cout << "largest 1st element from last is " << arr[s-1] << endl;
  cout << "largest kth element from last is " << arr[s-k] << endl; 	
  return arr[s-k];
}

int main() {
	int seed[] = {5, 8, 1, 4, 9, 21, 67, 34, 9, 19, 2, 56};
	vector<int> arr (seed, seed + 12);
	int k;
	cout << "Enter K: ";
	cin >> k;
	findKthLargest(arr, k);
	return 0;
}
