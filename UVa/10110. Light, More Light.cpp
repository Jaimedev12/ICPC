#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

int main() {

  int input;
  vector<string> outputs;
  string output;
  float rest = 3;
  bool isPerfect; // Determines if perfect square
  bool evenFactors; // Determines if even number of factors
  
  while (scanf("%d", &input)){

    if(input == 0){
      break;
    }
    
    rest = sqrt(input);
    
    if (rest == (int)rest){
      evenFactors = true;
    } else {
      evenFactors = false;
    }

    if(evenFactors){
      outputs.push_back("yes\n");
    } else {
      outputs.push_back("no\n");
    }
    
  }

  for(int i = 0; i < outputs.size(); i++){
    cout << outputs[i];
  }
  
}