#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        int n; cin>>n; int a[n];
        string s; int pos = 0;
        for(int i=0; i<n; i++) {
            cin>>s;
            if(s[0] == 'L') pos--, a[i] = -1;
            else if(s[0] == 'R') pos++, a[i] = 1;
            else { int p;
                cin>>s>>p; pos += a[p-1]; a[i] = a[p-1];
            }
        } cout<<pos<<endl;
    }
}
