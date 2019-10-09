// https://leetcode.com/problems/coin-change/
// Time: O(N*M)
// Memory: O(M)

#include <limits>
class Solution {
 public:
  int coinChange(vector<int> &coins, int amount) {
    /*
    subproblem
    i : left to amount
    DP[i]: # of coins
    for j in coins:
      DP[i+j] = std::min(DP[i+j], DP[i]+1)
    */
    // exception
    if (amount <= 0) return 0;

    std::vector<int> DP(amount + 1, std::numeric_limits<int>::max());

    // init
    for (auto &iter : coins)
      if (amount >= iter) DP[iter] = 1;

    // iterate
    for (int i = 0; i < amount + 1; i++) {
      for (auto &iter : coins) {
        if (i - iter >= 0 && DP[i - iter] != std::numeric_limits<int>::max())
          DP[i] = std::min(DP[i - iter] + 1, DP[i]);
      }
    }
    if (DP.back() == std::numeric_limits<int>::max())
      return -1;
    else
      return DP.back();
  }
};
