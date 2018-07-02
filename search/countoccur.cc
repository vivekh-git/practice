#include <iostream>
#include <vector>
using namespace std;

const int NOTFOUND = -1;
int bsearch(vector<int>& arr, int start, int end, int search, bool searchfirst) {
  if (start > end) 
    return NOTFOUND;
  int mid = (start + end) / 2;
  int ret = -1; int index = -1;
  if (search == arr.at(mid)) {
    ret = mid;
    if (searchfirst)
      index = bsearch(arr, start, mid-1, search, searchfirst);
    else
      index = bsearch(arr, mid+1, end, search, searchfirst);
  }
  else if (search < arr.at(mid)) {
    index =  bsearch(arr, start, mid-1, search, searchfirst);
  }
  else {
    index =  bsearch(arr, mid+1, end, search, searchfirst);
  }

  if (ret == -1 && index != -1)
    return index;

  if (ret != -1 && index != -1) {
    if (searchfirst) {
      return ((ret < index) ? ret : index);
    }
    else {
      return ((ret > index) ? ret : index);
    }
  }

  return ret;
}

int countoccur(vector<int>& arr, int search) {
  int firstindex = bsearch(arr, 0, arr.size()-1, search, true);
  int lastindex = -1;
  if (firstindex == -1) { // not found
    cout << search << " not found in arr" << endl;
    return -1;
  }
  cout << "firstindex = " << firstindex << endl;
  lastindex = bsearch(arr, 0, arr.size()-1, search, false);
  cout << "lastindex = " << lastindex << endl;
  cout << "count of " << search << " = " <<  lastindex-firstindex+1 << endl;
  return lastindex-firstindex+1;
}

int bsearch2(vector<int>& arr, int size, int search, bool searchfirst) {
  if (size <= 0) return NOTFOUND;
  int low = 0;
  int high = size-1;
  int ret = -1;

  while (low <= high) {
    int mid = low + ((high-low)/2);
    if (search == arr.at(mid)) {
      ret = mid;
      if (searchfirst) 
        high = mid-1;
      else
	low = mid+1;
    }
    else if (search > arr.at(mid)) {
      low = mid+1;
    }
    else {
      high = mid-1;
    }
  }
  return ret;
}

int countoccur2(vector<int>& arr, int search) {
  int firstindex = bsearch2(arr, arr.size(), search, true);
  int lastindex = -1;
  if (firstindex == -1) { // not found
    cout << search << " not found in arr" << endl;
    return -1;
  }
  lastindex = bsearch2(arr, arr.size(), search, false);
  cout << "count of " << search << " = " <<  lastindex-firstindex+1 << endl;
  return lastindex-firstindex+1;
}

int main() {
  vector<int> sorted {3, 12, 15, 20, 25, 30, 40, 56};
  for (int i = 0; i < sorted.size(); i++) 
    cout << sorted[i] << ", ";
  cout << endl;  

  int count = countoccur(sorted, 10);
  cout << "count of 10 = " << count << endl;

  return 0;
}
