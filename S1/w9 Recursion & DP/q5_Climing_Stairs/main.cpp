// https://leetcode.com/problems/climbing-stairs/
// Time O(n)
// Mem O(1)

#include <queue>
class Solution {
 public:
  int climbStairs(int n) {
    /*
    subproblem
    DP[2] = 2
    DP[1] = 1
    DP[i] = DP[i-1]+DP[i-2];
    */
    if (n <= 1)
      return 1;
    else if (n == 2)
      return 2;

    std::queue<int> DP;
    // save only 2
    DP.push(1);
    DP.push(2);

    for (int i = 2; i < n; i++) {
      int val3 = DP.front() + DP.back();
      DP.pop();
      DP.push(val3);
    }
    return DP.back();
  }
};
