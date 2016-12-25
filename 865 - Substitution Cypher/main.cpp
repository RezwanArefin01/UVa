#include<bits/stdc++.h>
using namespace std;
int t,pos;
string str,en,dn;
int main() {
    cin>>t;
    getchar(); getline(cin,str);
    while(t--) {
        getline(cin,en);
        getline(cin,dn);
        puts(dn.c_str());puts(en.c_str());
        while(getline(cin,str)&&str!=""){
            for(int i=0;i<str.size();i++) {
                if((pos = en.find(str[i]))!=string::npos){
                    cout<<dn[pos];
                }
                else cout<<str[i];
            }
            puts("");
        }
        if(t) puts("");
    }
}
