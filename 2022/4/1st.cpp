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
  vector<string> __pair;
  string temp;
  vector<string> split;

  if(input.is_open()){
      while(input){
        getline(input, pair_temp);
        __pair.push_back(pair_temp); 
    }
    input.close();
  }

  for(int pair = 0; pair < __pair.size(); pair++){
    for(int single = 0; single < __pair[pair].size(); single++){
      if()
    }
  }
//for(auto i = __pair.begin(); i < __pair.end(); i++){
//  cout << *i << endl;
//}

    return 0;
}
