#include <bits/stdc++.h>
//#include <iostream>
using namespace std;

#define PI 3.141592653589
#define MOD 1000000007

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;


int main () {

    int N; cin >> N;
    int count = 0;

    string s; cin >> s;

    for (int i = 0; i < N-1; i++) {

        if (i < N && s[i] == 'a' && s[i+1] == 'a') {

            count += 2;
            i++;

            while (i < N && s[i+1] == 'a'){
                i++;
                count++;
            }

        }

    }

    cout << count << endl;

    /*
    int N, count = 0;

    string s;
    scanf("%d" ,&N);
    cin >> s;

    for(int i = 0; i < (N -1); ++i){
        if((s[i] == 'a') && (s[i+1] == 'a')){
            for(int k = i; s[k] != 'b'; ++k){
                count++;
                i = k;
            }
            if(i >= (N -1)){
                printf("%d\n", count);
                return 0;

            } 
        }
    }

    printf("%d\n", count);

    */
    

    return 0;
}