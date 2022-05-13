#include <iostream>
#include <vector>

using namespace std;

vector<bool> isPrime;
vector<int> primes;

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


int main() {

  int T, i, j, cnt;

  cin >> T;

  criba(100000);

  for (int index = 0; index < T; index++){
    cin >> i >> j;
    cnt = 0;

    for (int jindex = 0; jindex < primes.size(); jindex++){
      if (primes[jindex] >= i && primes[jindex] <= j){
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
}