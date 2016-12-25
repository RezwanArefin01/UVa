#include<bits/stdc++.h>
using namespace std;
string str,a,b;
map<string, string> m;
int main() {
    while(getline(cin,str) && str!="") {
        istringstream ss(str);
        ss>>a>>b;
        m[b] = a;
    }
    while(cin>>str) {
        if(m[str] == "") puts("eh");
        else cout<<m[str]<<endl;
    }
}
