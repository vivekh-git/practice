#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

void merge(std::vector<int> &arr, std::vector<int> &arr1, std::vector<int> &arr2);

template <typename T>
void swap(T &num1, T &num2) {
  T tmp = num1;
  num1 = num2;
  num2 = tmp;
}

template <typename T>
void print_arr(std::vector<T> &arr) {
  std::cout << "DEBUG: print_arr:" << std::endl;
  for (int i = 0; i < arr.size(); i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << std::endl;
}

void selection_sort(std::vector<int> &arr) {
  // find minimum and swap with first element
  int compares = 0; int inserts = 0; int length = arr.size();
  for (int i = 0; i < arr.size()-1; i++) {
    int minindex = i;
    for (int j = i+1; j < arr.size(); j++) {
      ++compares;
      if (arr[j] < arr[minindex]) {
        minindex = j;
      }
    }
    ++inserts;
    swap(arr[i], arr[minindex]); 
  }
  std::cout << "DEBUG: selection_sort: stats: compares:"<< compares << ", inserts:"<< inserts<<", size:"<< length<< std::endl;
}

// not bubblesort
void bubble_sort(std::vector<int> &arr) {
  // assume first element is sorted
  // take second element and insert before if smaller
  // given jth element,
  // look at 0 to j-1 and and identify which is larger than jth element and swap
  int compares = 0; int inserts = 0; int length = arr.size();
  for (int i = 1; i < arr.size(); i++) {
    for (int j = 0; j < i; j++) {
      compares++;
      if (arr[j] > arr[i]) {
        swap(arr[j], arr[i]);
	inserts++;
      }
    }
  }
  std::cout << "DEBUG: bubble_sort: stats: compares:"<< compares << ", inserts:"<< inserts<<", size:"<< length<< std::endl;
}

void insertion_sort(std::vector<int> &arr) {
  // take a element and insert into right position, sliding remaining items out
  int compares = 0; int inserts = 0; int length = arr.size();
  for (int i = 1; i < arr.size(); i++) {
    int current = arr[i]; int j=0;
    for (j = i-1; j >= 0 && arr[j] > current ; j--) {
      compares++;
      inserts++;
      arr[j+1] = arr[j]; //sliding elements out
    }
    inserts++;
    arr[j+1] = current;
  }
  std::cout << "DEBUG: insertion_sort: stats: compares:"<< compares << ", inserts:"<< inserts<<", size:"<< length<< std::endl;
}

void copyvector(std::vector<int>::iterator inputbegin,
                std::vector<int>::iterator inputend, 
	        std::vector<int>::iterator outputbegin) {
  //std::cout << "DEBUG: copyvector:" << *inputbegin << " - " << *inputend << " - " << *outputbegin << std::endl;
  while (inputbegin != inputend) {
    *outputbegin = *inputbegin;
    outputbegin++; inputbegin++;
  }
}


void merge_sort(std::vector<int> &arr) {
  if (arr.size() > 1) {
    int n1 = arr.size() /2;
    std::vector<int> first(arr.begin(), arr.begin() + n1);
    std::vector<int> second(arr.begin() + n1, arr.end());
    merge_sort(first);
    merge_sort(second);
    merge(arr, first, second);
  }
}

void merge(std::vector<int> &arr, std::vector<int> &arr1, std::vector<int> &arr2) {
  int arrindex = 0;
  int firstindex = 0;
  int secondindex = 0;
  while (firstindex < arr1.size() && secondindex < arr2.size()) {
    if (arr1[firstindex] < arr2[secondindex]) {
      arr[arrindex++] = arr1[firstindex++];
    }
    else {
      arr[arrindex++] = arr2[secondindex++];
    }
  }
  while (firstindex < arr1.size()) {
    arr[arrindex++] = arr1[firstindex++];
  }
  while (secondindex < arr2.size()) {
    arr[arrindex++] = arr2[secondindex++];
  }
}

// default comparison operator
template <typename T>
int operatorCmp(T a, T b) {
  if (a == b) return 0;
  return (a < b ? -1 : 1);
}

/*
 * take arr[start] as pivot
 * move left pointer from start+1 and go right, move right pointer from stop and go left
 * identify left index where element is greater than pivot
 * identify right index where element is less than pivot
 * swap those elements
 * do this until left pointer and right pointer cross over or equal to each other 
 * entire thing above is one parse
 * when pointers cross over, compare pivot element with element at pointer and if needed swap.
 * identify wher pivot is- either at start or at leftpointer cross over and return pivot index.
 */
template <typename T>
int partition_vector(std::vector<T> &arr, int startindex, int stopindex, int (cmp)(T, T)) {
  T pivot = arr[startindex]; 
  int pivotindex = startindex;
  int left = startindex + 1;
  int right = stopindex;
  while (true) {
    while ((cmp(arr[right], pivot) >= 0) && left < right) {
      right--;
    }
    while ((cmp(arr[left], pivot) < 0) && left < right) {
      left++;
    }
    if (left == right) break;
    // swap
    swap(arr[left], arr[right]);
  }
  if (cmp(arr[left], pivot) >= 0)  return startindex;
  swap(arr[startindex], arr[left]);
  return left;
}

template <typename T>
void quick_sort_internal(std::vector<T> &arr, int startindex, int stopindex, int (cmp)(T, T)) {
  if (stopindex > startindex) { // base case
    //print_arr(arr);
    int pivot = partition_vector(arr, startindex, stopindex, cmp);
    quick_sort_internal(arr, startindex, pivot-1, cmp);
    quick_sort_internal(arr, pivot+1, stopindex, cmp);
  }
}

template <typename T>
void quick_sort(std::vector<T> &arr, int (cmp)(T, T) = operatorCmp) {
  // find a partition element
  // put elements smaller than partition element to left of it and elements greater than to right of it.
  // recurse and repeat same thing in left partition and same thing in right partition.
  // this is the standard used in most libraries
  quick_sort_internal(arr, 0, arr.size()-1, cmp);  
}


int main() {
  std::vector<int> arr {92, 45, 67, 41, 74, 28, 87, 8, 67, 15, 59 };
  std::vector<int> arr2 { 92, 45, 67, 41, 74, 28, 87, 8, 67, 15, 59 };
  std::vector<int> arr3 { 92, 45, 67, 41, 74, 28, 87, 8, 67, 15, 59 };
  std::vector<int> arr4 { 92, 45, 67, 41, 74, 28, 87, 8, 67, 15, 59 };
  std::vector<int> arr5 { 45, 41, 28, 92, 74, 67, 87, 8, 67, 15, 59 };
  //selection_sort(arr);
  //bubble_sort(arr2);
  //insertion_sort(arr3);
  //merge_sort(arr4);
  quick_sort(arr5);
  //print_arr(arr);
  //print_arr(arr2);
  //print_arr(arr3);
  //print_arr(arr4);
  print_arr(arr5);

  std::vector<std::string> arr6 {"vivek", "reya", "sudha", "hari", "ram", "ramesh"};
  quick_sort(arr6);
  print_arr(arr6);

  return 0;
}
