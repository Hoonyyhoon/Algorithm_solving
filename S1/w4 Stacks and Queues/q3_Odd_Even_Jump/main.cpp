// https://leetcode.com/problems/basic-calculator/
// Time O(N)
// Space O(N)

class Solution {
 public:
  int cnt = 0;

  int calculate(string s) {
    // exception: all string is integer
    bool isDigit = true;
    for (auto& iter : s) {
      if (!std::isdigit(iter)) {
        isDigit = false;
        break;
      }
    }
    if (isDigit) return std::stoi(s);

    // iterating, find first non integer, determine sign, iterating...

    bool nega = false;
    int cur = 0;
    int total_sum = BracketCal(s, cur, nega);
    return total_sum;
  }

  int BracketCal(std::string& s, int& cur, bool neg) {
    // iterating, find first non integer, determine sign, iterating...
    // when bracket is closed, remove that part of string
    //     std::cout<<"call timer "<<cnt++<<std::endl;

    int inner_neg = false;
    int sum = 0;
    for (auto iter = (s.begin() + cur); iter != s.end(); ++iter) {
      // std::cout<<"current iter "<<*iter<<" cur "<<cur<<" inner_neg?
      // "<<inner_neg<< " neg "<<neg<<std::endl;
      if (iter == s.end() || *iter == ')')
        break;
      else if (*iter == '(') {
        sum += BracketCal(s, ++cur, inner_neg);
        inner_neg = false;
        // newly update
        iter = s.begin() + cur;
      } else {
        if (std::isdigit(*iter)) {
          std::string::iterator int_st = iter;
          while (std::isdigit(*(++int_st))) cur++;
          std::string int_val(iter, int_st);
          int value = std::stoi(int_val);
          if (inner_neg)
            sum -= value;
          else
            sum += value;
          inner_neg = false;
          // update iterator
          iter = int_st - 1;
        } else if (*iter == '+')
          inner_neg = false;
        else if (*iter == '-') {
          // toggle
          if (inner_neg)
            inner_neg = false;
          else
            inner_neg = true;
        }
      }
      cur++;
    }
    // std::cout<<"func end "<<sum<<std::endl;

    if (neg)
      return -sum;
    else
      return sum;
  }
};
