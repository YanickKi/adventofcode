#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main () {
  ifstream input; 
  input.open ("input");
  string _frist_, _second_;
  vector<string> __First, __Second;

  if(input.is_open()){
   //   while(input.good()){
   //     getline(input, one_elf);
   //     all_elfs.push_back(one_elf);
   // }
  
  while (input >> _frist_ >> _second_) {
    __First.push_back(_frist_);
    __Second.push_back(_second_);
  }
  }
    input.close();
    for(auto i = all_elfs.begin(); i != all_elfs.end(); i++){
        cout << *i;
    }
    return 0;
}   