

#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

#define PI 3.141592653589
#define MOD 1000000007

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

void AddCard(int &persona, int carta) {
    if (carta > 10) {
        persona += 10;
    } else {
        persona += carta;
    }
}

int main () {

    int J = 0, M = 0;
    int N; cin >> N;

    vi disp(14, 4);

    int j1, j2, m1, m2;

    cin >> j1;
    AddCard(J, j1);
    disp[j1]--;

    cin >> j2;
    AddCard(J, j2);
    disp[j2]--;

    cin >> m1;
    AddCard(M, m1);
    disp[m1]--;

    cin >> m2;
    AddCard(M, m2);
    disp[m2]--;

    
    //cout << J << " " << M << endl;

    int temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        AddCard(J, temp);
        AddCard(M, temp);
        disp[temp]--;
    }


    if (J <= M) {
        int goal = 23-M;

        if (goal > 10) {
            cout << -1 << "\n";
            return 0;
        }

        if (disp[goal] == 0) {
            cout << -1 << "\n";
            return 0;
        } 
        else  {
            cout << goal << "\n";
            return 0;
        }
    }


    else if (J > M) {
        int goalJ = 24 - J; // 4
        int goalM = 23 - M; // 10

        while (goalJ <= goalM) {

            if (goalM > 10) {
                cout << -1 << "\n";
                return 0;
            }

            if (disp[goalJ] == 0) {
                goalJ++;
            } 
            else {
                cout << goalJ << "\n";
                return 0;
            }
        }

        cout << -1 << "\n";

    }


    return 0;
}
