// https://leetcode.com/problems/binary-tree-right-side-view/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Time O(N)
// Memory O(logN)
class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    std::vector<int> v_val;
    DepthPreorder(root, 1, v_val);
    return v_val;
  }

  void DepthPreorder(TreeNode* node, int height, std::vector<int>& v_val) {
    if (!node) return;
    if (v_val.size() < height) v_val.push_back(node->val);
    DepthPreorder(node->right, height + 1, v_val);
    DepthPreorder(node->left, height + 1, v_val);
  }
};
