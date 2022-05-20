#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int index = 0, step, mod;
  
  while(cin >> step >> mod){
    
    bool vis[mod] = {0};
    bool bad = false;
    
    for (int i = 0; i < mod; i++){
      int generated = (index + step) % mod;

      if (vis[generated] == 1){
        bad = true;
        break;
      }

      vis[generated] = 1;      
      index = generated;
      
    }
  cout << setw(10) << step << setw(10) << mod << "    ";
  bad ? cout << "Bad Choice\n\n" : cout << "Good Choice\n\n";
    
  }
  
}