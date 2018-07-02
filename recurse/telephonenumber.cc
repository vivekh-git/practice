#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, string> dict = {{'1', " "},
 			  {'2', "ABC"},
			  {'3', "DEF"},
			  {'4', "GHI"},
			  {'5', "JKL"},
			  {'6', "MNO"},
			  {'7', "PQRS"},
			  {'8', "TUV"},
			  {'9', "WXYZ"},
			  {'0', "+"}
			};

void permuteNumber(string build, string population) {
  if (population == "") {
    cout << build << endl;
  }
  else {
    // 123
    int i = 0;
    string mapstr = dict[population[i]]; // ABC
    //cout << "mapstr - " << mapstr << endl;
    if (mapstr.empty()) {
      permuteNumber(build, population.substr(1));
    }
    else {
      for (int j=0; j<mapstr.length(); j++) { // DEF
        string next = build + mapstr[j];
        string remaining = population.substr(1);
        permuteNumber(next, remaining); // XA, 3
      }
    }
  }
}

void ListPermutations(string number) {
  permuteNumber("", number);
}


int main() {
  /*
  for (map<int, string>::iterator it = dict.begin(); it != dict.end(); it++) {
    cout << it->first << "-" << it->second << endl;
  }*/

  ListPermutations("213");

  return 0;
}
