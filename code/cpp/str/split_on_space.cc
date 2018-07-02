#include <iostream>
#include <list>
#include <string>

using namespace std;
	
void split_string(string str) {
  list<string> words;
	
  if (str == "")
	 return;
  
  int length = str.length();
  bool quote = false;
  string sb;
  for (int i = 0; i < length; i++) {
    char ch = str[i];

    if (ch == '\"') {
      if (!quote) {
        quote = true;
      }
      else {
        quote = false;
      }
	  sb += ch;
    }
	
    else if (ch == ' ') {
      if (!quote && sb != "")  { // comment: if string is not empty.
        words.push_back(sb);
        sb.erase();
      }
	  else {
		sb += ch;
	  }
    } 
	else {
    	sb += ch;
    } 
	
  }
  if (sb != "")  { // comment: if string is not empty.
    words.push_back(sb);
    sb.erase();
  }
  
  cout<<"start" <<endl;
  for (list<string>::iterator it = words.begin(); it != words.end(); it++ ) {
	  cout << *it << endl;
  }
  cout<<"end" <<endl;
}


int main() {
	string st1 = "aa bb"; cout << st1 << endl;
	string st2 = "aa\" \"bb"; cout << st2 << endl;
	
	split_string(st1);
	split_string(st2);
}
