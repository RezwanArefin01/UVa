#include<bits/stdc++.h>
using namespace std;
int t,co=0, N; typedef unsigned long long ll;
int main() {
    cin>>t; while(t--) {
        cin>>N; ll A[10], n = 0, m = 0, tmp = 1;
        for(int i=0; i<N; i++) {cin>>A[i]; tmp*= A[i];}
        m = tmp*N;
        for(int i=0; i<N;i++) n += tmp/A[i];
        ll g = __gcd(m,n); m/=g, n/=g;
        printf("Case %d: %lld/%lld\n", ++co, m, n);
    }
}
