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
  string one_elf;
  vector<string> all_elfs;
  vector<int> calories;

  if(input.is_open()){
      while(input.good()){
        getline(input, one_elf);
        all_elfs.push_back(one_elf);
    }
  }
    input.close();
    for(auto i = all_elfs.begin(); i != all_elfs.end(); i++){
        cout << *i;
    }
    return 0;
}   