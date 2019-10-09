/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // https://leetcode.com/problems/palindrome-linked-list/
 // Time O(N)
 // Memory O(1)
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      if(!head || !head->next) return true;
      if(!head->next->next){
        if(head->val == head->next->val) return true;
        else return false;
      }
      bool odd = false;
      auto fast = head;
      auto slow = head;   // place at the middle
      while(fast->next && fast->next->next) {
          fast = fast->next->next;
          slow = slow->next;
      }
      if(!fast->next) odd = true;
      if(!odd) slow = slow->next;
      
      slow = reverse(slow);
      auto go_end = slow;
      fast = head;
      auto fast_end = slow;
      while(slow) {
          if(fast->val != slow->val) return false;
          fast = fast->next;
          slow = slow->next;
      }
      return true;
        
    }
    // reverse from head to the end
    ListNode* reverse(ListNode* head) {
      // insert head->next to temp->next
      // 0 3 2 1
      // 0 2 3 1
      // 0 1 2 3
      ListNode* temp = new ListNode(0);
      temp->next = head;
      while(head->next) {
        auto ins = head->next;
        head->next = ins->next;
        ins->next = temp->next;
        temp->next = ins;
      }
      auto r_pt = temp->next;
      delete temp;
      return r_pt;
    }
};
