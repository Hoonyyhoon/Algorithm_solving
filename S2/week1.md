# Week 1

## Q1. Reorder Data in LogFiles([Link](https://leetcode.com/problems/reorder-data-in-log-files/)) (:heavy_check_mark:)

- Time: O(NlogN)
- Space: O(N)
- Note <br/> 1) std::stable_sort vs std::sort? <br/> 2) String compares with relational operators([Link](https://stackoverflow.com/questions/34540790/string-comparisons-with-relational-operators-differing-lengths))
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
