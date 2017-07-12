#include <iostream>

using namespace std;
class Solution {
public:
  void setZeros(int** arr, int m, int n) {
    int *rowset = new int[m] {0}; int *colset = new int[n] {0};
    for (int i=0; i<m; i++) {
      for (int j=0; j<n; j++) {
        if (arr[i][j] == 0) {
          rowset[i] = 1;
          colset[j] = 1;
        }
      }
    }

    for (int i=0; i< m; i++) {
      for (int j=0; j<n; j++) {
        if ((rowset[i] == 1) || (colset[j] == 1)) {
          arr[i][j] = 0;
        }
      }
    }

  }

  void printArr(int **arr, int m, int n) {
    cout << "printing array" << endl;
    for (int i=0; i < m; i++) {
      for (int j=0; j < n; j++) {
        cout << arr[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

int main() {
  int pixel4[4][4] = {
     0, 2, 3, 4,
     5, 6, 7, 8,
     9, 10, 11, 12,
     13, 14, 15, 16 };
  int M4 = 4; int N4 = 4;

  int pixel[6][6] = {
      1, 2, 3, 4, 5, 0,
      7, 8, 0,10,11,12,
     13,14,15,16,17,18,
     19,20,21,22,23,24,
     25,26,27,28,29,30,
     31,32,33,34,0,36};
  int M = 6; int N = 6;

  int pixel34[3][4] = {
      1, 2, 3, 4,
      0, 6, 7, 8,
      9, 10, 11, 12 };
  int M34=3, N34=4; 

  // surrogate
  int *p[M];
  for (size_t i=0; i<N; i++) {
    p[i] = pixel[i];
  }

  Solution sol;
  sol.printArr(p, M, N);
  sol.setZeros(p, M, N);
  sol.printArr(p, M, N);
  return 0;
}
