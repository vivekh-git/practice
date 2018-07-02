#include <iostream>

using namespace std;

// 1 2 3 4 5 6 7 8
// 0 1 2 3 4 5 6 7
// 

class Minheap {
public:
	Minheap(int arr[], int size);
	~Minheap();
	void Minheapify(int i);
	int left(int i) { return 2*i + 1; } // 2i + 1
	int right(int i) { return 2*i + 2; }  // 2i + 2
	int parent(int i) { return ((i-1)/2) ;}
	int getMin() {return _arr[0];}
	int extractMin(); // remove root and run Minheapify(0) again
	
private:
    int _heapSize;
	int* _arr;
};

void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

Minheap::Minheap(int arr[], int size) {
	_arr = arr;
	_heapSize = size;
	int i = (_heapSize -1)/2;
	while (i >= 0) {
		Minheapify(i);
		i--;
	}
}

Minheap::~Minheap() {
  _arr = NULL;
  _heapSize =0;	
}

void Minheap::Minheapify(int i) {
	int smallest = i;
	int l = left(i);
	int r = right(i);
	if ((l < _heapSize)  && (_arr[l] < _arr[i])) {
		smallest = l;
	}
	if ((r < _heapSize)  && (_arr[r] < _arr[smallest])) {
		smallest = r;
	}
	if (smallest != i) {
		swap(&_arr[smallest], &_arr[i]);
		Minheapify(smallest); // do i need this ?
	}
}


int Minheap::extractMin() {
	if (_heapSize == 0) { return INT_MAX; }
	int root = _arr[0];
	
	if (_heapSize > 1) {
	  _arr[0] = _arr[_heapSize-1];
	  Minheapify(0);
    }
	_heapSize--;
	return root;
}

int kthSmallest(int arr[], int size, int k) {
	Minheap mh(arr, size);
    for (int i = 0; i<k-1; i++) {
    	mh.extractMin();
    }
	return mh.getMin();
}


int main() {
   int arr [] = { 1, 31, 5, 21, 17, 7, 11 };
   int n = sizeof(arr) / sizeof(arr[0]);
   cout << "n:" << n << endl;
   
   for (int i=0; i<n; i++) { cout << arr[i] << ", "; } cout << endl;
   
   int k;
   cout << "enter k: ";
   cin >> k;
 
   int element = kthSmallest(arr, n, k);
   cout << "kth element: " << element << endl;
   return 0;
}