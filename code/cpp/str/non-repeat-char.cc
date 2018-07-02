#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

void print_non_repeat_char(std::string s) {
	std::map<char, int> charCount;
	
	if (s.empty()) {
		cout << "Your string :" << s << " is empty" << endl;
		return;
	}
	
    for (std::string::iterator it=s.begin(); it != s.end(); it++) {
		charCount[*it]++;
		
	}
	
	bool repeat_found = false; bool non_repeat_found = false;
	for (std::string::iterator it=s.begin(); it != s.end(); it++) {
		if (charCount[*it] == 1 && !non_repeat_found) {
			cout << "First non repeating character: " << *it << endl;
			non_repeat_found = true;
		}
		else if (charCount[*it] > 1 && !repeat_found) {
			cout << "First repeating character: " << *it << endl;
			repeat_found = true;
		}
                if (repeat_found && non_repeat_found) {
                        break;
                }
	}
	return;
}

int main() {
	string s;
	cout << "Enter a string: ";
	getline(cin, s);
	cout << "String entered is :" << s << endl;
	
	print_non_repeat_char(s);
	return 0;
}
