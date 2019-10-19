# Array and String 2

## Q1. Letter Combinations of a Phone Number([Link](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)) (:o:)

- Time: O(3^N)(ignoring 4 letter case)
- Space: O(3^N)
- Note <br/> Condition for digit is already given(from 2-9)
```cpp
const vector<string> numtostr = {"abc", "def",  "ghi", "jkl",
                                 "mno", "pqrs", "tuv", "wxyz"};
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string temp;
    if (digits.empty()) return ans;
    ans.reserve(pow(4, digits.size()));
    expandLetter(digits, ans, temp);
    return ans;
  }
  void expandLetter(const string& digits, vector<string>& ans, string cur_str) {
    int index = cur_str.size();
    if (digits.size() <= index) {
      ans.push_back(cur_str);
      return;
    } else {
      for (auto& iter : numtostr[digits[index] - '0' - 2])
        expandLetter(digits, ans, cur_str + iter);
    }
  }
};
```
- Check <br/> 1) Try to solve using queue <br/> 2) [Space-complexity](https://cs.stackexchange.com/questions/83574/does-space-complexity-analysis-usually-include-output-space)

## Q2. First Missing Positive([Link](https://leetcode.com/problems/first-missing-positive/)) (:x:)

- Time: O(N)
- Space: O(1)
- Note <br/> Run within O(N) with constant space(O(1))
```cpp
class Solution {
 public:
  int firstMissingPositive(vector<int> &nums) {
    int N = 0;
    for (auto &iter : nums)
      if (iter > 0) N++;
    for (int i = 0; i < nums.size(); i++) {
      int v = nums[i];
      while (v >= 1 && v <= N && nums[v - 1] != v) {
        std::swap(nums[i], nums[v - 1]);
        v = nums[i];
      }
    }
    int ans = 1;
    for (auto &iter : nums) {
      if (iter == ans) ans++;
    }
    if (ans == N)
      return ans++;
    else
      return ans;
  }
};
```
- Check <br/> How will you catch the hint condition for the solution?(answer will be ranging from [1, # of positive number in array+1]) 

## Q3. Spiral Matrix([Link](https://leetcode.com/problems/spiral-matrix/)) (:o:)

- Time: O(N*M)
- Space: O(1) // ignoring return vector
- Note <br/>
```cpp
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;

    if (matrix.empty() || matrix.front().empty()) return res;

    // right down left up
    int left = -1;  // for concise
    int up = 0;
    int down = matrix.size();
    int right = matrix.front().size();
    int total_size = (down--) * (right--);
    res.reserve(total_size);
    while (left <= right && up <= down) {
      // go right
      for (int h = ++left; h <= right; h++) res.push_back(matrix[up][h]);
      // touch right, up
      if (res.size() == total_size) break;
      // go down
      for (int v = ++up; v <= down; v++) res.push_back(matrix[v][right]);
      // touch right, bottom
      if (res.size() == total_size) break;
      // go left
      for (int h = --right; h >= left; h--) res.push_back(matrix[down][h]);
      // touch left, down
      if (res.size() == total_size) break;
      // go up
      for (int v = --down; v >= up; v--) res.push_back(matrix[v][left]);
      // touch left, up
      if (res.size() == total_size) break;
    }
    return res;
  }
};
```
- Check <br/> Any way to reduce if condition?

## Q4. Word Search([Link](https://leetcode.com/problems/word-search/)) (:heavy_check_mark:)
- Time: O(H*W*4^(S-1)) // H: height, W: width, S: length of word
- Space: O(S)
- Note <br/>
```cpp
std::pair<int, int> operator+(const std::pair<int, int>& a,
                              const std::pair<int, int>& b) {
  return std::pair<int, int>(a.first + b.first, a.second + b.second);
}

const std::vector<std::pair<int, int>> dir{
    std::pair<int, int>(0, 1), std::pair<int, int>(1, 0),
    std::pair<int, int>(0, -1), std::pair<int, int>(-1, 0)};

class Solution {
 public:
  bool exist(vector<vector<char>>& board, string word) {
    if (board.empty() || board.front().empty()) return false;
    if (word.empty()) return true;
    if (board.front().size() * board.size() < word.size()) return false;

    bool sol = false;
    for (int h = 0; h < board.size(); h++) {
      for (int w = 0; w < board.front().size(); w++) {
        std::pair<int, int> pos(h, w);
        if (RecursiveSearch(board, word, pos, 0)) return true;
      }
    }
    return false;
  }

  bool RecursiveSearch(vector<vector<char>>& board, const string& word,
                       const std::pair<int, int>& pos, const int str_idx) {
    int h = pos.first;
    int w = pos.second;
    if (h < 0 || h > board.size() - 1 || w < 0 ||
        w > board.front().size() - 1 || board[h][w] == '0')
      return false;
    if (board[h][w] == word[str_idx]) {
      if (str_idx == word.size() - 1) {
        return true;
      }
      char temp = board[h][w];
      board[h][w] = '0';
      bool sol = false;
      for (auto& it : dir)
        sol = sol || RecursiveSearch(board, word, pos + it, str_idx + 1);
      board[h][w] = temp;
      return sol;
    } else
      return false;
  }
};
```
- Check <br/> 1) How will you come up with idea "mark and recover"?
<br/> 2) Space complexity for recursion function call([Link](https://stackoverflow.com/questions/43298938/space-complexity-of-recursive-function))

## Q5 Move Zeroes([Link](https://leetcode.com/problems/move-zeroes/)) (:o:)
- Time: O(N)
- Space: O(1)
- Note <br/>
```cpp
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int rm_nz = 0;  // right-most non-zero
    int lm_z = 0;   // left-most zero
    for (int i = 0; i < nums.size(); i++) {
      if (nums[lm_z] == 0) {
        if (rm_nz < lm_z) rm_nz = lm_z;  // rm_nz cannot be smaller than lm_z
        while (nums[rm_nz++] == 0) {     // find right-most non zero
          if (rm_nz > nums.size() - 1) {  // break when non zero lies onto the end
            rm_nz = nums.size() - 1;
            break;
          }
        }
        std::swap(nums[lm_z], nums[rm_nz]);
        i = rm_nz;  // update i to right-most nonzero since we dont need to care index that has 0
      }
      lm_z++;  // update left-most zero
    }
  }
  void moveZeroes2(vector<int>& nums) {
    int last_non_zero = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) std::swap(nums[last_non_zero++], nums[i]);
    }
  }
};
```
- Check <br/> 1) How will you end up thinking "reversely"?
