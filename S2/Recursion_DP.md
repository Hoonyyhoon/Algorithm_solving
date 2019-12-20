# Recursion & DP

## Q2. Recover Binary Search Tree([Link](https://leetcode.com/problems/recover-binary-search-tree/)) (:o:)

- Time: O(N)
- Space: O(1)
- Note <br/> 
```cpp
class Solution {
 public:
  void recoverTree(TreeNode* root) {
    if (!root) return;
    std::stack<TreeNode*> stk;
    stk.push(root);
    TreeNode* cur = root;
    TreeNode* prev = nullptr;
    TreeNode* wrong = nullptr;
    TreeNode* n_wrong = nullptr;

    while (cur->left) {
      stk.push(cur->left);
      cur = cur->left;
    }
    while (!stk.empty()) {
      cur = stk.top();
      if (!prev) prev = cur;
      // abnormal
      if (prev->val > cur->val) {
        if (!wrong) {
          wrong = prev;
          n_wrong = cur;
        } else {
          std::swap(wrong->val, cur->val);
          return;
        }
      }
      prev = cur;
      stk.pop();

      // if right, go right
      if (cur->right) {
        stk.push(cur->right);
        cur = cur->right;
        while (cur->left) {
          stk.push(cur->left);
          cur = cur->left;
        }
      }
    }
    std::swap(wrong->val, n_wrong->val);
  }
};
```
