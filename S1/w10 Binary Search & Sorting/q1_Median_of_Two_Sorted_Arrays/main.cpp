// https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/
// Time: O(log(min(n, m))
// Mem: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        parition i: arr[0] to arr[i-1] belongs to the left partition
        
        ex1 odd)
        total_length = 4 + 5 = 9
        A: 1 3 5 | 7    partition A: 3
        B: 2 4 | 6 8 9  partition B: 2
        --> median value: maximum value of the left partition
        
        ex2 even)
        total_length = 4 + 4 = 8
        A: 1 3 | 5 7    partition A: 2
        B: 2 4 | 6 8    partition B: 2
        
        par_A + par_B = (len_A + len_B + 1) / 2
        when t_len even: (max of left part + min of right part)/2
                    odd: max of left part
                    
        // exceptional handling
        partition 0: left part value as -inf
        partition len_A: right part value as +inf
        
        // meaning of finding median as a partition condition
        if max of each left partition of arrays is smaller than the min of each right partition of arrays --> condition is met
        else // keep binary search on partition A
        if( A[par_A-1] > B[par_B] ) --> update partition A ( lower )
        else if( B[par_B-1] > A[par_A] ) --> update partition A ( higher )
        */
      if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2, nums1);
      
      int len_A = nums1.size();
      int len_B = nums2.size();
      bool even =  (len_A+len_B)%2 == 0;
      int parA_B = (len_A + len_B + 1)/2;
      int bs_s = 0;
      int bs_e = len_A;
      
      while(true) {
        int par_A = ( bs_s + bs_e ) / 2;
        int par_B = parA_B - par_A;
        
        // load value
        int left_max_A = (par_A-1 < 0) ? std::numeric_limits<int>::min() : nums1[par_A-1];         
        int left_max_B = (par_B-1 < 0) ? std::numeric_limits<int>::min() : nums2[par_B-1];
        int right_min_A = (par_A == len_A) ? std::numeric_limits<int>::max() : nums1[par_A];
        int right_min_B = (par_B == len_B) ? std::numeric_limits<int>::max() : nums2[par_B];        
        
        int left_max = std::max(left_max_A, left_max_B);
        int right_min = std::min(right_min_A, right_min_B);
        
        // condition satisfies for median
        if( left_max <= right_min ) {
          if(even) return (double)(left_max+right_min)/2; 
          else return (double)left_max;  
        }
        // newly scope
        else if( left_max_A > right_min_B ) bs_e = par_A-1; 
        else bs_s = par_A+1;
      }
    }
};
