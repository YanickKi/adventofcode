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
  vector<string> __elf;

  if(input.is_open()){
  
    string _first_;  
    while (input.good()) {
      __elf.push_back(_first_);
    }

  }
  char letters[54];
  for(int i = 0; i< 26; i++){
    letters[i] = 'A' + i;
    letters[i+26] = 'a' + i;  
  }
  for (int i = 0; i < 54; i++){
    cout << letters << " ";
  }
    return 0;
}