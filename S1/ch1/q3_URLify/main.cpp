// https://practice.geeksforgeeks.org/problems/urlify-a-given-string/0
#include <iostream>
#include <string>
#include <vector>

// replacing space
int main() {
  // code here
  int num_cases = 0;
  std::cin>>num_cases;
  std::vector<std::string> output;
    
  output.reserve(num_cases);
  std::string replace = "%20";
    
  while(num_cases>0){
    int size;
    std::string result;
    std::string input;
    
    std::cin.ignore();
    std::getline(std::cin, input)
    std::cin>> size;
    for(auto &iter : input) {
      if(iter != ' ') result.insert(result.end(), iter);
      else result.insert(result.size(), replace);
    }
    output.push_back(result);
    num_cases--;
  }
    
  for(auto &iter: output) std::cout<<iter<<std::endl;
  
  return 0;
  }
