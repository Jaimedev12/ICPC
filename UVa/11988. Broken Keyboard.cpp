// UVa 11988. Broken Keyboard

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    list<char> outputText;
    list<char>::iterator it;
    
    while (getline(cin, s)){
        
        outputText.clear();
        it = outputText.begin();
        
        for (int i = 0; i < s.length(); i++){
            
            if (s[i] == '[')
                it = outputText.begin();
            
            if (s[i] == ']')
                it = outputText.end();
                
            if (s[i] != '[' && s[i] != ']'){
                outputText.insert(it, s[i]);
            }
            
        }
        
        for (it = outputText.begin(); it != outputText.end(); it++){
            printf("%c", *it);
        }
    }

    return 0;
}
