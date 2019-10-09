// https://leetcode.com/problems/add-two-numbers/
// Time : O(max(M,N))
// Memory : O(1)  //reuse

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
      // dont know which one is longer      
      auto r1 = l1;
      auto r2 = l2;
      
      bool carry_over = false;
      bool r1_done = false;
      bool r2_done = false;
      int l1_cnt = 0;
      int l2_cnt = 0;
      
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
        
        if(!r1_done) {
          r1->val = value;
          l1_cnt++;
        }
        if(r1->next) r1 = r1->next;
        else r1_done = true;
        
        if(!r2_done) {
          r2->val = value;
          l2_cnt++;
        }
        if(r2->next) r2 = r2->next;
        else r2_done = true;
      }
      
      if(l1_cnt>l2_cnt) {
        if(carry_over) {
          ListNode *ins = new ListNode(1);
          r1->next = ins;
        }
        return l1;
      }
      else {
        if(carry_over) {
          ListNode *ins = new ListNode(1);
          r2->next = ins;
        }
        return l2;
      }
    }
};
