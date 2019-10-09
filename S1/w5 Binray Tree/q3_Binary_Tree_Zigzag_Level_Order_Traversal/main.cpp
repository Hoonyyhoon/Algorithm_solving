// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
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
// Memory: O(N)

class Solution {
 public:
  int getHeight(TreeNode* node) {
    if (node == nullptr) {
      return 0;
    } else {
      int l_h = getHeight(node->left);
      int r_h = getHeight(node->right);
      if (l_h < r_h)
        return r_h + 1;
      else
        return l_h + 1;
    }
  }
  
  bool insertInnerVector(TreeNode* root, 
                         int level,  
                         bool reverse,
                        std::vector<int>& sub_zigzag) {
    
   if(root == nullptr) {return false;}
    if(level==1){
      sub_zigzag.push_back(root->val);
    }
    else if (level>1) {
      if(reverse){
        insertInnerVector(root->right, level-1, reverse, sub_zigzag);
        insertInnerVector(root->left, level-1, reverse, sub_zigzag);
      }
      else {
        insertInnerVector(root->left, level-1, reverse, sub_zigzag);
        insertInnerVector(root->right, level-1, reverse, sub_zigzag);
      }
    }
    
    return true;
  }  
  
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    std::vector<std::vector<int>> zigzag;
    std::vector<int> sub_zigzag;
    int h = getHeight(root);
    zigzag.reserve(h);
    
    bool reverse = false;
    for(int i=1; i<=h; i++) {
      if(i%2==0) reverse = true;
      else reverse = false;
      
      if(insertInnerVector(root, i, reverse, sub_zigzag)){
        zigzag.push_back(sub_zigzag);
        sub_zigzag.clear();
        sub_zigzag.reserve(pow(2,i));
      }  
    }
    return zigzag;
  }
};
