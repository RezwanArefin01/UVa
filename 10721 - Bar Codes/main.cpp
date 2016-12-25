#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[60][60];
int m;
ll solve(int n, int k) {
    if(!k) return n?0:1;
    ll &ret = dp[n][k];
    if(ret != -1) return ret; ret = 0;
    for(int i=1; i<=m && n-i >= 0; i++)
        ret+= solve(n-i, k-1);
    return ret;
}
int main() {
    int n,k; while(cin>>n>>k>>m) {
        memset(dp, -1, sizeof dp);
        cout<<solve(n,k)<<endl;
    }
}
