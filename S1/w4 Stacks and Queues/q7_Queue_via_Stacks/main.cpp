// https://leetcode.com/problems/odd-even-jump/

class Solution {
public:
    std::unordered_map<int, bool> oddMap;
    std::unordered_map<int, bool> evenMap;    
    int oddEvenJumps(vector<int>& A) {

        int num_good = 0;
        for(int i=0; i<A.size()-1; i++) {
            int cnt = 1;
            if(iterateJumps(A, i, cnt)) num_good++;
        }
        
        return num_good+1;
    }
    bool iterateJumps(vector<int>& A, int index, int &cnt) {
        if(cnt%2==0) {
            // std::cout<<"[even] index "<<index<<std::endl;
            auto fnd = evenMap.find(index);
            if(fnd != evenMap.end()) {
                return evenMap[index]; 
            }
            else {
                // go even jump
                int max_idx = index;
                int max_val = -1;
                bool first = false;
                
                // find max val index that satisfiy the condition(A[j]>=A[i])
                for(int i=index+1; i<A.size(); i++) {
                    if(A[index]>=A[i]) {
                        if(!first){
                            if(A[i]>=max_val) {
                                max_val = A[i];
                                max_idx = i;
                                first = true;
                            }
                        }
                        else {
                            if(A[i]>max_val) {
                                max_val = A[i];
                                max_idx = i;
                            }
                        }
                    }
                }
                // success to find --> proceed
                if(first) {
                    if(max_idx == A.size()-1) {
                        evenMap[index] = true;
                        return true;
                    }
                    else {
                        bool check = iterateJumps(A, max_idx, ++cnt);
                        if(check) evenMap[index] = true;
                        else evenMap[index] = false;
                        return check;
                    }
                }
                else {
                    evenMap[index] = false;
                    return false;
                }   
            }
        }
        else {
            auto fnd = oddMap.find(index);
            if(fnd != oddMap.end()) {
                return oddMap[index];
          } else {
            return iterateJumps(A, max_idx, ++cnt);
          }
        } else {
          evenMap[index] = false;
          return false;
        }
      }
    } else {
      auto fnd = oddMap.find(index);
      if (fnd != oddMap.end()) {
        return oddMap[index];
      } else {
        // go odd jump
        int min_idx = index;
        int min_val = 1000000;
        bool first = false;

        // find min val index that satisfiy the condition(A[i]>=A[j])
        for (int i = index + 1; i < A.size(); i++) {
          if (A[index] <= A[i]) {
            if (!first) {
              if (A[i] <= min_val) {
                min_val = A[i];
                min_idx = i;
                first = true;
              }
            } else {
              if (A[i] < min_val) {
                min_val = A[i];
                min_idx = i;
              }
            }
          }
        }
        // success to find --> proceed
        if (first) {
          if (min_idx == A.size() - 1) {
            oddMap[index] = true;
            return true;
          } else {
            return iterateJumps(A, min_idx, ++cnt);
          }
        }
        // failed to find --> save as fail
        else {
          oddMap[index] = false;
          return false;
        }
      }
    }
  }
};
