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

  } 

  input.close();
  int count[52] = {0};
  for (int elf = 0; elf < __backpacks.size(); elf++){
    for (int item = 0; item < __backpacks[elf].size()/2; item++){    //FIRST HALF OF THE RUCKSACK OF EACH ELF
      if(int(__backpacks[elf][item]) < 97){
        count[int(__backpacks[elf][item])- 65] = 1;
      }
      else{
        count[int(__backpacks[elf][item])- 97 + 26] = 1;
      }
    }

    for (int item = __backpacks[elf].size()/2; item < __backpacks[elf].size(); item++) {    //SECOND HALF OF THE RUCKSACK OF EACH ELF
      if(int(__backpacks[elf][item]) < 97 and count[int(__backpacks[elf][item])- 65] == 1){
        count[int(__backpacks[elf][item])- 65] = 2;
      }
      else if(int(__backpacks[elf][item]) >= 97 and count[int(__backpacks[elf][item])- 97 + 26] == 1){
        count[int(__backpacks[elf][item])- 97 + 26] = 2;
    
      }
    }

    for(int letter = 0; letter < 52; letter++){   //SUM UP PRIORITY FOR EACH ELF
      if(count[letter] == 2){
        if(letter < 26){
          priority += letter + 27;
        }
        else{
          priority += letter - 26 + 1;
        }
      }
    }
    for(int i = 0; i < 52; i++){
      count[i] = 0;
    } 
  }
  //cout << "Sum of priorities: " << priority << "\n";
  // part 2

  priority = 0;

  for (int elf = 0; elf < __backpacks.size(); elf++){ 
    for (int item = 0; item < __backpacks[elf].size(); item++){ 
      if(int(__backpacks[elf][item]) < 97){
        if((elf + 1) % 3 == 1){        
          count[int(__backpacks[elf][item])- 65] = 1;
        }
        if((elf + 1) % 3 == 2 and count[int(__backpacks[elf][item])- 65] == 1){        
          count[int(__backpacks[elf][item])- 65] = 2;
        }
        if((elf + 1) % 3 == 0 and count[int(__backpacks[elf][item])- 65] == 2){        
          count[int(__backpacks[elf][item])- 65] = 3;
        }
      }
      else{
        if((elf + 1) % 3 == 1){
        count[int(__backpacks[elf][item])- 97 + 26] = 1;
        }
        if((elf + 1) % 3 == 2 and count[int(__backpacks[elf][item])- 97 + 26] == 1){
        count[int(__backpacks[elf][item])- 97 + 26] = 2;
        }
        if((elf + 1) % 3 == 0 and count[int(__backpacks[elf][item])- 97 + 26] == 2){
        count[int(__backpacks[elf][item])- 97 + 26] = 3;
        }
      }
    }
    if((elf + 1) % 3 == 0 ){
      for(int letter = 0; letter < 52; letter++){
        if(count[letter] == 3){
          if(letter < 26){
            priority += letter + 27;
          }
          else{
            priority += letter - 26 + 1;
          }
        }
        count[letter] = 0;
      }
    }
  }
  cout << "Sum of priorities: " << priority << "\n";

  return 0;

}