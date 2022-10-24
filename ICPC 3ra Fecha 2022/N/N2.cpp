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

lli CalcPointsSpecial(vi &fronts, vi &backs, lli ptr1, lli ptr2, lli N, lli L) {
    lli totalPoints = 0;
    priority_queue<lli> heap;

    ptr2++;

    while (ptr1 != ptr2) {
        totalPoints += fronts[ptr1];
        heap.push(backs[ptr1]);

        ptr1++;
    }

    while (L--) {
        totalPoints += heap.top();
        heap.pop();
    }

    return totalPoints; 
}

lli CalcPoints (vi &fronts, vi &backs, lli ptr1, lli ptr2, lli N, lli L, lli K) {
    lli totalPoints = 0;
    priority_queue<lli> heap;

    if (ptr2 == N-1) {
        ptr2 = 0;
    }
    else {
        ptr2++;
    }

    cout << "todo bien" << endl;

    while (ptr1 != ptr2) {
        totalPoints += fronts[ptr1];
        heap.push(backs[ptr1]);

        if (ptr1 == N-1) {
            ptr1 = 0;
        }
        else {
            ptr1++;
        }
    }

    while (L--) {
        totalPoints += heap.top();
        heap.pop();
    }

    return totalPoints;
}

int main() { _
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int N; cin >> N;
    vi fronts(N);
    vi backs(N);

    fore (i, 0, N) {
        cin >> fronts[i];
    }
    fore(i, 0, N) {
        cin >> backs[i];
    }

    int K, L; cin >> K >> L;
    int ptr1 = 0, ptr2 = K-1;

/*
    if (N == K) {
        cout << CalcPointsSpecial(fronts, backs, ptr1, ptr2, N, L) << endl;
        return 0;
    }
    */

    int maxPoints = 0;
    int cnt = K+1;

    while (cnt--) {
        int curPoints = CalcPoints(fronts, backs, ptr1, ptr2, N, L, K);
        //int curPoints = cnt;

        if (N == K) {
            cout << curPoints << endl;
            return 0;
        }

        maxPoints = max(maxPoints, curPoints);

        if (ptr1 == 0) {
            ptr1 = N-1;
        }
        else {
            ptr1--;
        }

        if (ptr2 == 0) {
            ptr2 = N-1;
        }
        else {
            ptr2--;
        }
        
    }

    cout << maxPoints << endl;

}   
