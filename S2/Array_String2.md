# Array and String 1

## Q1. Letter Combinations of a Phone Number([Link](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)) (:o:)

- Time: O(3^N)(ignoring 4 letter case)
- Space: O(3^N)
- Note <br/> Condition for digit is already given(from 2-9)
```cpp
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits.size() == 0) return res;

    string str;
    res.reserve(pow(4, digits.size()));
    expandLetter(res, str, digits);
    return res;
  }
  void expandLetter(vector<string>& res, string str, string& digits) {
    int index = str.size();
    if (index == digits.size()) {
      res.push_back(str);
    } else {
      int num = digits[index] - 48 - 2;
      for (auto& iter : number_table[num])
        expandLetter(res, str + iter, digits);
    }
  }

 private:
  vector<string> number_table = {"abc", "def",  "ghi", "jkl",
                                 "mno", "pqrs", "tuv", "wxyz"};
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
  int firstMissingPositive(vector<int>& nums) {
    int last_nonneg = nums.size() - 1;
    for (int i = 0; (i < nums.size()) && (i < last_nonneg); i++)
      if (nums[i] <= 0) std::swap(nums[i], nums[last_nonneg--]);

    int N = last_nonneg + 1;
    for (int i = 0; i < N; i++) {
      int val = nums[i];
      while (val > 0 && val <= N && val != nums[val - 1]) {
        std::swap(nums[val - 1], nums[i]);
        val = nums[i];
      }
    }

    for (int i = 0; i < N; i++)
      if (nums[i] != i + 1) return i + 1;
    return N + 1;
  }
};
```
- Check <br/> How will you catch the hint condition for the solution?(answer will be ranging from [1, # of positive number in array+1]) 

## Q2. Spiral Matrix([Link](https://leetcode.com/problems/spiral-matrix/)) (:o:)

- Time: O(N*M)
- Space: O(N*M)
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
