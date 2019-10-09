# https://leetcode.com/problems/sum-of-two-integers/
# O(1) / O(1)
class Solution {
 public:
  int getSum(int a, int b) {
    /*
    5  101
    6  110
    3  011
    XOR --> when 0

    for every bit
    by going up, if both 1,
    0 0 --> 0
    0 1 // 1 0 --> 1
    1 1 --> 0, up count
    */
    bool up_bit = false;
    int sum = 0;
    for (int i = 0; i < 32; i++) {
      int a_bit = (a >> i) & 1;
      int b_bit = (b >> i) & 1;
      // 0, up
      if (a_bit == 1 && b_bit == 1) {
        if (up_bit) sum |= (1 << i);  // set value as 1
        else sum &= ~(1 << i);  // set value as 0
        up_bit = true;
      }
      // both 0
      else if (a_bit == 0 && b_bit == 0) {
        if (up_bit) sum |= (1 << i);  // set value as 1
        else sum &= ~(1 << i);  // set value as 0
        up_bit = false;
      }
      // 1 0 // 0 1
      else {
        if (up_bit) {
          sum &= ~(1 << i);  // set value as 0
          up_bit = true;
        } else {
          sum |= (1 << i);  // set value as 1
          up_bit = false;
        }
      }
    }
    return sum;
  }
};
