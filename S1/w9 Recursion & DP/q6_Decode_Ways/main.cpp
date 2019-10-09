// https://leetcode.com/problems/decode-ways/
// O(N)
// O(1)

#include <queue>
class Solution {
 public:
  int numDecodings(string s) {
    // max num: 26
    /* subproblem --> stair + condition?
    // two single digits? or one single digit
    // DP[i-1] + DP[i-2]
    if last two string is smaller than 27 && both aren't 0 --> DP[i-1] + DP[i-2]
    else( bigger than 26 ) --> valid single digit only : DP[i-1]
    DP[i] = DP[i-1]+ DP[i-2]
    */
    // EXCEPTIONS: TOO DIRTY
    // 1) starting
    // 1. 0 --> impossible
    // 2. 01, 02, ..09 --> impossible
    // 2) while
    // 1. 00 --> return 0;
    // 2. 10, 20 --> only one way DP[i-2]
    // 3. 30, 40, 50, ... 90 --> return 0;
    std::queue<int> DP;
    DP.push(1);
    // exception
    if (s.size() == 1) {
      if (s.substr(0, 1) == "0")
        return 0;
      else
        return 1;
    }
    // determine DP[1]
    bool f_z, b_z;
    int val = getValwithZeros(s.substr(0, 2), f_z, b_z);

    if (f_z || (val > 26 && b_z))
      return 0;
    else if (val <= 26 && (!f_z && !b_z))
      DP.push(2);
    else
      DP.push(1);

    for (int i = 2; i < s.size(); i++) {
      bool f_z, b_z;
      int val = getValwithZeros(s.substr(i - 1, 2), f_z, b_z);

      if (f_z && b_z || (val > 26 && b_z))
        return 0;  // impossible
      else if (val <= 26 && (!f_z && !b_z)) {
        // two digit or single digit
        int val = DP.front() + DP.back();
        DP.pop();
        DP.push(val);
      } else if (val <= 26 && b_z) {
        // only two digit
        DP.push(DP.front());
        DP.pop();
      } else {
        // single digit
        DP.push(DP.back());
        DP.pop();
      }
    }
    return DP.back();
  }

  int getValwithZeros(std::string s, bool& front, bool& back) {
    front = std::stoi(s.substr(0, 1)) == 0 ? true : false;
    back = std::stoi(s.substr(1, 1)) == 0 ? true : false;
    return std::stoi(s);
  }
};
