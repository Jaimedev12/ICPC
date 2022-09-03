/*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < prueba.txt
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  vector<string> palabras; 
  vector<bool> abecedario(26, 0);
  for (int i = 0; i < n; i++) {
    string temp;
    cin >> temp;
    abecedario[(int) temp[0] - 65] = 1;
    palabras.push_back(temp);
  }

  for (string pal : palabras) {

    function<bool()> f = [&] () -> bool {
      
      for (char letra : pal) {
        if (abecedario[(int) letra - 65] == 0) {
          return false;
        }
      }
      return true;
    };

    bool flag = f();

    if (flag) {
      cout << "Y" << endl;
      return 0;
    }    
  }

  cout << "N" << endl;
  return 0;
  
}