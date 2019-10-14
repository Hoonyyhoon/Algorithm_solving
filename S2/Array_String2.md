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