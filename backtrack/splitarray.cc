#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool splitSum(vector<int> sofar, int start, int arrlen, int rest[], map<int,int>& tmap) {
  // base case
  if (start == arrlen) {
    // if sum of so far == target - return true else return false
    cout << "printing array..."<< endl;
    int sum = 0;
    for (int i=0; i < sofar.size(); i++) {
      cout << sofar[i] << ", ";
      sum = sum + sofar[i];
    }
    cout << "sum = " << sum << " , ending array.. " << endl;
    if (tmap.count(sum))
      return true;
    tmap[sum] = 1;
    return false;
  }
  else {
    // recurse with item included in set
    vector<int> next = sofar;
    next.push_back(rest[start]);
    if(splitSum(next, start+1, arrlen, rest, tmap)) return true;
    // recurse with item not included in set
    if (splitSum(sofar, start+1, arrlen, rest, tmap)) return true;
  }
  return false;
}

bool splitSum2(int sum, int start, int arrlen, int rest[], map<int,int>& tmap) {
  // base case
  if (start == arrlen) {
    // if sum of so far == target - return true else return false
    cout << "sum = " << sum << " , ending array.. " << endl;
    if (tmap.count(sum))
      return true;
    tmap[sum] = 1;
    return false;
  }
  else {
    // recurse with item included in set
    cout << "sum + rest[start] = " << sum+rest[start] << endl;
    if (splitSum2(sum+rest[start], start+1, arrlen, rest, tmap)) return true;
    // recurse with item not included in set
    cout << "sum = " << sum << endl;
    if (splitSum2(sum, start+1, arrlen, rest, tmap)) return true;
  }
  return false;
}


int main() {
  map<int, int> tMap {};
  vector<int> sofar {};
  int nums[] = {5, 2, 2}; int arrlen = 3; int sum = 0;
  bool s = splitSum2(sum, 0, arrlen, nums, tMap);
  cout << "splitting [5 2 2] into 2 groups of equal sum = " << s << endl;
  return 0;
}
