#include <bits/stdc++.h>
#include <algorithm>
#include <string>
using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {

   unsigned int *arr = new unsigned int[26]();

   // convert lowercase
   std::transform(s.begin(),
   s.end(),
   s.begin(),
   [](unsigned char in_) {return std::tolower(in_);});

   // remove space
   s.erase(std::remove_if(s.begin(), s.end(),
                       [] (unsigned char in_){return std::isspace(in_);}),
           s.end());

   unsigned int total_len = s.size();

   //store it to the array
   for(auto& iter: s) {
       int index = (int)iter-int('a');
       *(arr+index) +=1;
   }

   //even → symmetry
   bool isPalin = true;
   if(total_len%2==0) {
       for(int i=0; i<26;i++) {
           if(arr[i]%2==1) isPalin = false;
       }
   } else {
       int odd_cnt = 0;
       for(int i=0; i<26;i++) {
       if(arr[i]%2==1) {
           odd_cnt++;
           if(odd_cnt>1) isPalin = false;
           }
       }
   }
   if(isPalin) return "YES";
   else return "NO";
}

int main() {
   ofstream fout(getenv("OUTPUT_PATH"));

   string s;
   getline(cin, s);
   string result = gameOfThrones(s);
   fout << result << "\n";
   fout.close();

   return 0;
}

