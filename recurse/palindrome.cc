#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
  if (str.length() <= 1) 
    return true;
  else
    return ((str[0] == str[str.length()-1]) &&
             isPalindrome(str.substr(1, str.length()-2)));
}


int main() {
  cout << "if 'gog' palindrome=" << isPalindrome("gog") << endl;
  cout << "if 'wasitacaroracatisaw' palindrome=" << isPalindrome("wasitacaroracatisaw") << endl;
  cout << "if 'gohangasalamiimalasagnahog' palindrome=" << isPalindrome("gohangasalamiimalasagnahog") << endl;


  return 0;
}
