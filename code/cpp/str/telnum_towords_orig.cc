#include <iostream>
#include <string>
#include <list>
#include <map>

using namespace std;

void printWords(list<string>& words, int input[], int pos, int input_size, map<int, string>& mapping) {
	//cout << "printWords -- " << i << endl;
	if (pos >= input_size) { return; }
	
	list<string> cache;
	for (list<string>::iterator it= words.begin(); it != words.end(); it++) {
		cache.push_back(*it);
	}
	
	words.clear();
	int mapindex = input[pos];
	//cout << "mapindex -- " << mapindex << endl;
	string st = mapping[mapindex]; string st2; string schar;
	//cout << "st -- " << st << endl;
	if (cache.empty()) {
		for (string::iterator it=st.begin(); it!=st.end(); it++) {
			schar = *it;
			words.push_back(schar);
		}
	}
	else {
		for (string::iterator it1=st.begin(); it1!=st.end(); it1++) {
			for (list<string>::iterator it2=cache.begin(); it2!=cache.end(); it2++) {
				st2 = *it2 + *it1;
				words.push_back(st2);
			}
		}
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
   int input[7] = {2,6,6,2,2,7,8};
   //int input[10] = {8,8,8,3,7,1,8,9,2,2};
   int input_size = sizeof(input)/sizeof(input[0]);
   //cout << "number inputted is - " << input << endl;
   
   printWords(words, input, 0, input_size, mapping);
 
   int counter = 0;
   for (list<string>::iterator it=words.begin(); it != words.end(); it++) {
	   cout << *it << endl;
	   counter++; /*
	   if (*it == "COMCAST") {
		   cout << "String COMCAST FOUND" << endl; return 0;
	   }*/
   }
   cout << "counter -- " << counter << endl;
   
   return 0;
	
}
