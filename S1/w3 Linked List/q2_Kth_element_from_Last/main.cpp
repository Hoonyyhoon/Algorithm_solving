/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Time Complexity O(N)
// Memory Complexity O(1)
class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* init = new ListNode(0);
    init->next = head;
    ListNode* ref = head;
    ListNode* p_remove = init;
    ListNode* remove = head;
    int cnt = 0;

    // exceptional handling
    if (ref->next == nullptr && n == 1) return nullptr;

    while (ref != nullptr) {
      if (cnt > n - 1) {
        remove = remove->next;
        p_remove = p_remove->next;
      }
      cnt++;
      ref = ref->next;
    }

    // remove
    p_remove->next = remove->next;
    delete remove;

    // return
    return init->next;
  }
};
