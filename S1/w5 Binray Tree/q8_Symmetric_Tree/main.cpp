//https://leetcode.com/problems/symmetric-tree/
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
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {    
      if(root==nullptr) return true;
      else if(root->left ==nullptr && root->right == nullptr) return true;
      else{
        if(root->left!=nullptr && root->right!=nullptr){
          TreeNode* left = root->left;
          TreeNode* right = root->right;
          return checkSym(left, right);
        }
        else return false;
      }
    }
  // left, right seeks same order
    bool checkSym(TreeNode* n_left, TreeNode* n_right){
      if(n_left!=nullptr && n_right!=nullptr)
      if(n_left==nullptr && n_right==nullptr) return true;
      
      //non-sym
      else if(n_left==nullptr || n_right==nullptr) return false;
      
      if (n_left->val == n_right->val &&
          checkSym(n_left->right, n_right->left) &&
          checkSym(n_left->left, n_right->right)) return true;
      else return false;
    }
};
