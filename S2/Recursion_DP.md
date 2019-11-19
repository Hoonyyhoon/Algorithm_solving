# Recursion & DP

## Q2. House Robber([Link](https://leetcode.com/problems/house-robber/)) (:o:)

- Time: O(N)
- Space: O(1)
- Note <br/> 
```cpp#include <queue>
class Solution {
 public:
  /*
  DP[i]: max_sum at i
  DP[0] = nums[0];
  DP[1] = max(nums[0], nums[1]);
  DP[i] = max(DP[i-2]+nums[i], DP[i-1])
  */
  int rob1(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    std::queue<int> DP;
    DP.push(nums[0]);
    DP.push(max(nums[0], nums[1]));

    for (int i = 2; i < nums.size(); i++) {
      int earlier = DP.front();
      DP.pop();
      DP.push(max(earlier + nums[i], DP.front()));
    }
    return DP.back();
  }
  int rob2(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);
    int DP[3] = {0};
    DP[0] = nums[0];
    DP[1] = max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++) {
      DP[2] = max(DP[0] + nums[i], DP[1]);
      DP[0] = DP[1];
      DP[1] = DP[2];
    }
    return DP[2];
  }
};
```
