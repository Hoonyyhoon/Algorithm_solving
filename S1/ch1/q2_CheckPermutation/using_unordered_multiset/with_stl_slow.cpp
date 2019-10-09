#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;

class Solution{
public:
bool checkInclusion(string s1, string s2) {
//make set for reference
    std::unordered_multiset<char> reference;
    std::unordered_multiset<char> compare;
    reference.reserve(s1.size());
    compare.reserve(s1.size());

    for(const auto &it: s1)
        reference.insert(it);
    int length = s1.size();
    if(s1.size()>s2.size()) return false;
    for(auto &itt: reference) std::cout<<itt;    
    std::cout<<std::endl;
    //initialize
    for(int i=0; i<length; i++){
        compare.insert(s2[i]);        
        if(reference == compare) return true;        
    }
    //debug    
    for(int i=length; i<s2.size(); i++) {    
        // erase only one time
        auto find = compare.begin();
        while(find != compare.end()){
            if(*find == s2[i-length]){
                compare.erase(find);
                break;
            }
            find++;
        }        
        compare.insert(s2[i]);
        if(reference == compare) return true;            
    }
    return false;
}

};
