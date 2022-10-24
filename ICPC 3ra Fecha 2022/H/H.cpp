#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

#define PI 3.141592653589
#define MOD 1000000007

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

int main () {

    int N,M, R, S;
    scanf("%d %d", &N, &M);
    vector<bool> Destino_filas(N+1), Origen_columnas(N+1);

    for(int i = 1; i <= M; ++i){
        scanf("%d %d", &R, &S);
        Origen_columnas[R] = true;
        Destino_filas[S] = true;
    }

    int caminosRestantes = 0;
    
    for(int x = 1; x <= N; ++x){
        if(!Origen_columnas[x]){
            caminosRestantes++;
        }
        if(!Destino_filas[x]){
            caminosRestantes++;
        }
    }

    printf("%d\n", caminosRestantes);

    return 0;
}