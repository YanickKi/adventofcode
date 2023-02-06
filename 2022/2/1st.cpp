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
  vector<int> __elf, __mine;

  if(input.is_open()){
  
    char _first_, _second_;  
    while (input >> _first_ >> _second_) {
      __elf.push_back(int(_first_) - 65);
      __mine.push_back(int(_second_) - 88);
    }

  }

  int score = 0, dif;
  for(int i = 0; i < __elf.size(); i++){
    dif = __elf[i] - __mine[i];
    if(dif == -1 or dif == 2){
      score += 6;
    }
    else if(dif == 0){
      score += 3;
    }
    score += __mine[i] + 1;
  }

  cout << "My total score of the first half is: " << score << "\n";

//part 2 
  vector<int> __outcome = __mine; //just a renaming for readability
  score = 0;
  for(int i = 0; i < __elf.size(); i++){
      if(__outcome[i] == 0){
        if(__elf[i] == 0){
          score += 3;
        }
        else {
          score += __elf[i];
        }
      }
      if(__outcome[i] == 2){
        if(__elf[i] == 2){
          score += 1;
        }
        else {
          score += __elf[i] + 2;
        }
      }
      if(__outcome[i] == 1){
        score += __elf[i] + 1;
      }
      score += __outcome[i]*3;
    }

  cout << "My total score of the second half is: " << score << "\n";
    return 0;
}   