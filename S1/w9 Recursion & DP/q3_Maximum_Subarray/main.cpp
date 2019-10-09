// https://leetcode.com/problems/maximum-subarray/
// Time: O(N)
// Memory: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        subproblem
        DP[i]: largest sum at i
        DP[i] = nums[i] +(DP[i-1]>0? DP[i-1] : 0);
        */
      //exception
      if(nums.empty()) return 0;
      int DP = nums[0];
      int max_sum = DP;
      for(int i=1; i<nums.size(); i++) {
        DP = nums[i] + (DP>0? DP : 0);
        max_sum = std::max(DP, max_sum);
      }
      return max_sum;
    }
};
