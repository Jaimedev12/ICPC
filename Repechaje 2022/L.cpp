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


int nHijosFunct(int node, vector<unordered_set<lli>> &hijos) {
    
    int ans = 0;

    for(auto hijo : hijos[node]) {
        ans += nHijosFunct(hijo, hijos);
        ans++;
    }

    return ans;

}


int main() { _

    lli N, X; cin >> N >> X;

    vector<unordered_set<lli>> hijos(N+1);
    vector<vector<lli>> adj(N+1);

    for (lli i = 0; i < N-1; i++) {
        lli src, dest;
        cin >> src >> dest;
        adj[src].emplace_back(dest);
        adj[dest].emplace_back(src);
    }


    // BFS
    bitset<1000001> visited;
    queue<lli> q;
    q.push(1);
    visited[1] = true;
    vector<lli> parents(N+1);
    while (!q.empty()) {
        lli node = q.front();
        q.pop();
        for (lli nbr : adj[node]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                parents[nbr] = node;
                hijos[node].insert(nbr);
                q.push(nbr);
            }
        }
    }

    // Sacar Ruta
    vector<lli> ruta;
    lli temp = X;
    while (temp != 1) {
        ruta.emplace_back(temp);
        temp = parents[temp];
    }

    reverse(ruta.begin(), ruta.end());

    lli ans = (2 * (N-1)) - (2 * (nHijosFunct(parents[X], hijos))) - (2 * (ruta.size() - 1)) + (ruta.size());
    cout << ans << endl;

    /*
    // Obtener respuesta
    //lli ans = 0;
    lli curTreeNode = 1;  
    lli curRutaIndex = 0;  
    while (true) {

        if (hijos[curTreeNode].count(X) == 1) {
            ans++;
            cout << ans << endl;
            return 0;
        }

        for (auto hijo : hijos[curTreeNode]) {
            if (hijo != ruta[curRutaIndex]) {
                ans += (nHijosFunct(hijo, hijos)+1) * 2;
            }
        }

        ans++;
        curTreeNode = ruta[curRutaIndex];
        curRutaIndex++;
    }
    */
    

}   
