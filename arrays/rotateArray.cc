#include <iostream>

using namespace std;
class Solution {
public:
  int**  rota(int **arr, int n) {
    for (int layer =0; layer < n/2; layer ++) { //layer 0,
      for (int index = layer; index < n-layer-1; index++) { // index=0,1,
        int top = arr[layer][index];  // 00, index=0
        arr[layer][index] = arr[n-index-1][layer];  // 00=20 01=20
        arr[n-index-1][layer] = arr[n-layer-1][n-index-1]; // 20=22  20=32
        arr[n-layer-1][n-index-1] = arr[index][n-layer-1]; // 22=02 32=13
        arr[index][n-layer-1] = top;
        printArr(arr, n); 
      }
    }
    return arr;
  }
  void printArr(int **arr, int n) {
    cout << "printing array" << endl;
    for (int i=0; i < n; i++) {
      for (int j=0; j < n; j++) {
        cout << arr[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

int main() {
  int pixel4[4][4] = {
     1, 2, 3, 4,
     5, 6, 7, 8,
     9, 10, 11, 12,
     13, 14, 15, 16 };
  int dim4 = 4;

  int pixel[6][6] = {
      1, 2, 3, 4, 5, 6,
      7, 8, 9,10,11,12,
     13,14,15,16,17,18,
     19,20,21,22,23,24,
     25,26,27,28,29,30,
     31,32,33,34,35,36};
  int dim = 6;


  // surrogate
  int *p[dim];
  for (size_t i=0; i<dim; i++) {
    p[i] = pixel[i];
  }

  Solution sol;
  sol.printArr(p, dim);
  int **rot = sol.rota(p, dim);
  sol.printArr(rot, dim);
  return 0;
}
