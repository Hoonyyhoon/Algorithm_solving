# Linked List

## Q1. Swap Nodes in Pairs([Link](https://leetcode.com/problems/swap-nodes-in-pairs/)) (:o:)

- Time: O(N)
- Space: O(1)
- Note <br/> 
```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      ListNode* zero = new ListNode(0);
      zero->next = head;
      ListNode* pt0 = zero;
      ListNode* pt1 = head;
      
      while(pt1 && pt1->next) {
        ListNode* post = pt1->next;
        pt0->next = pt1->next;
        pt1->next = post->next;
        post->next = pt1;
        pt0 = pt1;
        pt1 = pt0->next;
      }
      return zero->next;
    }
};
```
