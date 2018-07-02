#include <iostream>
#include <string>

using namespace std;

void recurSubset(string sofar, string rest) {
  if (rest == "") {
    cout << sofar << endl;
  }
  else {
    //n, k-1
    recurSubset(sofar + rest[0], rest.substr(1));
    // n-1, k-1
    recurSubset(sofar, rest.substr(1));
  }
}


void ListSubset(string str) {
  recurSubset("", str);
}

int main() {
  ListSubset("abcd");
  return 0;
}
