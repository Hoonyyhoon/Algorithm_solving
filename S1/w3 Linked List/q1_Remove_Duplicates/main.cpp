//https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
// Time: O(N)
// Space: O(1)

class Solution {
public:
   ListNode* deleteDuplicates(ListNode* head) {
     
     // less than size 2
     if ( head == nullptr  || head->next == nullptr) return head;
    
     ListNode* init = new ListNode(0);  // prev_head to define prev ptr
     init->next = head;
     ListNode* prev = init;
     ListNode* ref = prev->next;
     
     while( ref->next != nullptr ) {
       ListNode* lookahead = ref->next;
       
       if( ref->val == lookahead->val ) { // find first non duplicates
         while ( ref->val == lookahead->val ) {
           delete ref;
           ref = lookahead;
           lookahead = lookahead->next;
           if( lookahead == nullptr ) break;
         }
         delete ref;
         prev->next = lookahead;
         ref = prev->next;
         if(ref == nullptr) break;
       } else {
         prev = prev->next;
         ref = prev->next;
       }
     }
     
     return init->next;
   }
};
