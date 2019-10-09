// https://leetcode.com/problems/linked-list-components/
// Time: O(N), Mem: O(M(size of set))
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
      std::unordered_set<int> set_(G.begin(), G.end());   // O(M)
      auto iter = head;
      int cnt = 0;
      
      // O(N)
      while( iter ) {
        if(set_.count(iter->val)) {
          cnt++;
          while( iter ) {
            iter = iter->next;
            if( !iter ) break;
            if( set_.count(iter->val)==0 ) break;
          }
        }
        else iter = iter->next;
      }
      return cnt;
    }
};
