// https://leetcode.com/problems/word-break/
// Time O(N)
// Memory O(N)

class Solution {
 public:
  bool wordBreak(string s, std::vector<string> &wordDict) {
    /*
    subproblem
    DP[i]: word found till i? true : false
    // go forward
    for i in range(n):
    // go backward
      for j in range(i-1, max(strlen, -1),-1):
      // from true
        if DP[j]:
          // check validity from wordDict
          if(checkStr) DP[i] = true;
    */
    // initialize
    std::vector<bool> DP(s.size() + 1, false);
    DP[0] = true;
    int max_len = 0;
    for (auto &iter : wordDict) max_len = std::max((int)iter.size(), max_len);

    // iterate
    // go forward
    for (int i = 1; i <= s.size(); i++) {
      // go backward to check matching word exist
      for (int j = i - 1; j >= std::max(i - max_len, 0); j--) {
        // find last valid
        if (DP[j]) {
          // check validity
          int len = i - j;
          if (checkWord(s.substr(j, len), wordDict)) {
            DP[i] = true;
            break;
          }
        }
      }
    }
    return DP.back();
  }

  bool checkWord(std::string s, std::vector<std::string> &wordDict) {
    for (auto &iter : wordDict)
      if (s == iter) return true;
    return false;
  }
};
