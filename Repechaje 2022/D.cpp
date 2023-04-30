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

    int M; cin >> M;    
    unordered_map<int, int> numsByOperation;
    multiset<int> nums;

    int A, B;
    int num;
    int numSmallerElements;

    for (int i = 1; i <= M; i++) {
        int op; cin >> op;
        

        switch (op)
        {
            case 1:
                cin >> A;
                numsByOperation[i] = A;
                nums.insert(A);
                break;
            case 2:
                cin >> B;
                nums.erase(nums.find(numsByOperation[B]));
                break;
                
            case 3: 
                cin >> B >> A;
                nums.erase(nums.find(numsByOperation[B]));
                numsByOperation[B] += A;
                nums.insert(numsByOperation[B]);
                break;
                
            case 4:
                cin >> B;

                cout << *nums.find(numsByOperation[B]) << endl;

                
                numSmallerElements = distance(nums.begin(), nums.find(numsByOperation[B]));
                cout << numSmallerElements << endl;
                
                break;
        
            default:
                break;
        }

    }

}   
