#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int getMinSteps(int n);
int *steps;

//dp
int getMinSteps(int n) {
   if (n <= 0) return -1;
   steps[1] = 0;
   for (int i=2; i<= n; i++) {
      steps[i] = 1 + steps[i-1];
      if (i % 2 == 0) { 
         steps[i] = min(steps[i], 1 + steps[i/2]);
      }
      if (i % 3 == 0) {
         steps[i] = min(steps[i], 1 + steps[i/3]);
      }
   }
   return steps[n];
}

// memoization
int recMinSteps(int n) {
   if (n <= 0) return -1;
   if (n == 1) return 0;
   if (steps[n] != -1 ) { // we have already seen steps[n] - use that
      return steps[n];
   }
   int r = 1 + recMinSteps(n-1);
   if (n%2 == 0) {
      r = min(r, 1+recMinSteps(n/2));
   }
   if (n%3 == 0) {
      r = min(r, 1+recMinSteps(n/3));
   }
   steps[n] = r;
   return steps[n];
}


int main() {
   int n = 0;
   cout << "Enter number : ";
   cin >> n;
   cout << "Number entered " << n << endl;
   steps = new int[n+1];
   for (int i=0; i< n+1; i++) {
      steps[i] = -1;
   }
   
   //cout << "Min Steps : " << getMinSteps(n) << endl;
   cout << "Min Steps : " << recMinSteps(n) << endl;
   // dellocate memory
   delete steps;
   steps = NULL;
   return 0;
}