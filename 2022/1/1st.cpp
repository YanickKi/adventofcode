#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
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
    input.close();
  }
    int sum = 0;
    for(int i = 0; i < all_elfs.size(); i++){
      if(all_elfs[i] != ""){
        sum += stoi(all_elfs[i]); 
      
        if(all_elfs[i+1] == ""){
          calories.push_back(sum);
          sum = 0;
        }
      }
    }

  cout << *std::max_element(begin(calories), end(calories));

// part 2
  return 0;
}