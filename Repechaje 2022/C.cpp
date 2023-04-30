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

lli findIndex(vector<lli> &nums, lli curNum) {

    auto it = lower_bound(nums.begin(), nums.end(), curNum);

    return (lli) (it - nums.begin());
}

int main() { _

    lli N, M; cin >> N >> M;

    vector<lli> nums(N);
    vector<lli> sums(N);

    // Crear el vector de números
    for (lli i = 0; i < N; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    sums[0] = nums[0];

    // Construir el valor de sums
    for (lli i = 1; i < N; i++) {
        sums[i] = sums[i-1] + nums[i];
    }    

    // Recibir las queries
    for (lli i = 0; i < M; i++) {
        lli curNum; cin >> curNum;
        lli index = findIndex(nums, curNum);
        //cout << "Index: " << index << endl;

        lli numsRestantes = nums.size() - (index+1);
        //cout << "Num Restantes: " << numsRestantes << endl;

        lli curAns;

        if (index >= nums.size()) {
            curAns = sums[N-1];
        } else {
            curAns = (sums[index]-nums[index]+curNum) + (numsRestantes*curNum);
        }

        cout << curAns << endl;
    }

}   
