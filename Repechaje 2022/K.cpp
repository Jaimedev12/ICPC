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

#define N 15

int main() { _

    vector<string> reprs;
    set<string> reprsSet;

    int num = pow(2, N);

    for (int i = 0; i < num; i++) {
        bitset<N> b(i);
        reprs.emplace_back(b.to_string());
    }

    //cout << "1" << endl;

    for (auto rep : reprs) {

        //cout << "2" << endl;

        for (int i = 1; i <= (N+1)/2; i++) {

            //cout << "i: " << i << endl;

            //cout << "3" << endl;

            //vector<string> subStrings;
            
            string temp = rep.substr(0, i);
            bool flag = 1;
            for (int j = i; j < N; j += i) {
                string temp2 = rep.substr(j, i);

                if (temp != temp2) {
                    flag = 0; 
                    break;
                }
                //cout << "Substr: " << rep.substr(j, i) << endl;
            }

            //cout << endl;

            /*
            bool flag = 1;
            for (int k = 1; k < N/i; k++) {
                if (subStrings[k] != subStrings[k-1]) {
                    flag = 0;
                }
            }
            */

            if (flag) {
                reprsSet.insert(rep);
            }
            
        }

    }

    //cout << "Inserted" << endl;

    cout << reprsSet.size() << endl;

    /*
    for (auto it : reprsSet) {
        cout << it << endl;
    }
    */
    



}   
