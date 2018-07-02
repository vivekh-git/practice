#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

bool isUniqueChars(string input);

bool isUniqueChars(string input) {
	/* 3 algos
	1. count occurrence of alphabets in string. And if any alphabet occurs more than once, return false
	2. store in bit map
	3. compare each letter with the rest of string
	4. sort string in place and look for repitition of chars.
	*/
	// count occurrence of alpha
	// assume alpha numerice means - 256 character set
	
	if (input.empty()) {
		return false;
	}
	
	if (input.length() > 256) {
                // string can be greater than 256
                // but each char need to be less than 256 for it to be alpha numeric
		//return false;
	}
	bool alpha_arr[256] = {};
	
	for (string::iterator it = input.begin(); it != input.end(); it++) {
		int val = *it;
		cout << "character is " << *it << " and int val is " << val << endl;
		cout << "flag is " << alpha_arr[val] << endl;
                if (val > 256) {
                   cout << "string has non alpha numeric characters" << endl;
                   return false;
                }
		if (alpha_arr[val]) {
			return false;
		}

		alpha_arr[val] = true;
	}
	return true;
}


int main() {
	string input;
	cout << "Enter String: " << endl;
	getline(cin, input);
	cout << "You entered: " << input << endl;
	
	bool flag = isUniqueChars(input);
	if (flag) {
		cout << "Your String : " << input << " has unique characters" << endl;
	}
	else if (input.empty()) {
		cout << "Your String : " << input << " is empty" << endl;
	}
	else {
	    cout << "Your String : " << input << " has non unique characters" << endl;	
	}
	
	return 0;
	
}
