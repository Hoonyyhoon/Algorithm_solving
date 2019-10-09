class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      if(s1.size()>s2.size()) return false;
        //with array
        int *ref_bin = new int[26];
        for(auto &it: s1) {
            int val = (int)it%97;
            *(ref_bin+val)+=1;
        }
        
        int *find_bin = new int[26];
        int s1_len = s1.size();
        for(int i=0; i<s1_len;i++){
            int val = (int)s2[i] % 97;
            *(find_bin+val)+=1;
        }
        if(this->checkEquivalent(ref_bin, find_bin)) return true;
        
        int s2_len = s2.size();
        for(int i=s1_len;i<s2_len; i++){
            int reduce_val = (int)s2[i-s1_len]%97;
            *(find_bin+reduce_val)-=1;
            int val = (int)s2[i] % 97;
            *(find_bin+val)+=1;
            if(this->checkEquivalent(ref_bin, find_bin)) return true;
        }
        return false;
    }
    
    bool checkEquivalent( int *arr1, int *arr2 ){
        for(int i=0; i<26; i++) if(arr1[i]!=arr2[i]) return false;
        return true;
    }
};
