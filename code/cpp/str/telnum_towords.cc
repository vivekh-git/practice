#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

void printWords(list<string>& words, int input[], int pos, int input_size, map<int, string>& mapping) {
	cout << "printWords -- " << pos << endl;
	if (pos >= input_size) { return; }
	int mapindex = input[pos];
	string st = mapping[mapindex]; 
	string schar;
	list<string>::iterator it2; 
	
	while (words.front().length() <= pos) {
		it2 = words.begin();
		bool initial = words.empty();
		it2 = words.begin();
		for (string::iterator it1=st.begin(); it1!=st.end(); it1++) {
			if (initial) {
				schar = *it1;
				words.push_back(schar);
			}
			else {
				schar = *it2 + *it1;
				words.push_back(schar);
			}
		}
		if (st.empty()) {
			if (initial) {
				schar = to_string(mapindex);
			    words.push_back(schar);
			}
			else {
				schar = *it2 + to_string(mapindex);
				words.push_back(schar);
			}
		}
		if (!initial) words.pop_front();
	}
	printWords(words, input, ++pos, input_size, mapping);
	return;
}


int main () {
   list<string> words;

   map<int, string> mapping;
   mapping[1] = "";
   mapping[2] = "ABC";
   mapping[3] = "DEF";
   mapping[4] = "GHI";
   mapping[5] = "JKL";
   mapping[6] = "MNO";
   mapping[7] = "PQRS";
   mapping[8] = "TUV";
   mapping[9] = "WXYZ";
   mapping[0] = "";
	

   //cout << "Enter number: ";
   //cin >> input;
   // 1800 COMCAST = 1800 2662278
   //int input[2] = {1, 2};
   //int input[7] = {9,3,6,2,1,7,0};
   //int input[9] = {1,1,2,6,6,2,2,7,8};
   int input[10] = {8,8,8,3,7,1,8,9,2,2};
   int input_size = sizeof(input)/sizeof(input[0]);
   //cout << "number inputted is - " << input << endl;
   
   printWords(words, input, 0, input_size, mapping);
 
   int counter = 0;
   for (list<string>::iterator it=words.begin(); it != words.end(); it++) {
	   cout << *it << endl;
	   counter++; 
	   /*
	   if (*it == "11COMCAST") {
		   cout << "String 11COMCAST FOUND" << endl; return 0;
	   }*/
   }
   cout << "counter -- " << counter << endl;
   
   return 0;
	
}
