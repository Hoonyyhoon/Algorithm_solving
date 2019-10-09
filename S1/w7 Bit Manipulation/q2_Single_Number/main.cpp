// https://leetcode.com/problems/single-number/
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    /* XOR
    property
    a ^0 = a
    a ^a = 0
    commutative
    O(N) / O(1)
    */

    int a = 0;
    for (auto& it : nums) {
      a ^= it;
    }
    return a;
  }
};
