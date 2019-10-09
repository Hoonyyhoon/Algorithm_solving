// https://leetcode.com/problems/trapping-rain-water/

class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.size() <= 2) return 0;

    // store max left, right for all position
    std::vector<int> max_upwards;
    std::vector<int> max_downwards;
    max_upwards.resize(height.size());
    max_downwards.resize(height.size());
    // fill max up
    max_upwards[0] = height[0];
    for (int i = 1; i < height.size(); i++) {
      if (max_upwards[i - 1] <= height[i])
        max_upwards[i] = height[i];
      else
        max_upwards[i] = max_upwards[i - 1];
    }

    // fill max down
    max_downwards[height.size() - 1] = height.back();
    for (int i = height.size() - 2; i >= 0; i--) {
      if (max_downwards[i + 1] <= height[i])
        max_downwards[i] = height[i];
      else
        max_downwards[i] = max_downwards[i + 1];
    }
    int fill = 0;
    for (int i = 0; i < height.size(); i++) {
      int diff_h = std::min(max_upwards[i], max_downwards[i]) - height[i];
      if (diff_h > 0) fill += diff_h;
    }
    return fill;
  }
};
