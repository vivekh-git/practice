#include <iostream>
#include <string>

using namespace std;

const bool DEBUG = true;
class Solution {
public:
  bool isUnique(string& str) {
    // input validation
    if (str.length() > 256) return false;

    bool alpha[256] = {false}; int val=0;
    for (string::iterator it = str.begin(); it != str.end(); it++) {
      val = *it;
      if (alpha[val]) return false;
      alpha[val] = true;
    }
    return true;
  }
};


class Solution2 {
public:
  bool isUnique(string& str) {
    // input validation
    if (str.length() > 256) return false;
    int checker = 0; int ch=0;
    for (string::iterator it=str.begin(); it !=str.end(); it++) {
      ch = *it;
      if (DEBUG) cout << "ch - " << *it << endl;
      if (ch != 32) {
        ch = ch - 'a';  // assumes only a-z in string and space
      } else {
        ch = ch -1;
      }
      if (DEBUG) cout << "ch minus a" << ch << endl;
      if (checker & (1<<ch)) { if (DEBUG) {cout << ch << " bit is duped" << endl;} return false;}
      checker |= (1<<ch); 
      if (DEBUG) cout << "checker - " << checker << endl;
    }
    return true;
  }
};


int main() {
  string str = "this is reya";
  cout << "String - " << str << endl;
  Solution2 sol;
  bool uniq = sol.isUnique(str);
  if (uniq) { cout << "String is unique" << endl; }
  else { cout << "String is not unique" << endl; }
  return 0;
}
