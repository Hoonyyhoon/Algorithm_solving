// https://leetcode.com/problems/decode-string/
// Time: O(N)
// Space: O(N) 

class Solution {
public:
    string decodeString(string s) {
        int cur = 0;
        return Divide(s, cur);
    }
    
    string Divide(string& s, int& cur) {
        int multiply = 1;
        std::string sub_res;
        
        for( auto iter = s.begin()+cur ; iter != s.end() ; ++iter ) {
            if(std::isdigit(*iter)) {
                auto it_num = iter;
                int number = 1;
                while(std::isdigit(*(++it_num))) number++;
                std::string num_str = s.substr(cur, number);
                multiply = std::stoi(num_str);
                cur+=number;  // next to the last intger
                iter = s.begin()+cur-1;
            }
            else if(*iter=='[') {
                std::string div_str=Divide(s, ++cur);
                std::string mul_str;
                for(int i= multiply; i>0; i--) mul_str+=div_str;
                multiply =0;
                sub_res+=mul_str;
                iter = s.begin()+(cur++);
            }
            else if(*iter==']') break;
            else {
                sub_res+=*iter;
                cur++;
            }
        }      
        return sub_res;
    }
};
