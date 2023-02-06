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

  cout << "Calories of the first elf: " << *max_element(begin(calories), end(calories));

// part 2
vector<int> first_three;

  for(int i = 0; i<3; i++){
    first_three.push_back(*max_element(begin(calories), end(calories)));
    remove(calories.begin(), calories.end(), *max_element(begin(calories), end(calories)));
  }
  cout << "Calories of the first three elfs: " << accumulate(first_three.begin(), first_three.end(), 0);
  return 0;
}