#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int findMajority(int input[], int len) {
  
  sort (input, input+len); 

  vector<int> vArr(input, input+len);
   
   sort(vArr.begin(), vArr.end());
   
   map<int,int> numCount; int curr = 0;
   int maxCount =0; int maxIndex = 0;
   for (vector<int>::iterator it=vArr.begin(); it!=vArr.end(); it++) {
      curr = *it;
      numCount[curr]++;
      if (numCount[curr] > maxCount) {
         maxCount = numCount[curr];
         maxIndex = curr;
      }
   }
   
   if (maxCount > len/2) {
      cout << "Majority element found: " << maxIndex << " and count is :" << maxCount <<endl;
      return maxIndex;
   }
   else {
      cout << "No majority found" << endl;
      return -1;
   }
}



int main() {
   int a[] = {2, 2, 4, 3, 5, 2};
   int b[] = {2, 2, 4, 3, 2, 2};
   
   findMajority(b, 6);
   
   
}
