// https://leetcode.com/problems/add-two-numbers/
// newly make summed list
// Time complexity O(max(N, M))
// Mem complexity O(max(N, M)+1)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      auto r1 = l1;
      auto r2 = l2;
 
      ListNode* sum_node = new ListNode(0);
      auto begin = sum_node;
      auto ref = begin;
      bool carry_over = false;
      bool r1_done = false;
      bool r2_done = false;
      
      while(!r1_done || !r2_done) {
        int value = 0;
        if(carry_over) {
          value = 1;
          carry_over = false;
        }
        
        if(!r1_done) value+=r1->val;
        if(!r2_done) value+=r2->val;
        
        if(value >=10) {
          value %=10;
          carry_over = true;
        }
        ListNode* ins = new ListNode(value);
        ref->next = ins;
        ref = ref->next;
        if(r1->next) r1 = r1->next;
        else r1_done = true;
        if(r2->next) r2 = r2->next;
        else r2_done = true;
      }
      
      // if there exist carry over
      if(carry_over) {
        ListNode* ins = new ListNode(1);
        ref->next = ins;
      }
      return begin->next;
      }
};
