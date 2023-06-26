// SPARSE TABLE PARA MINIMO EN UN RANGO

#include <bits/stdc++.h>
using namespace std;

// Código de https://www.youtube.com/watch?v=0jWeUdxrGm4

const int MAX_N = 100'005;
const int LOG = 17; // "Capas" de la sparse table
int a[MAX_N];
int m[MAX_N][LOG];
int log_precom[MAX_N];

int query(int L, int R) {
    int length = R - L + 1;
    int k = log_precom[length];

    // O(logn)
    // while ((1 << (k+1)) <= length)
    // {
    //     k++;
    // }

    return min(m[L][k], m[R-(1<<k)+1][k]);
}

int main() {
    int n; cin >> n;

    // Log precomputation to n
    log_precom[1] = 0;
    for (int i = 2; i <= n; i++) {
        log_precom[i] = log_precom[i/2]+1;
    }

    // La primera cada de la sparse table
    /*
        El número menor en el rango n-n es n, otra forma
        de verlo es como el punto más bajo de las
        comparaciones
    */
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[i][0] = a[i];
    }

    // Preprocessing
    for (int k = 1; k < LOG; k++) { // Por cada una de las capas de la sparse table
        // Con esto vemos si nos quedan todavía al menos log2(k) elemento por calcular
        // Si no, pues seguimos al siguiente nivel
        for (int i = 0; i + (1<<k) -1 < n; i++) { // Todas las iteraciones de este intervalo
            m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
        }
    }

    // Queries
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int L, R; // De dónde a dónde queremos saber el mínimo
        cin >> L >> R;
        cout << query(L, R) << "\n";
    }
}


// -------------- Código sin comentarios ----------------

/*
#include <bits/stdc++.h>
using namespace std;

// Código de https://www.youtube.com/watch?v=0jWeUdxrGm4

const int MAX_N = 100'005;
const int LOG = 17;
int a[MAX_N];
int m[MAX_N][LOG];
int log_precom[MAX_N];

int query(int L, int R) {
    int length = R - L + 1;
    int k = log_precom[length];

    return min(m[L][k], m[R-(1<<k)+1][k]);
}

int main() {
    int n; cin >> n;

    // Log precomputation to n
    log_precom[1] = 0;
    for (int i = 2; i <= n; i++) {
        log_precom[i] = log_precom[i/2]+1;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[i][0] = a[i];
    }

    // Preprocessing
    for (int k = 1; k < LOG; k++) {
        for (int i = 0; i + (1<<k) -1 < n; i++) {
            m[i][k] = min(m[i][k-1], m[i+(1<<(k-1))][k-1]);
        }
    }

    // Queries
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        cout << query(L, R) << "\n";
    }
}
 */

