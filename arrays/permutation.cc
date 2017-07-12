#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  bool sortAndCompare(string str1, string str2) {
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    if (str1.length() != str2.length()) return false;
    int i=0; int len=str1.length();
    while (i < len) {
      if (str1.at(i) != str2.at(i)) return false;
      i++;
    }
    return true;
  }

  bool characterCountArray(string str1, string str2) {
    if (str1.length() != str2.length()) return false;
    int charArr[256] = {0}; char ch=0;
    for (int i = 0; i < str1.length(); i++) {
      ch = str1.at(i);
      charArr[ch]++;
    }
    for (int j = 0; j < str2.length(); j++) {
      ch = str2.at(j);
      charArr[ch]--;
      if (charArr[ch] < 0) return false;
    }
    //for (int k =0; k < 256; k++) {
    //  if (charArr[ch] !=0) return false;
    //}
    return true;
  }
};

int main() {
  string str1 = "godddd";
  string str2 = "goddgg";
  Solution sol;
  bool f = sol.characterCountArray(str1, str2);
  if (f) cout << str1 << " and " << str2 << " are premutations of each other" << endl;
  else cout << str1 << " and " << str2 << " are not premutations of each other" << endl;
  return 0;
}
