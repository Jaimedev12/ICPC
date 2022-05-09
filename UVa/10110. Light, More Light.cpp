#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {

  long long int input;
  double rest;
  
  while (scanf("%lld", &input)){

    if(input == 0){
      break;
    }
    
    rest = sqrt(input);

    cout << (rest == round(rest) ? "yes\n":"no\n");
  }
  return 0;
}