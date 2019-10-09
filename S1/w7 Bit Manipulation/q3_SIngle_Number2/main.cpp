# https://leetcode.com/problems/single-number-ii/
# reference : https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-number
# O(N) / O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
      for(int i=0; i<32; i++){
        int sum=0;
        for(auto &it: nums) sum+=(it>>i)&1;
        // set bit
        if(sum%3) res|=(1<<i);
      }
      return res;
    }
};
