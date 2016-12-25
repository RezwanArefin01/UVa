#include<bits/stdc++.h>
using namespace std;

int main() {
    string code[11]; int n, co = 0;
    while (cin >> code[0]) {
        n = 0; do {
            n++;
            cin >> code[n];
        } while (code[n][0]!='9');
        bool yes = true;
        for (int i=0; i<n && yes; i++) for (int j=i+1; j<n && yes; j++) {
                string s = code[i].substr(0, code[j].length()); if (s==code[j]) yes = false;
                       s = code[j].substr(0, code[i].length()); if (s==code[i]) yes = false;
        }
        cout<<"Set "<< ++co << " is"<< (yes ? ("") : (" not")) << " immediately decodable"<<endl;
    }
}
