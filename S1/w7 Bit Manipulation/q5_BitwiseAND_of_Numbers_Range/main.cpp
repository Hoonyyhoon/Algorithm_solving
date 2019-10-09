# https://leetcode.com/problems/bitwise-and-of-numbers-range/
# O(1) / O(1)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0;
        while(m!=n){
            m=m>>1;
            n=n>>1;
            ++i;        
        }
        return m<<i;
    }
};
