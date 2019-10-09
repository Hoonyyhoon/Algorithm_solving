#https:  // leetcode.com/problems/majority-element/
#include <unordered_map>
#include <map>

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    /*
    size. sum
    1 1 1 1 1 10000
    */

    /* 1) hashmap // O(N), O(N/2) since it contains same value at least n/2
    std::unordered_map<int, int> m;
    int size_thres = nums.size()/2+1;
    for(auto &iter: nums) {
      if(m.find(iter)!=m.end()) m[iter]++;
      else m[iter] = 1;
      if(m[iter]>=size_thres) return iter;
    }
    // never happens
    return 0;
    */

    // 2) using bit operation // O(N*32), O(1)
    int majority = 0;
    for (unsigned int i = 0, mask = 1; i < 32; i++, mask <<= 1) {
      int bits = 0;
      for (int num : nums) if (num & mask) bits++;
      if (bits > nums.size() / 2) majority |= mask;  // bit change specific pos(mask)
    }
    return majority;
  }
};
