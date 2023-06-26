#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

struct vertex {
    map<char,int> next,go;
    int p,link;
    char pch;
    vector<int> leaf;
    vertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1){}
};

vector<vertex> t;

void aho_init() {
    t.clear();
    t.pb(vertex());
}

void add_string(string s, int id) {
    int v=0;
    for(char c:s) {
        if(!t[v].next.count(c)) {
            t[v].next[c]=t.size();
            t.pb(vertex(v,c));
        }
        v=t[v].next[c];
    }
    t[v].leaf.pb(id);
}

int go(int v, char c);
int get_link(int v) {
    if(t[v].link<0)
        if(!v||!t[v].p) t[v].link=0;
        else t[v].link=go(get_link(t[v].p),t[v].pch);
    return t[v].link;
}

int go(int v, char c) {
    if(!t[v].go.count(c))
        if(t[v].next.count(c)) t[v].go[c]=t[v].next[c];
        else t[v].go[c]=v==0?0:go(get_link(v),c);
    return t[v].go[c];
}

ll countSeparations(string s) {
    int n = s.size();
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;

    fore(i, 0, n) {
        int v = 0;
        for (int j = i; j >= 0; --j) {
            v = go(v, s[j]);
            if (t[v].leaf.empty()) continue;
            for (int leaf : t[v].leaf) {
                if (j - (int)t[leaf].pch + 1 >= 0) {
                    dp[i + 1] += dp[j - t[leaf].pch + 1];
                }
            }
        }
    }

    return dp[n];
}

int main() {
  
    aho_init();

    string s; cin >> s;

    int n; cin >> n;
    fore(i, 0, n) {
        string tempS; cin >> tempS;
        add_string(tempS, i);
    }

    ll result = countSeparations(s);
    cout << result << endl;

    return 0;
}
