# Week 1: Array and String

## Q1. Reorder Data in LogFiles([Link](https://leetcode.com/problems/reorder-data-in-log-files/)) (:heavy_check_mark:)

- Time: O(NlogN)
- Space: O(N)
- Note <br/>
```cpp
class Solution {
 public:
  struct logs_cmp {
    inline bool Isdigitlog(const string& s, int& next_idx_space) {
      int i = s.find(' ');
      next_idx_space = i + 1;
      if (s[i + 1] >= 97)
        return false;
      else
        return true;
    }

    inline bool operator()(const string& a, const string& b) {
      // true when a goes front
      // a, b_idx: pos of non identifier
      int a_idx, b_idx;
      bool a_digit = Isdigitlog(a, a_idx);
      bool b_digit = Isdigitlog(b, b_idx);
      // a: digit-log b: digit-log : false
      //              b: letter-log : false
      // a: letter-log b: digit-log : true
      //               b: letter-log if (non identifier a == non identifier b)
      //               compare identifier
      //                             else after_id_a < after_id_b;

      if (a_digit) {
        return false;
      } else {
        if (b_digit)
          return true;
        else {
          // non identifier
          auto comp_a = a.substr(a_idx);
          auto comp_b = b.substr(b_idx);
          if (comp_a == comp_b) {
            auto comp_id_a = a.substr(0, a_idx);
            auto comp_id_b = b.substr(0, b_idx);
            return comp_id_a < comp_id_b;
          } else {
            return comp_a < comp_b;
          }
        }
      }
    }
  };

  vector<string> reorderLogFiles(vector<string>& logs) {
    std::stable_sort(logs.begin(), logs.end(), logs_cmp());
    return logs;
  }
};
```
- Check <br/> 1) std::stable_sort vs std::sort? <br/> 2) String compares with relational operators([Link](https://stackoverflow.com/questions/34540790/string-comparisons-with-relational-operators-differing-lengths))

## Q2. Product of Array Except Self([Link](https://leetcode.com/problems/product-of-array-except-self/)) (:o:)

- Time: O(N)
- Space: O(1)
- Note <br/> Don't use divide operator
```cpp
class Solution {
 public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size();
    std::vector<int> ret(size, 1);
    int f = nums.front();
    int b = nums.back();

    for (int i = 1; i < size; i++) {
      int j = size - 1 - i;
      ret[i] *= f;
      ret[j] *= b;
      f *= nums[i];
      b *= nums[j];
    }

    return ret;
  }
};
```
- Check <br/> 1) What do we change while iterating?
## Q3. Game of Life([Link](https://leetcode.com/problems/game-of-life/)) (:heavy_check_mark:)
- Time: O(MN)
- Space: O(1)
- Note <br/> What do we need to implement inplace?
```cpp
class Solution {
 public:
  void Nextstate(vector<vector<int>>& cur, int r, int c) {
    int current_state = 0;
    if (cur[r][c] >= 2) current_state = 1;
    int liv_cnt = 0; 

    for (int i = r - 1; i <= r + 1; i++) {
      if (i < 0)
        continue;
      else if (i > cur.size() - 1)
        break;
      for (int j = c - 1; j <= c + 1; j++) {
        if (j < 0)
          continue;
        else if (j > cur.front().size() - 1)
          break;
        if (cur[i][j] >= 2) liv_cnt++;
      }
    }

    if (current_state == 1) {
      liv_cnt--;
      if (liv_cnt < 2)
        cur[r][c] = 2;
      else if (liv_cnt <= 3)
        cur[r][c] = 3;
      else
        cur[r][c] = 2;
    } else {
      if (liv_cnt == 3)
        cur[r][c] = 1;
      else
        cur[r][c] = 0;
    }
  }

  void gameOfLife(vector<vector<int>>& board) {
    if (board.empty()) return;

    int m = board.size();          
    int n = board.front().size();

    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (board[r][c] == 1) board[r][c] = 3;
      }
    }

    for (int r = 0; r < m; r++) {
      if (r < 0)
        continue;
      else if (r > m - 1)
        break;
      for (int c = 0; c < n; c++) {
        if (c < 0)
          continue;
        else if (c > n - 1)
          break;
        Nextstate(board, r, c);
      }
    }

    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        board[r][c] %= 2;
      }
    }
  }
};
```
- Check <br/> 1) How do we change saving rules to express multiple states in order to realize inplace? <br/> 2) Don't forget the procedure! (**modify** -> calculate -> modify)

## Q4. Generate Parentheses([Link](https://leetcode.com/problems/generate-parentheses/)) (:heavy_check_mark:)
- Time: O(MN)
- Space: O(1)
- Note <br/>
```cpp
class Solution {
 public:
  void AddString(vector<string>& ret, 
                 string cur, int n,
                 int pos_used, int neg_used) {
    if (2 * n > cur.size()) {
      if (n > pos_used) AddString(ret, cur + '(', n, pos_used + 1, neg_used);
      if (pos_used > neg_used) AddString(ret, cur + ')', n, pos_used, neg_used + 1);
    } else {
      ret.push_back(cur);
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> ret;
    AddString(ret, "(", n, 1, 0);
    return ret;
  }
};
```
- Check <br/> 1) Come up with the idea recursive or DFS + how to implement it?
<br/> 2) How do you derive time complexity?
