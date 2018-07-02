#include <iostream>
#include <vector>
using namespace std;

const int NOTFOUND = -1;
int bsearch(vector<int>& arr, int start, int end, int search) {
  if (start > end) 
    return NOTFOUND;
  int mid = (start + end) / 2;
  if (search == arr.at(mid)) 
    return mid;
  else if (search > arr.at(mid)) 
    return bsearch(arr, mid+1, end, search);
  else
    return bsearch(arr, start, mid-1, search);
}

int bsearch2(vector<int>& arr, int size, int search) {
  if (size <= 0) return NOTFOUND;
  int low = 0;
  int high = size-1;
  while (low <= high) {
    int mid = (high+low)/2;
    if (arr.at(mid) == search)
      return mid;
    else if (arr.at(mid) < search)
      low = mid+1;
    else
      high = mid-1;
  }
  return NOTFOUND;
}

int main() {
  vector<int> sorted {3, 5, 10, 10, 10, 35, 40, 56};
  for (int i = 0; i < sorted.size(); i++) 
    cout << sorted[i] << ", ";
  cout << endl;  

  //cout << "bsearching 56=" << bsearch(sorted, 0, sorted.size()-1, 56) << endl;
  cout << "bsearching 56=" << bsearch2(sorted, sorted.size(), 56) << endl;


  return 0;
}
