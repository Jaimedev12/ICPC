#include <iostream>
#include <cmath>

#define lli long long int
using namespace std;

lli c = (pow(10, 9)+7);

lli result[1000100] = {};
lli factorial(int n)
{
    if (n >= 0) 
    {
        result[0] = 1;
        for (int i = 1; i <= n; ++i) 
        {
            result[i] = (i * result[i - 1]) % c;
        }
        return result[n];
    }
}

int combinations (int a, int b){
  int cnt = 1;
  for (int i = 0; i < b; i++){
    cnt *= (a-i);
  }
  return (cnt/factorial(b)) % c;
}

int main() {

  lli N, M, K, almacen = 0, C;
  cin >> N >> M >> K;

  if (K % 2 == 0){
    for (int i = 0; i < K; i++){
      almacen += (combinations(K, K-i)) * (((int) pow(K-i, N))%c) * (((int) pow(-1, K-i))%c);
    }
  } else{
    for (int i = 0; i < K; i++){
      almacen += (combinations(K, K-i)) * (((int) pow(K-i, N))%c) * (((int) pow(-1, K+1-i))%c);
    }
  }
  
  cout << (combinations(M, K) * almacen)%c << "\n";
  
  
  
}