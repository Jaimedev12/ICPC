#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

#define PI 3.141592653589
#define MOD 1000000007

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;
#define maxH 1000001
#define maxN 100001

int main () {
    int N, h, flechas = 0;

    scanf("%d", &N);
    unordered_map <int,int> queridos(N+1);
    
    
    // Recibir datos
    for(int i = 1; i <= N; ++i){
        scanf("%d", &h);
        if(queridos[h] == 0){
            queridos[h-1]++;
            flechas++;
        }
        else if(queridos[h] >= 1){
            queridos[h]--;
            queridos[h-1]++;
        }
    }
    

    printf("%d\n", flechas);

    return 0;
}