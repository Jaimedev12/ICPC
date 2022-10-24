#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

#define PI 3.141592653589
#define MOD 1000000007

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int main () {

    int N; 
    cin >> N;

    int x, y; 
    cin >> x >> y;

    int nDivs = 0;

    while (!(x & 1)) {
        x /= 2;
        y /= 2;
        nDivs++;
    }

    cout << N-1-nDivs << endl;
    
}