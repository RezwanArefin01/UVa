#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; while(t--) {
        string s; cin>>s;
        int L = (s[0]-'A')*26*26+(s[1]-'A')*26+(s[2]-'A');
        int R = (s[4]-'0')*1000+(s[5]-'0')*100+(s[6]-'0')*10+(s[7]-'0');
        if(abs(L-R) > 100) cout<<"not ";
        puts("nice");
    }
}
