// https://leetcode.com/problems/validate-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Time: O(N)
// Mem: O(N)

#include<queue>


class Solution {
public:
  void inOrderTraversal(TreeNode* node, std::queue<int>& queue_){
    if(node != nullptr){
      inOrderTraversal(node->left, queue_);
      queue_.push(node->val);
      inOrderTraversal(node->right, queue_);
    }
  }
  
    bool isValidBST(TreeNode* root) {
      if(root == nullptr) return true;
      
      std::queue<int> val_qu;
      inOrderTraversal(root, val_qu);
      int last_val = val_qu.front();
      val_qu.pop();
      while(!val_qu.empty()){
        if(last_val>=val_qu.front()) return false;
        last_val = val_qu.front();
        val_qu.pop();
      }
      
      return true;
    }
};
