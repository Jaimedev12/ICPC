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


int main() { _
    
    int N, M; cin >> N >> M;

    vector<char> pat(N+1, 'L');
    vector<char> pat2(N+1, 'L');
    vector<char> pat3(N+1, 'L');
    
    vector<int> nums;

    for (int i = 1; i <= N; i++) {
        if (__builtin_popcount(i) % 2 == 0) {
            nums.push_back(i);
        }
    }

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl << endl;

    //pat[0] = 'L';

    for (int i = 1; i <= M; i++){
        pat[i] = 'W';
        pat2[i] = 'W';
        // pat3[i] = 'W';
    }

    for (int i = M; i < N+1; i++) {
        for (int j = 1; j <= M; j++) {
            if (pat[i-j] == 'L' && __builtin_popcount(i-j) % 2 == 0 ) {
                pat[i] = 'W';
                break;
            }
        }
        
    }

    for (int i = M; i < N+1; i++) {
        for (int j = 1; j <= M; j++) {
            if (pat2[i-j] == 'L') {
                pat2[i] = 'W';
                break;
            }
        }
        
    }


    // for (int i = M; i < N+1; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         if (__builtin_popcount(i-j) % 2 == 0 ) {
    //             pat3[i] = 'W';
    //             break;
    //         }
    //     }
        
    // }

   



    cout << "Patron real" << endl;
    for (int i = 0; i < N+1; i++) {
        cout << pat[i] << " ";
        if (i % 10 == 0) {
            cout << endl;
        }
    }

    cout << endl << endl;

    cout << "Patron solo regla 3" << endl;
    for (int i = 0; i < N+1; i++) {
        cout << pat2[i] << " ";
        if (i % 10 == 0) {
            cout << endl;
        }
    }

    // cout << endl << endl;

    // cout << "Patron solo regla 4" << endl;
    // for (int i = 0; i < N+1; i++) {
    //     cout << pat3[i] << " ";
    //     if (i % 10 == 0) {
    //         cout << endl;
    //     }
    // }

}   
