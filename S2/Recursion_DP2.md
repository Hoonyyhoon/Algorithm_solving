# Recursion & DP 2

## Q4. Longest Increasing Subsequence([Link](https://leetcode.com/problems/longest-increasing-subsequence/solution/)) (:o:)

- Time: O(NlogN) (not sure yet)
- Space: O(N)
- Note <br/> 
```cpp
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    /*
    DP[i]: length of LIS choosing i as base
    DP[c]: max(DP[b] +1) , among b>c & nums[b] > nums[c]
    */
    // O(N^2) O(N)
    if (nums.empty()) return 0;
    std::vector<int> DP(nums.size(), 1);
    int max_val = DP.back();
    // going down
    for (int d = nums.size() - 2; d >= 0; d--) {
      for (int u = d + 1; u < nums.size(); u++) {
        if (nums[d] >= nums[u]) continue;
        DP[d] = std::max(DP[d], DP[u] + 1);
      }
      max_val = std::max(max_val, DP[d]);
    }
    return max_val;
  }

  int lengthOfLIS2(vector<int>& nums) {
    // O(NlogN)(?) O(N)
    if (nums.empty()) return 0;
    std::vector<int> DP(nums.size(), 1);
    std::multimap<int, int, std::greater<int>> ordered_dp;  // DP value, index
    ordered_dp.insert(std::pair<int, int>(DP.back(), nums.size() - 1));
    int max_val = DP.back();
    // going down
    for (int d = nums.size() - 2; d >= 0; d--) {
      for (auto& iter : ordered_dp) {
        if (nums[d] >= nums[iter.second]) continue;
        DP[d] = std::max(DP[d], iter.first + 1);
        break;
      }
      ordered_dp.insert(std::pair<int, int>(DP[d], d));
      max_val = std::max(max_val, DP[d]);
    }
    return max_val;
  }
};
```
