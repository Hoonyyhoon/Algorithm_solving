/*
https://leetcode.com/problems/subsets/
Time : O(2^n*n)
Space : O(2^n-1) 
*/

class Solution {
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    /*
    1. for all combination of subsets,
    2. determine each element belongs to that certain combination
       ex) when elem = 5 (0x101)
        0x101 x 0x1 --> 1, shift
         0x10 x 0x1 --> 0, shift
          0x1 x 0x1 --> 1
    */

    int size = nums.size();
    int total_combination = pow(2, nums.size());
    const int bit_ = 0x01;

    std::vector<std::vector<int>> sol;
    sol.reserve(total_combination);

    for (int elem = 0; elem < total_combination; elem++) {
      std::vector<int> index_set;
      index_set.reserve(size);
      for (int n_shift = 0; n_shift < size; n_shift++) {
        if ((elem >> n_shift) & bit_) index_set.push_back(nums[n_shift]);
        if ((elem >> n_shift) == 0) break;
      }
      sol.push_back(index_set);
    }
    return sol;
  }
};
