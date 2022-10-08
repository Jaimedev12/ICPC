/*
 * Compilacion para ejecucion:
 *    g++ -std=c++17 -O3 -o main *.cpp
 * Ejecucion:
 *    ./main < prueba.txt
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int nEstaciones;
  cin >> nEstaciones;

  int n = nEstaciones + (nEstaciones - 1);

  vector<int> path(n);

  for (int i = 1; i < n - 1; i += 2) {
    int temp;
    cin >> temp;
    path[i] = temp;
  }

  for (int i = 0; i < n; i += 2) {
    int temp;
    cin >> temp;
    path[i] = temp;
  }

  int ptr1 = 0, ptr2 = n - 1;

  while (ptr1 != ptr2) {
    if (path[ptr1] < path[ptr2]) {
      path[ptr2] -= path[ptr1];
      path[ptr1] -= path[ptr1];
      ptr1++;
    } else if (path[ptr2] < path[ptr1]) {
      path[ptr1] -= path[ptr2];
      path[ptr2] -= path[ptr2];
      ptr2--;
    } else {
      path[ptr1] -= path[ptr1];
      path[ptr2] -= path[ptr2];
      ptr1++;
      ptr2--;
    }
  }

  if (!(ptr1 & 1)) {
    cout << path[ptr1] << endl;
  } else {
    cout << 0 << endl;
  }

  return 0;
}
