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
  string pair_temp;
  vector<string> NUMBERS;

  if(input.is_open()){

  while(getline(input, pair_temp)){
    size_t prev = 0, pos;
    while ((pos = pair_temp.find_first_of(" -,", prev)) != std::string::npos)
      {
        if (pos > prev)
            NUMBERS.push_back(pair_temp.substr(prev, pos-prev));
        prev = pos+1;
      }
    if (prev < pair_temp.length())
        NUMBERS.push_back(pair_temp.substr(prev, std::string::npos));
  }

    input.close();
  }

  int count = 0;
  for(int pos = 3; pos < NUMBERS.size(); pos += 4){
    if(stoi(NUMBERS[pos]) <= stoi(NUMBERS[pos - 2]) && stoi(NUMBERS[pos-1]) >= stoi(NUMBERS[pos-3])) {
      count += 1;
    }
    if(stoi(NUMBERS[pos]) >= stoi(NUMBERS[pos - 2]) && stoi(NUMBERS[pos-1]) <= stoi(NUMBERS[pos-3])) {
      count += 1;
    }
    if(stoi(NUMBERS[pos]) == stoi(NUMBERS[pos - 2]) && stoi(NUMBERS[pos-1]) == stoi(NUMBERS[pos-3])){
      count -= 1;
    }
  }
  cout << "count PART 1: " << count << endl;


  //Part 2

  count = 0;
  for(int pos = 3; pos < NUMBERS.size(); pos += 4){
    if(stoi(NUMBERS[pos-3]) <= stoi(NUMBERS[pos - 1]) and stoi(NUMBERS[pos-1]) <= stoi(NUMBERS[pos - 2] )
    or stoi(NUMBERS[pos-1]) <= stoi(NUMBERS[pos - 3]) and stoi(NUMBERS[pos-3]) <= stoi(NUMBERS[pos] )
    or stoi(NUMBERS[pos])   >= stoi(NUMBERS[pos - 2]) and stoi(NUMBERS[pos-1]) <= stoi(NUMBERS[pos-2]   )
    or stoi(NUMBERS[pos-2]) >= stoi(NUMBERS[pos])     and stoi(NUMBERS[pos-3]) <= stoi(NUMBERS[pos]   )
    or stoi(NUMBERS[pos-3]) == stoi(NUMBERS[pos - 1]) and stoi(NUMBERS[pos-2]) == stoi(NUMBERS[pos] )) {
      count += 1;
    }
  }
  cout << "count PART 1: " << count << endl;
  return 0;
}
