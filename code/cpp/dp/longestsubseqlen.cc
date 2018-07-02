#include <stdio.h>
#include <iostream>

using namespace std;

int lenLargestSubSeq(int arr[], int len) {
   int* longest_seq = new int[len];
   for (int x = 0; x < len; x++) {
      longest_seq[x] = 0;
   }
   for (int i=0; i< len; i++) {
      longest_seq[i] = 1;
      for (int j=0; j<i; j++) {
         if ((arr[i] > arr[j]) && (longest_seq[i] < (longest_seq[j]+1))) { //if lsj+1 > lsi, lsi = lsj+1
            longest_seq[i] = longest_seq[j] + 1;
         }
      }
   }
   
   int max = longest_seq[0];
   for (int k=1; k< len; k++) {
      if (longest_seq[k] > max) {
         max = longest_seq[k];
      }
   }
   return max;
}



int main() {
   int a[] = {4, 5, -1, 0, 6, 2, 1, 7, 8};
   int b[] = {5, 4, 0, 2, 6, 4};
   int c[] = {3,4, -1, 5, 8, 2,3,12,7,9,10};
   int d[] = {8,7,3,4,9,8,12};
   
   //cout << "array: " << a << endl;
   cout << "Len of largest subseq: " << lenLargestSubSeq(b, 6) << endl;
   
   return 0;
}