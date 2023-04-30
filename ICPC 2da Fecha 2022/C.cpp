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
    int N, M;
    cin >> N >> M;

    map<int, set<int>> registrosSolicitados;
    map<int, set<int>> registrosRegistrados;
    //map<int, vector<pair<int, char>>> errors;

    int numStudentsWithMistakes = 0, numNotRequested = 0, numMissed = 0;

    for (int i = 0; i < N; i++) {

        int curID, nClasses; cin >> curID >> nClasses;

        for (int j = 0; j < nClasses; j++) {
            int classCode; cin >> classCode;
            registrosSolicitados[curID].insert(classCode);
        }        
    } 



    for (int i = 0; i < M; i++) {

        int curID, nClasses; cin >> curID >> nClasses;

        for (int j = 0; j < nClasses; j++) {
            int classCode; cin >> classCode;
            registrosRegistrados[curID].insert(classCode);
        }        
    } 

    


    /*

    for (auto regSolicitado : registrosSolicitados) {

        //map<int, char> errors;
        bool errorFlag = false;

        int curID = regSolicitado.first;

        // Por cada clase solicitada de este alumno
        for (auto claseSolicitada : registrosSolicitados[curID]) {
            // Si la clase solicitada no está registrada
            if (registrosRegistrados[curID].count(claseSolicitada) == 0) {

                //errors[curID].push_back(make_pair(claseSolicitada, '+'));
                errorFlag = true;
                numMissed++;

            } else {
                
                registrosRegistrados[curID].erase(claseSolicitada);

            }
        }

        // Clases sobrantes que están registradas pero no deberían
        for (auto claseRegistrada : registrosRegistrados[curID]) {
            //errors[curID].push_back(make_pair(claseRegistrada, '-'));
            errorFlag = true;
            numNotRequested++;
            //registrosRegistrados[curID].erase(claseRegistrada);
        }

        if (errorFlag) {
            numStudentsWithMistakes++;
        }

    }

    */

    /*

    for (auto registroExtra : registrosRegistrados) {
        int curID = registroExtra.first;
        bool errorFlag = false;

        if (registroExtra.second.size() > 0) {
            errorFlag = true;

            for (auto claseRegistrada : registroExtra.second) {

                errors[curID].emplace_back(make_pair(claseRegistrada, '-'));
                numNotRequested++;

            }

        }

        if (errorFlag) {
            numStudentsWithMistakes++;
        }

    }
    */


    /*
    for (auto err : errors) {

        cout << err.first << " ";
        
        sort(err.second.begin(), err.second.end());

        for (int i = 0; i < err.second.size(); i++) {
            cout << err.second[i].second << err.second[i].first << " ";
        }

        cout << endl;

    }
    */


    if (numStudentsWithMistakes == 0) {
        cout << "GREAT WORK! NO MISTAKES FOUND!" << endl;
    } else {
        cout << "MISTAKES IN " << numStudentsWithMistakes 
        <<  " STUDENTS: " << numNotRequested 
        << " NOT REQUESTED, " << numMissed << " MISSED" << endl;
    }


    

    



    
    for (auto it:registrosSolicitados) {
        cout << it.first << " ";
        
        for (auto it2:it.second) {
            cout << it2 << " ";
        }

        cout << endl;
    }

    cout << endl << endl;

    for (auto it:registrosRegistrados) {
        cout << it.first << " ";
        
        for (auto it2:it.second) {
            cout << it2 << " ";
        }

        cout << endl;
    }
    

}   
