#include<iostream>
#include<string>
#include<cmath>
/*
   given two string, determine the required number of correction(insert, delete, change)
   is within 1.
   example
   pale, ple --> true
   pales, pale --> true
   pale, bale --> true
   pale, bake --> false

   balk palk

   when the two strings have same length
   */

bool isPartofString(const std::string& longer, const std::string& shorter){

  bool isContain = false;
  // exceptional handling
  if( longer.size()==1 && shorter.size() == 0 ) { 
	return true;
  } else {
	bool isContain = false;
	for( int i=0; i<longer.size(); i++ ) {
	  if( longer[i] == shorter[0] ){	
		if( shorter == longer.substr(i, shorter.size()) ) return true;
		else return false;
	  }
	}
	return isContain;
  }
}

bool stringCheck(const std::string& w1, const std::string& w2) {

  int diff_length = std::abs( w1.size() - w2.size() );
  if( diff_length > 1 ) { 
	return false;
  } else if( diff_length == 1) {  // check longer letter contains shorter
	if( w1.size() > w2.size() && isPartofString(w1, w2) ) return true;
	else if( w2.size() > w1.size() && isPartofString(w2, w1) ) return true;
  } else {  // identical length --> by iterating
	int diff_count = 0;
	for( int i = 0; i < w1.size() ; i++ ){
	  if(w1[i]!=w2[i]) {
		diff_count++;
		if(diff_count>=2) return false;
	  }
	}
	return true;
  }
}

int main() {
  std::string w1, w2;

  std::getline(std::cin, w1);
  // std::cin.ignore();
  std::getline(std::cin, w2);

  std::cout<<w1<<"  "<<w2<<std::endl;
  // contain first and second
  std::cout<<stringCheck(w1, w2)<<std::endl;

  return 0;
}

