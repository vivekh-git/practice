#include <iostream>
#include <string>

using namespace std;

bool strCopies(string str, string sub, int n) {
  int len = str.length();
  int sublen = sub.length();
  size_t found = str.find(sub);

  // base case
  if (len == 0)
    if (n == 0)
      return true;
    else
      return false;
  else if (found != string::npos)
    return strCopies(str.substr(found+1), sub, n-1);
  else if (n > 0) 
    return false;
  else
    return true;
}

int strDist(string str, string sub) {
  int len = str.length();
  int sublen = sub.length();

  // base case
  if (len == 0)
    return 0; // come back and correct
  else if ((str.substr(0,sublen) == sub) &&
           (str.substr(len-sublen, sublen) == sub))
    return len;
  else if (str.substr(0,sublen) != sub)
    return strDist(str.substr(1), sub);
  else
    return strDist(str.substr(0,len-1), sub);
}



int main() {
  cout << "9-" << strDist("catcowcat", "cat") << endl;
  cout << "3 - " << strDist("catcowcat", "cow") << endl;
  cout << "9-" << strDist("cccatcowcatxx", "cat") << endl;
  cout << "12-" << strDist("abccatcowcatcatxyz", "cat") << endl;
  return 0;
}
