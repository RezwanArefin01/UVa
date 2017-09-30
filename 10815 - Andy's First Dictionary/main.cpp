#include<bits/stdc++.h>
using namespace std;
int main() {
    set<string>s;
    char str[205];
    while(gets(ar)){
        string s = "";
        for(i=0;i<=l;i++) {
            if(isalpha(ar[i]))
                x+=tolower(ar[i]);
            else if(x!="") {
                s.insert(x);
                x="";
            }
        }
    }
    for(set<string>::iterator it=s.begin();it!=s.end();it++)
    cout<<*it<<endl;
    return 0;
}
