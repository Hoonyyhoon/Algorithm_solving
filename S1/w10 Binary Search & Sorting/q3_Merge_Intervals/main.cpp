// https://leetcode.com/problems/merge-intervals/
// Time: O(NlogN)
// Memory: O(N)
    
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::vector<std::vector<int>> res;
    if (intervals.empty()) return res;

   
    // sort(O(NlogN)) -> greedy(O(N))
    
    std::sort(intervals.begin(), intervals.end(),
              [](std::vector<int>& a, std::vector<int>& b) {
                // ascending order
                return a[0] < b[0];
              });
    res.push_back(intervals.front());

    for (int i = 1; i < intervals.size(); i++) {
      // res.back contains intervals
      // update res.back()
      if (res.back()[1] >= intervals[i][0])
        res.back()[1] = std::max(res.back()[1], intervals[i][1]);
      // insert current intervals so that assign new res.back
      else
        res.push_back(intervals[i]);
    }

    return res;
  }
};
