// https://leetcode.com/problems/intersection-of-two-linked-lists/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      // find equivalent position from the very back
      int sizeA = getSize(headA);
      int sizeB = getSize(headB);
      
      auto iterA = headA;
      auto iterB = headB;
      int compen = abs(sizeA-sizeB);
      
      // go forward for sizeA-sizeB step
      if(sizeA>sizeB) while(compen-->0) iterA = iterA->next;
      else if(sizeB>sizeA) while(compen-->0) iterB = iterB->next;
      
      while(iterA!=iterB) {
        iterA = iterA->next;
        iterB = iterB->next;
      }
      return iterA;
    }
  
    int getSize(ListNode* list) {
      int size = 0;
      if(!list) return 0;
      while(list) {
        list = list->next;
        size++;
      }
      return size;
    }
};
