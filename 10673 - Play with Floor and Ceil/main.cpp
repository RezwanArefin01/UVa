#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    unsigned long long q,p,x,k;
    cin>>t;
    while(t--) {
        cin>>x>>k;
        q = x%k;
        p = k-q;
        cout<<p<<" " <<q<<endl;
    }
    return 0;
}
