# Recursion & DP 2

## Q2. Restore IP Addresses([Link](https://leetcode.com/problems/restore-ip-addresses/)) (:o:)
- Time: O(1)
- Space: O(1)
- Note <br/>
```cpp
class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    std::vector<std::string> res;
    std::string gen_str;
    recursiveAddress(s, 0, 0, gen_str, res);
    if (s.empty()) return res;
    return res;
  }

  void recursiveAddress(const std::string& s, int idx, int num_dots,
                        std::string gen_str, std::vector<std::string>& res) {
    // break cond
    if (idx >= s.size()) return;

    // end cond
    if (num_dots == 3) {
      // break cond 1. left over exceeds 3 digits
      if (s.size() - idx > 3) return;
      std::string check_str = s.substr(idx);
      int check_val = std::stoi(check_str);
      // if its valid
      if (check_str.size() >= 2 && check_str[0] == '0') return;
      if (check_val <= 255 & check_val >= 0) res.push_back(gen_str + check_str);
      return;
    }

    for (int i = 1; i < 4; i++) {
      std::string check_str = s.substr(idx, i);
      int check_val = std::stoi(check_str);
      // if its valid
      if (check_str.size() >= 2 && check_str[0] == '0') return;
      if (check_val <= 255 && check_val >= 0) {
        std::string sum_str = check_str + '.';
        std::string new_str = gen_str + sum_str;
        recursiveAddress(s, idx + i, num_dots + 1, new_str, res);
      }
    }
  }
};
```

## Q3. Maximum Product Subarray([Link](https://leetcode.com/problems/maximum-product-subarray/)) (:heavy_check_mark:)

- Time: O(N)
- Space: O(1)
- Note <br/> 
```cpp
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int ans = nums[0];
    int cur_max = nums[0];
    int cur_min = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < 0) std::swap(cur_max, cur_min);

      cur_max = std::max(nums[i], cur_max * nums[i]);
      cur_min = std::min(nums[i], cur_min * nums[i]);

      ans = std::max(ans, cur_max);
    }
    return ans;
  }
};
```

## Q4. Longest Increasing Subsequence([Link](https://leetcode.com/problems/longest-increasing-subsequence/solution/)) (:o:)

- Time: O(N^2)
- Space: O(N)
- Note <br/> Could you improve it to O(NlogN) time complexity? 
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
    // O(N^2) O(N)
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
