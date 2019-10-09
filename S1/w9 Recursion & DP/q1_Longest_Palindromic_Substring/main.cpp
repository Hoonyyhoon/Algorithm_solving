// https://leetcode.com/problems/longest-palindromic-substring/
// Time: O(N^2)
// Memory: O(1)

class Solution {
 public:
  string longestPalindrome(string s) {
    // extending from origin
    int maxLength = 1;
    int start = 0;

    for (int i = 0; i < s.size(); i++) {
      int case1 = extendString(s, i, i);
      int case2 = extendString(s, i, i + 1);
      if (2 * case1 + 1 > maxLength) {
        maxLength = 2 * case1 + 1;
        start = i - case1;
      }
      if (2 * (case2 + 1) > maxLength) {
        maxLength = 2 * (case2 + 1);
        start = i - case2;
      }
    }
    return s.substr(start, maxLength);
  }

  int extendString(string& s, int left, int right) {
    int length = -1;
    while (left >= 0 && right < s.size()) {
      if (s[left--] == s[right++])
        length++;
      else
        break;
    }
    return length;
  }
};
