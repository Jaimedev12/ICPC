// #include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main () {
    
    string s; // El string inicial
    cin >> s; // Agarrarlo del input
    s += '$'; // Agregar el dollar sign
    
    // Creamos los vectores de las posiciones y de las clases en base a la longitud de s
    int n = s.length();
    vector<int> p(n), c(n); // p eventualmente será nuestro resultado

    // k = 0
    {
        // k = 0
        // Creamos un vector para guardar cada char en nuestro string con su posicion correspondiente
        /*
            Ej. s = ababba$
            a = {{a, 0}, {b, 1}, {a, 2}...}
         */
        vector<pair<char, int>> a(n); 
        for (int i = 0; i < n; i++) a[i] = {s[i], i};
        // Ordenamos cada char lexicograficamente, guardando su posición original
        sort(a.begin(), a.end());

        // Una vez ordenados los chars lexicograficamente, actualizamos p para guardar
        // las nuevas posiciones
        for (int i = 0; i < n; i++) p[i] = a[i].second;

        // Ahora actualizamos el vector de clases
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i-1].first) {
                c[p[i]] = c[p[i-1]];
            } else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
    }

    // k -> k+1
    int k = 0;
    // Se repite hasta tener mínimo la mitad de elementos que n;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int>> a(n); // pair<pair<clase de primera mitad, clase de segunda mitad>, posición>
        // Con este for construimos los pares de clases con las posiciones ordenadas
        for (int i = 0; i < n; i++) {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }

        // Ordenamos de acuerdo a los pares de clases
        sort(a.begin(), a.end());

        // De nuevo, ya tenieno los pares ordenados, sigue actualizar el vector de posiciones
        for (int i = 0; i < n; i++) p[i] = a[i].second;

        // Otra vez, con el nuevo vector de posiciones, actualizamos de nuevo el vector de clases
        // (Es exactamente le mismo código que con k = 0)
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i-1].first) { // Los pares también pueden evaluarse con el signo ==
                c[p[i]] = c[p[i-1]];
            } else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }

        // Pasamos a k+1
        k++;

    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }

}