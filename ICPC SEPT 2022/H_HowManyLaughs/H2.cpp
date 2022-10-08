/*
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main < prueba.txt
 */

#include <bits/stdc++.h>
using namespace std;

int main() {

  int nNums, nMax;
  scanf("%d %d", &nNums, &nMax);

  vector<int> mults(nMax + 1);

  int temp;
  for (int n = 0; n < nNums; n++) {
    scanf("%d", &temp);
    if (mults[temp] == 0) {
      for (int i = temp; i <= nMax; i += temp) {
        mults[i] = 1;
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i <= nMax; i++) {
    if (mults[i] == 1) {
      cnt++;
    }
  }

  cout << cnt << endl;

  return 0;
}