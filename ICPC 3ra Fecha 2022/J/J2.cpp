#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

#define PI 3.141592653589
#define MOD 1000000007

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

void SubtCard(int &persona, int carta) {
    if (carta > 10) {
        persona -= 10;
    } else {
        persona -= carta;
    }
}

int main () {

    int J = 23, M = 23;
    int N; cin >> N;

    vi disp(14, 4);

    int j1, j2, m1, m2;

    cin >> j1;
    SubtCard(J, j1);
    disp[j1]--;

    cin >> j2;
    SubtCard(J, j2);
    disp[j2]--;

    cin >> m1;
    SubtCard(M, m1);
    disp[m1]--;

    cin >> m2;
    SubtCard(M, m2);
    disp[m2]--;

    
    //cout << J << " " << M << endl;

    int temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        SubtCard(J, temp);
        SubtCard(M, temp);
        disp[temp]--;
    }




    for (int card = 1; card <= 13; card++) {
        int tempJ, tempM;

        if (card == 11 || card == 12 || card == 13) {
            tempJ = J - 10;
            tempM = M - 10;
        } 
        else {
            tempJ = J - card;
            tempM = M - card;
        }

        if (disp[card] == 0) {
            continue;
        }
        else if (tempM == 0) {
            cout << card << "\n";
            return 0;
        }
        else if (tempJ < 0 && tempM >= 0) {
            cout << card << "\n";
            return 0;
        }

    }

    cout << -1 << "\n";


    return 0;
}