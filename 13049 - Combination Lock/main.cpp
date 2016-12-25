#include<bits/stdc++.h>
using namespace std;

int steps(int a, int b) {
    return min(abs(a-b), 10 - abs(a-b));
}
int main() {
    int t, co=0; cin>>t; while(t--) {
        int n, ans=0; cin>>n; string a,b;
        cin>>a>>b;
        for(int i=0; i<n; i++)
            ans += steps(a[i]-'0', b[i]-'0');
        cout<<"Case "<<++co<<": "<<ans<<endl;
    }
}
