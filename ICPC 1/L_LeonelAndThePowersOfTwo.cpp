#include <iostream>
#include <string>

typedef long long int lli;

using namespace std;

string s;

string finalString(lli k){
  if (k == 1){
    s = "2";
  } else if (k % 2 != 0){
    s = "(2*" + finalString(k-1) + ")";
  } else if(k % 2 == 0){
    s = "(" + finalString(k/2) + ")^2";
  }
  return s;
}

int main() {
  lli T, k;
  cin >> T;

  for(int i = 0; i < T; i++){
    cin >> k;
    cout << finalString(k) << endl;
  }
}