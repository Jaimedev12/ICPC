#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {

  long long int input;
  float rest;
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
      cout << "yes\n";
    } else {
      cout << "no\n";
    }
    
  }
  
}