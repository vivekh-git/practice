#include <iostream>
using namespace std;

void swap(int* a, int x, int y) {
	int tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;
}

void merge(int* a, int start, int mid, int last) {
   cout << "merge: " << start << " -- " << mid << " -- " << last << endl;
   	//first sorted array start - mid, 
	// second sorted array  mid+1 - last
	int tmp[100] = {0};
	int x = start; int y=mid+1; int t=start;
	
	while ((x <= mid) && (y <= last)) {
		if (a[x] <= a[y]) {
			tmp[t] = a[x];
			x++;
			t++;
		}
		else {
			tmp[t] = a[y];
			y++;
			t++;
		}
	}
	
	if ( x > mid ) {
	  for (int k=y; k<=last; k++) {
		  tmp[t] = a[k];
		  t++;
	  }	
	}
	else if (y > last) {
		for (int k=x; k<=mid; k++) {
			tmp[t] = a[k];
		    t++;
		}
	}
	
	/*
	while (x > mid) {
		tmp[t] = a[y];
		y++;
		t++;
	}
	while (y > last) {
		tmp[t] = a[x];
		x++;
		t++;
	}
	*/
	
	for (int p=start; p<=last; p++) {
		a[p] = tmp[p];
	}

}


void merge_sort(int* a, int start, int last) {
   cout << "merge_sort: " << start << " -- " << last << endl;
	if (start >= last) return;
	int mid = start + (last-start)/2;
	
	merge_sort(a, start, mid);
	merge_sort(a, mid+1, last);
	
	merge(a, start, mid, last);
	
	return;
}



int main() {
	int a[] = {3, 20, 5, 45, 9,2, 7, 15, 11};
	int len = sizeof(a)/sizeof(a[0]);
	int sindex = 0;
	
	for (int i=0; i< len; i++) {
		cout << a[i] << ", ";
	}
	cout<< endl;
	
	merge_sort(a, sindex, len-1);
	
	for (int i=0; i< len; i++) {
		cout << a[i] << ", ";
	}
	cout<< endl;
	return 0;
}