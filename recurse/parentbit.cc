#include <iostream>
#include <string>

using namespace std;

// 1(xy)1
// c++ substr uses length as second arg, java substring using endindex as second arg
// ()
string parenBit(string str) {
  cout << "str -- " << str << endl;
  // base case
  int len = str.length();
  if (len < 2) 
    return "";
  else if (str.at(0) != '(' && str.at(len-1) != ')')
    return parenBit(str.substr(1, len-2));
  else if (str.at(0) == '(' && str.at(len-1) != ')')
    return parenBit(str.substr(0, len-1));
  else if (str.at(0) != '(' && str.at(len-1) == ')')
    return parenBit(str.substr(1, len-1));
  else
    return str;
}


int main() {
  cout << parenBit("xyz(abc)123") << endl;
  cout << parenBit("x(hello)") << endl;
  /*
  cout << parenBit("()") << endl;
  cout << parenBit("x(hello)") << endl;
  cout << parenBit("1(xy)1") << endl;
  cout << parenBit("not really (possible)") << endl;
  cout << parenBit("(abc)xyz") << endl;
  cout << parenBit("(ab)") << endl;
  cout << parenBit("") << endl;
  */
  return 0;
}
