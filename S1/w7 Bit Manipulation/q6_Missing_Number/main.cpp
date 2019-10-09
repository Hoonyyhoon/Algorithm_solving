#https://leetcode.com/problems/missing-number/
#include <unordered_set>
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      // 1) naive: save set find non existing one O(N) O(1)
      std::unordered_set<int> s;
      int iter_num = nums.size()+1;
      for(auto &iter: nums) s.insert(iter);
      for(int i=0;i<iter_num; i++) if(s.find(i)==s.end()) return i;
      return 0;
      
      // 2) math  // O(N) O(1)
      int max_num = nums.size()+1;
      int sum = max_num*(max_num-1)/2;
      int arr_sum = 0;
      for(auto &iter: nums) arr_sum += iter;
      return sum-arr_sum;
      
      // 3) bit wise...?: utilizing concept from single number1 // O(N) / O(1)
      // ex) 0 1 3
      // 0^0^1^1^2^3^3 = 2
      int xor_res = 0;
      for(int i=1; i<nums.size()+1;i++) xor_res ^=(i^nums[i-1]);
      return xor_res;
    }
};
