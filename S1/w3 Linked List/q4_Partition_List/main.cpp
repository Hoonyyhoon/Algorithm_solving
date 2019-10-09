// https://leetcode.com/problems/partition-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // Time: O(N) Mem: O(1)
 
class Solution {
public:
  ListNode* partition(ListNode* head, int x) {
    auto left = new ListNode(0);
    auto right = new ListNode(0);

    auto it = head;
    auto i_l = left;
    auto i_r = right;
    
    while( it ) {
      if( it->val < x ) {
        i_l->next = it;
        i_l = i_l->next;
      }
      else {
        i_r->next = it;
        i_r = i_r->next;
      }
      it = it->next;
    }
    i_r->next = nullptr;

    // connect
    i_l->next = right->next;
    auto ret = left->next;
    delete right;
    delete left;
    
    return ret;
  }
};
