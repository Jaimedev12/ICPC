#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//vector<bool> isPrime;
//vector<int> primes;

/*
void criba(int n) {
  
  isPrime = vector<bool>(n, true);
  primes = vector<int>();
  isPrime[0] = isPrime[1] = false;
  
  for (int i=2; i<n; ++i) {
    
    if (isPrime[i]) {
      primes.push_back(i);
      
      for (int h=2; h*i<n; ++h){
        isPrime[i*h] = 0;
      } 
      
    }
  }
}
*/

int main() {

  int T, i, j, cnt, cnt2;

  cin >> T;

  //criba(1000000);

  for (int index = 0; index < T; index++){
    cin >> i >> j;
    cnt = 0;
    cnt2 = 0;

    for (int jindex = i; jindex <= j; jindex++){

      for (int k = 2; k <= sqrt(jindex); k++){

        cnt2 = 0;
        
        if (jindex % k == 0){
          cnt2++;
          break;
        }
        
      }

      if (cnt2 == 0){
        cnt++;
      }
      
      
      
    }


    /*
    for (int jindex = 0; jindex < primes.size(); jindex++){    
      if (primes[jindex] >= i && primes[jindex] <= j){
        cnt++;

        if (primes[jindex] > j){
          break;
        }
        
      }
    }
    */
    
    cout << cnt << "\n";
  }
}