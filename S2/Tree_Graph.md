# Tree & Graph

## Q1. Recover Binary Search Tree([Link](https://leetcode.com/problems/recover-binary-search-tree/)) (:o:)

- Time: O(N)
- Space: O(1)
- Note <br/> 
```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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

## Q2. Diameter of Binary Tree([Link](https://leetcode.com/problems/diameter-of-binary-tree/)) (:o:)

- Time: O(N)
- Space: O(N)
- Note <br/> 

```cpp
class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int maxDiam = 0;
    getHeight(root, maxDiam);
    return maxDiam;
  }

  int getHeight(TreeNode* node, int& maxDiameter) {
    if (!node) return 0;
    int left = 0;
    int right = 0;
    // height left
    if (node->left) left = getHeight(node->left, maxDiameter);
    // height right
    if (node->right) right = getHeight(node->right, maxDiameter);
    maxDiameter = std::max(maxDiameter, left + right);
    return std::max(left + 1, right + 1);
  }
};
```

## Q3. Keys and Rooms([Link](https://leetcode.com/problems/keys-and-rooms/)) (:o:)

- Time: O(N+K), N: num of rooms, K: num of keys
- Space: O(N)
- Note <br/> 

```cpp
// 1
class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    std::unordered_set<int> checked_room;
    openRoom(rooms, 0, checked_room);
    if (checked_room.size() == rooms.size()) return true;
    return false;
  }
  void openRoom(const vector<vector<int>>& rooms, int room_num,
                std::unordered_set<int>& checked_room) {
    if (checked_room.find(room_num) != checked_room.end()) return;
    checked_room.insert(room_num);
    for (int k = 0; k < rooms[room_num].size(); k++) {
      openRoom(rooms, rooms[room_num][k], checked_room);
    }
  }
};
// 2
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      std::unordered_set<int> checked_room;
      std::stack<int> s_rooms;
      s_rooms.push(0);
      while(!s_rooms.empty()) {
        int r_num = s_rooms.top();
        s_rooms.pop();
        if(checked_room.find(r_num) != checked_room.end()) continue;
        checked_room.insert(r_num);
        for(int key = 0; key < rooms[r_num].size(); key++) {
          s_rooms.push(rooms[r_num][key]);
        }
      }
      if(checked_room.size() == rooms.size()) return true;
      return false;
    }
};
```
