#include<bits/stdc++.h>
using namespace std;
map<string ,string> m;
int n,l;
string s,a;
int main() {
    cin>>l>>n;
    while(l--) {
        cin>>s>>a;
        m[s] = a;
    }
    while(n--) {
        cin>>s;
        if(m.count(s)==1) {
            cout<<m[s]<<endl;
        }
        else {
            int len = s.size()-1;
            if(s[len]=='y'){
                char las = s[len-1];
                if(las!='a' && las!='e' && las!='i' && las!='o' && las != 'u') {
                    string s1="";
                    for(int i=0;i<len;i++) s1+=s[i];
                    s1+= "ies";
                    s=s1;
                }
                else s.append("s");
            }
            else if(s[len]=='o' || s[len] == 's' || s[len]=='x' || s[len-1]=='c' && s[len]=='h' ||
                    s[len-1]=='s' && s[len]=='h' )
                    s.append("es");
            else s.append("s");
            cout<<s<<endl;
        }
    }
}
