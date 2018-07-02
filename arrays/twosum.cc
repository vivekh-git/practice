#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums_inp, int target) {

        // input validation
        if (nums_inp.empty()) assert(false);

        vector <int> result (2);
 		vector <int> nums = nums_inp;

        sort (nums.begin(), nums.end());
        
		vector<int>::iterator it_start = nums.begin();
        vector<int>::iterator it_end = nums.end(); it_end--;
  
        int temp_sum = 0;
        while (*it_start < *it_end) {
            temp_sum = *it_start + *it_end;
            if (target > temp_sum) {
                // temp_sum is smaller - need to increase - so increase the iterator of smaller num - start_pos
                ++it_start;
            }
            else if (target < temp_sum) {
                // temp_sum is bigger - need to reduce - so reduce the iterator of bigger num - end_pos
                --it_end;
            }
            else {
		int index = 0; int resultindex= 0;
                for (vector<int>::iterator it = nums_inp.begin(); it != nums_inp.end(); it++) {
		  if (*it == *it_start || *it == *it_end) {
		    result[resultindex++] = index;
		  }
		  index++;
		}
		return result;
            }
        }
	if ((*it_start + *it_end) == target) {
	  int index = 0; int resultindex= 0;
          for (vector<int>::iterator it = nums_inp.begin(); it != nums_inp.end(); it++) {
            if (*it == *it_start || *it == *it_end) {
              result[resultindex++] = index;
            }
            index++;
          }
          return result; 
        }
	assert(false);
    }
};


int main() {
    Solution sol;
    vector<int> input = {2,2,2};
    int target = 10;
    
    vector<int>result =  sol.twoSum(input, target);
    cout << " result -- [ ";
    for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}
