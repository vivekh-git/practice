#include <iostream>
#include <string>
using namespace std;

// ""
// A
// AB
// ABC
// ABCD
void permute (string combo, string population, int& count) {
  // base case
  // string empty
  if (population == "") {
    cout << combo << endl;
    count++;
  }
  else {
    // slightly larger case - let us do AB - recurse to smaller one
    for (int i = 0; i < population.length(); i++) {
      string next = combo + population[i];
      string remaining = population.substr(0,i) + population.substr(i+1);
      //cout << "next - " << next << ", remaining - " << remaining << endl;
      permute (next, remaining, count);
    }
  }
  return;
}

int main() {
  int count = 0;
  permute("", "ABCD", count);
  // n factorial permutations
  cout << "count = " << count << endl;
  return 0;
}
