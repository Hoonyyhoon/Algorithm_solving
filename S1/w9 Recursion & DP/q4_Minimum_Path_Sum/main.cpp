// https://leetcode.com/problems/minimum-path-sum/
// Time: O(m*n)
// Memory: O(m*n)

#include <limits>
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    /*
    goes down to right bottom
    subproblem
    DP[i][j] = std::min(DP[i-1][j]+cost[i][j], DP[i][j-1]+cost[i][j])
    */
    // exception : irregular
    if (grid.empty()) return std::numeric_limits<int>::min();

    int n_r = grid.size();  // max row
    int n_c = grid[0].size();  // max col
    vector<vector<int>> DP(n_r, vector<int>(n_c, 0));
    DP[0][0] = grid[0][0];

    // fill first row and column
    for (int row = 1; row < n_r; row++)
      DP[row][0] = DP[row - 1][0] + grid[row][0];
    for (int col = 1; col < n_c; col++)
      DP[0][col] = DP[0][col - 1] + grid[0][col];

    // exception: one way
    if (n_r == 1) return DP[0][n_c - 1];
    if (n_c == 1) return DP[n_r - 1][0];

    // iterate
    for (int row = 1; row < n_r; row++)
      for (int col = 1; col < n_c; col++)
        DP[row][col] =
            std::min(DP[row][col - 1], DP[row - 1][col]) + grid[row][col];

    return DP[n_r - 1][n_c - 1];
  }
};
