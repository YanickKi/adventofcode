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
  string pair;
  vector<string> __pair;

  if(input.is_open()){
      while(input){
        getline(input, pair);
        __pair.push_back(pair); 
    }
    input.close();
  }
//for(auto i = __pair.begin(); i < __pair.end(); i++){
//  cout << *i << endl;
//}

    return 0;
}
