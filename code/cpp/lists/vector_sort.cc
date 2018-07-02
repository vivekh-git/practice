#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class myData {
public:
	int mData;
	string mSomeString;
	bool operator<(myData rhs) {
		return (mData < rhs.mData);
	}	
};

bool mysort1(const myData& lhs, const myData& rhs) {
	return (lhs.mData < rhs.mData);
}

int main() {
	vector<myData> arr;
	myData d;
	for (int i=0; i<20; i++) {
		d.mData = i;
		d.mSomeString = "string" + std::to_string(i);
		arr.push_back(d);
	}
	
	std::random_shuffle(arr.begin(), arr.end());
	cout << "before sorting" << endl;
    for (vector<myData>::iterator it=arr.begin(); it!=arr.end(); it++) {
  	  cout << (*it).mData << " ";
    }
	cout << endl;
	
	sort(arr.begin(), arr.end());
    //sort(arr.begin(), arr.end(), mysort1);
	cout << "after sorting" << endl;
	for (vector<myData>::iterator it=arr.begin(); it!=arr.end(); it++) {
  	  cout << (*it).mData << " ";
    }
    cout << endl;
	
	return 0;
}
