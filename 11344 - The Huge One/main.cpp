#include<bits/stdc++.h>
using namespace std;
string num;
bool Check(int n) {
    int du = 0; int len = num.size();
    for (int i=0; i<len; i++) {
        du = du*10 + num[i]-48;
        du %= n;
    }
    return (du==0);
}
int main() {
    int t,n;
    cin >> t;
    while(t--) {
        cin>>num; cin>>n; vector<int>d(n);
        for(int i=0 ;i<n;i++) cin>>d[i];
        bool flag = true;
        for(int i=0; i<n;i++) {
            if(!Check(d[i])) {flag = false; break;}
        }cout<<num;
        if( flag ) cout<<" - Wonderful.\n";
        else cout<<" - Simple.\n";
    }
}
