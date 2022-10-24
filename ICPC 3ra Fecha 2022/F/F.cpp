// Plantilla de Tsurus Tuneados

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long int lli;
typedef pair<lli, lli> pii;
typedef vector<lli> vi;

#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define sz(s) lli(s.size())
#define all(s) begin(s), end(s)
#define print(s) cout << s << endl
#define fore(i, a, b) for(lli i = (a), TT = (b); i < TT; ++i)
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;

///-------------------------------------------------------------------------
///-------------------------------------------------------------------------

const lli MOD = 1e9 + 7;

///-------------------------------------------------------------------------

lli mcd(lli a, lli b) {return b ? mcd (b, a % b) : a;}
lli mcm(lli a, lli b) {return (!a || !b) ? 0 : a * b / mcd(a, b);}



// Créditos a Germán J por el algoritmo
int main() { _ // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int N; cin >> N;
    int C; cin >> C;

    map<string, lli> map;

    while (N--) {
        string s;
        cin >> s;
        int xi;

        // Encontrar en dónde está el * en la palabra
        fore (i, 0, C) { // for (int i = 0; i < C; i++)
            if (s[i] == '*') {
                xi = i;
                break;
            }
        }

        // Generar todas las variaciones de cada palabra
        fore(i, 0, 26) {
            // Añadimos cada char en base a su valor ASCII
            s[xi] = 'a' + i;
            // Aumentamos sus apariciones en el map
            map[s]++;
            // Con este algoritmo, el número de coincidencias ya se habrá
            // calculado, no va a hacer falta volver a recorrerlo;
            // además en log n, amazing
        }

    }

    // Par para almacenar la mejor respuesta hasta el momento
    pair<string, int> ans = {"", 0};
    // Recorremos todo el map con su iterador, cuando encontremos
    // alguna palabra con un número de concidencias mayor que 
    // el que tenemos guardado en ese momento, lo cambiamos
    // sólo hace falta hacer esto una vez porque en un mapa las
    // palabras ya están ordenadas lexicográficamente
    for(auto it: map) {
        if (it.second > ans.second) {
            ans = {it.first, it.second};
        }
    }

    // Imprimir respuesta
    cout << ans.first << " " << ans.second << endl;

}   