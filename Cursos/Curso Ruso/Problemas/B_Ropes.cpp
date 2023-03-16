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
#define eps 10e-6

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;


///-------------------------------------------------------------------------
///-------------------------------------------------------------------------

const lli MOD = 1e9 + 7;

///-------------------------------------------------------------------------

lli mcd(lli a, lli b) {return b ? mcd (b, a % b) : a;}
lli mcm(lli a, lli b) {return (!a || !b) ? 0 : a * b / mcd(a, b);}

int n, k; 
vector<double> vec;

bool good(double mid) {

    int cnt = 0;

    for (int i = 0; i < vec.size(); i++) {
        cnt += vec[i]/mid;
    }

    if (cnt >= k) {
        return true;
    }
    
    return false;

}

int main() { _
    
    
    cin >> n >> k;

    vec.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> vec[i];
    } 

    double l = 0, r = 10000000;
    double mid;

    int cnt = 100;

    while (cnt) {
        mid = (l + r)/2;

        if (good(mid)) {
            l = mid;
        } else {
            r = mid;
        }

        cnt--;

    }

    cout << setprecision(10) << fixed << l << endl;


}   
