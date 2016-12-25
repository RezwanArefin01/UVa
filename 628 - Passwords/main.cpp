#include<bits/stdc++.h>
using namespace std;
vector<string> dic; string law;
void backtrack(string s, int pos) {
    if(pos == law.size()) {cout<<s<<endl; return;}
    if(law[pos] == '#') for(int i=0; i<dic.size(); i++) backtrack(s+dic[i], pos+1);
    else for(char i='0'; i<='9'; i++) backtrack(s+i, pos+1);
}
int main() {
    int n,m; while(cin>>n) {
        dic.resize(n); for(int i=0; i<n; i++) cin>>dic[i];
        cin>>m; while(m--) {
            cin>>law; string tmp = "";
            cout<<"--\n";
            backtrack(tmp,0);
        }
    }
}
