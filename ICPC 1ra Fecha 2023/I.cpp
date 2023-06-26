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

    vector<int> vis(30, 0);
    string origS, s;
    int n, k;

    cin >> n >> k;
    cin >> origS;

    while (origS[0] == origS[n-1]) {
        n--;
    }   

    s = origS + origS.substr(0, n);
    n = s.size();

    //cout << s << endl;

    int start = 0, end = 0;

    vector<pair<char, int>> input;

    // Choose a place to start
    int next = start + 1;
    while (s[next] == s[start]) {
        start = next;
        next++;

        if (next == n) {
            cout << -1 << endl;
            return 0;
        }
    }

    start = next;

    // cout << "Place to Start: " << start << endl;

    end = start;

    vis[s[start] - 'a']++;

    int curLen = 0, maxLen = 0, maxStart = 0, maxEnd = 0;

    while (start < n && end < n) {
        end++;

        vis[s[end] - 'a']++;
        curLen++;

        while (end+1 < n && s[end+1] == s[end]) {
            end++;
            vis[s[end] - 'a']++;
            curLen++;
        }

        //cout << end << endl;

        while (start < n && (s[start-1] == s[start] || vis[s[end] - 'a'] > k)) {

            vis[s[start] - 'a']--;
            start++;
            curLen--;

        } 

        if (curLen+1 > maxLen) {
            maxLen = curLen;
            maxStart = start;
            maxEnd = end;
        }

        // cout << "CurLen: " << curLen+1 << endl;
        // cout << "Start: " << start << endl;
        // cout << "End: " << end << endl << endl;

    }

    maxLen = min((int)maxLen+1, (int)origS.size());

    cout << maxLen << endl;
    cout << s.substr(maxStart, maxLen) << endl;
        
}   
