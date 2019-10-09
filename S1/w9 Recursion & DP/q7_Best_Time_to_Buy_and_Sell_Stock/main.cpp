// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Time: O(n)
// Mem: O(1)

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // buy firt and sell next
    // find minimum difference
    // if min>0 : just return 0
    /*
    DP: vector pair<min_value, min_diff>
    subproblem
    if(DP[i-1].first - prices[i] < DP[i-1].second) DP[i].second = DP[i-1].first
    - prices[i];
    else DP[i].second = DP[i-1].second;
    if( DP[i-1].first> prices[i] )  DP[i].first = prices[i];  //new min
    else DP[i].first = prices[i];
    */

    // exception
    if (prices.size() <= 1) return 0;
    // init
    std::pair<int, int> memo(prices[0], 0);
    for (int i = 1; i < prices.size(); i++) {
      // update solution(min_diff)
      if (memo.first - prices[i] < memo.second)
        memo.second = memo.first - prices[i];
      // update new min
      if (memo.first > prices[i]) memo.first = prices[i];
    }
    if (memo.second > 0)
      return 0;
    else
      return -memo.second;
  }
};
