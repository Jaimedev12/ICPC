
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  long long int n, cnt = 0;
  int d;

  cin >> s;
  n = stoi(s);
  
  for (int i = 0; i < s.size(); i++){
    d = (int) s[i] - 48; 
    
    if(d != 0){
      if (n % d == 0){
      cnt++;
      }
    }
  }
  
  cout << cnt << "\n";
}