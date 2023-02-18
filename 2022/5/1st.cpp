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
  vector<string> __backpacks;
  int priority = 0;

  if(input.is_open()){
  
    string _backpack_;  
    while (input.good()) {
      getline(input,_backpack_);
      __backpacks.push_back(_backpack_);
    }

    for(auto i = __backpacks.begin(); i  != __backpacks.end(); i++){
        cout << *i << endl;
    }
  }
    return 0;
} 