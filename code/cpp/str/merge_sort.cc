#include <iostream>
#include <vector>

using namespace std;

void merge(int a[], int low, int mid, int high, int b[]);
void copyArr(int b[], int low, int high, int a[]);
void mergeSort(int a[], int low, int high, int b[]) {
    cout << "mergeSort:" << low << " -- " << high << endl;
    if (low >= high) {return;}
    int mid = low + (high - low)/2;
    mergeSort(a, low, mid, b);
    mergeSort(a, mid+1, high, b);
    merge(a, low, mid, high, b);
    copyArr(b, low, high, a);
}

void copyArr(int b[], int low, int high, int a[]) {
    cout << "copyArr:" << low << " -- " << high << endl;
    for (int p=low; p <= high; p++) {
    	a[p] = b[p];
    }
}


void merge(int a[], int low, int mid, int high, int b[]) {
    cout << "merge:" << low << " -- " << mid << " -- " << high << endl;
    //int tmp[50] = {0};
    
    int x=low; int y=mid+1; int t=low;
    while ((x <= mid) && (y <= high)) {
    	if (a[x] <= a[y]) {
    		//tmp[t] = a[x];
    		b[t] = a[x];
    		x++;
    	}
    	else {
    		//tmp[t] = a[y];
    		b[t] = a[y];
    		y++;
    	}
    	t++;
    }
    if ( x > mid ) {
      for (int k=y; k<=high; k++) {
    	  //tmp[t] = a[k];
    	  b[t] = a[k];
    	  t++;
      }	
    }
    else if (y > high) {
    	for (int k=x; k<=mid; k++) {
    		//tmp[t] = a[k];
    		b[t] = a[k];
    	    t++;
    	}
    }
    // copy from tmp to a
    /*
    for (int k=low; k<=high; k++) {
    	a[k] = tmp[k];
    }
    for (int p=low; p<=high; p++) {
    	a[p] = b[p];
    }*/
}

int main () {
    int a[] = {1, 5, 8, 21, 2, 33, 7, 3};
    int len = sizeof(a)/sizeof(a[0]); 

    vector<int> seq (a, a+len);
    for (vector<int>::iterator it=seq.begin(); it != seq.end(); it++ ) {
        cout << *it << endl;
    }
    
    int b[len];
    mergeSort(a, 0, len-1, b);
    for (int i=0; i< len; i++) {
    	cout << a[i] << ", ";
    }
    cout << endl;

    return 0;
}
