// https://leetcode.com/problems/search-in-rotated-sorted-array/
// Time: O(logN)
// Mem: O(1)

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    /*
    pivot: # of rotating elem
    scope: [start, end]
    */
    if (nums.empty()) return -1;

    int start = 0;
    int end = nums.size() - 1;

    while (end >= start && (start + end) / 2 < nums.size()) {
      int guess_idx = (start + end) / 2;

      // 0) end==start
      if (end == start) {
        if (nums[end] == target)
          return end;
        else
          return -1;
      }

      // 1) match with tgt
      if (nums[guess_idx] == target) return guess_idx;

      // 2) move guessing
      // 2-1) pivot is on left
      else if (nums[guess_idx] < nums[start]) {
        // if value expected to be in the non pivot part
        if (target <= nums[end] && target > nums[guess_idx])
          start = guess_idx + 1;
        // else: scope to pivot part
        else
          end = guess_idx - 1;
      }
      // 2-2) pivot is on right
      else if (nums[guess_idx] > nums[end]) {
        // if value expected to be in the non pivot part
        if (target >= nums[start] && target < nums[guess_idx])
          end = guess_idx - 1;
        // else: scope to pivot part
        else
          start = guess_idx + 1;
      }
      // 2-3) normal sorted array(pivot doesn't exist in the scope)
      else {
        if (nums[guess_idx] < target)
          start = guess_idx + 1;
        else
          end = guess_idx - 1;
      }
    }
    return -1;
  }
};
