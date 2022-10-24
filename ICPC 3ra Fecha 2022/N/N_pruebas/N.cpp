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



lli CalcPoints (vi &fronts, lli ptr1, lli ptr2, lli N) {
    int totalPoints = 0;

    if (ptr2 == N-1) {
        ptr2 = 0;
    }
    else {
        ptr2++;
    }

    while (ptr1 != ptr2) {
        totalPoints += fronts[ptr1];

        if (ptr1 == N-1) {
            ptr1 = 0;
        }
        else {
            ptr1++;
        }
    }

    return totalPoints;
}

int main() { _
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int N; cin >> N;
    vi fronts(N);

/*
    cout << "Fronts: " << endl;
    printVector(fronts);
    cout << "Backs: " << endl;
    printVector(backs);
    */

    fore (i, 0, N) {
        cin >> fronts[i];
    }

    int K; cin >> K;
    int ptr1 = 0, ptr2 = K-1;

    int maxPoints = 0;
    int cnt = K+1;

    while (cnt--) {
        int curPoints = CalcPoints(fronts, ptr1, ptr2, N);

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

/*

lli CalcPoints (vi &fronts, vi &backs, lli ptr1, lli ptr2, lli N, lli L) {
    int totalPoints = 0;
    priority_queue<int> heap;

    cout << "todo bien" << endl;

    while (ptr1 <= ptr2) {
        totalPoints += fronts[ptr1];
        heap.push(backs[ptr1]);

        if (ptr1 == N-1) {
            ptr1 = 0;
        }
        else {
            ptr1++;
        }
    }

    cout << "todo bien" << endl;

    while (L--) {
        totalPoints += heap.top();
        heap.pop();
    }

    return totalPoints;
}

int main() { _
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cout << "todo bien" << endl;
    
    int N; cin >> N;
    vi fronts(N), backs(N);


    cout << "todo bien" << endl;

    fore (i, 0, N) {
        cin >> fronts[i];
    }

    fore(i, 0, N) {
        cin >> backs[i];
    }

    int K, L; cin >> K >> L;
    int ptr1 = 0, ptr2 = K-1;

    cout << "todo bien" << endl;
    int maxPoints = 0;
    int cnt = N;
    while (cnt--) {
        int curPoints = CalcPoints(fronts, backs, ptr1, ptr2, N, L);

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
    */