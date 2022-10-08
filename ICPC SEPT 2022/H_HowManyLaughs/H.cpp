/*
* Compilacion para ejecucion:  
*    g++ -std=c++17 -O3 -o main *.cpp 
* Ejecucion:
*    ./main < prueba.txt
*/

#include <bits/stdc++.h>
//#include <iostream>
//#include <set>
using namespace std;

int main() {

    int nNums, nMax;
    scanf("%d %d", &nNums, &nMax);

    set<int> mults;

    int temp;
    for (int n = 0; n < nNums; n++) {
        scanf("%d", &temp);
        if (mults.find(temp) == mults.end()) {
            for (int i = temp; i <= nMax; i += temp) {
                mults.insert(i);
            }
        }
    }

    cout << mults.size() << endl;

    return 0;
}