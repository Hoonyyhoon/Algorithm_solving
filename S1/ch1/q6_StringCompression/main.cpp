#include<string>
#include<iostream>
#include<vector>
std::string compressString(std::string &s) {

  char ref_letter=s[0];
  int cnt=0;
  std::vector<std::pair<int, char>> compress_info;
  compress_info.reserve(s.size());

  for(auto iter = s.begin(); iter!=s.end(); ++iter) {
	if(*iter!=ref_letter) {
	  std::pair<int, char> data(cnt, ref_letter);
	  compress_info.push_back(data);

	  //initialize
	  cnt = 1;
	  ref_letter = *iter;
	  if(iter==s.end()-1) {
		std::pair<int, char> data(cnt, ref_letter);
		compress_info.push_back(data);
	  }
	} else if(iter==s.end()-1) {
	  cnt++;
	  std::pair<int, char> data(cnt, ref_letter);
	  compress_info.push_back(data);
	} else {
	  cnt++;
	}
  }

  // gen compressed string
  std::string result;
  for(auto &iter: compress_info){
	result.push_back(iter.second);
	result.append(std::to_string(iter.first));
  }
  if(s.size()<result.size()) return s;
  else return result;
}

int main() {

  std::string test;
  std::getline(std::cin, test);
  std::cout<<compressString(test)<<std::endl;

  return 0;
}
