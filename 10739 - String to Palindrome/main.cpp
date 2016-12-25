#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001]; string str;
int len(int l, int r) {
    if(dp[l][r] != -1) return dp[l][r];
    if(l == r) return dp[l][r] = 0;
    if(l + 1 == r) return dp[l][r] = (str[l] == str[r]) ? 0:1;
    if(str[l] != str[r]) return dp[l][r] = 1 + min(len(l+1, r), min(len(l, r-1), len(l+1, r-1)));
    return dp[l][r] = len(l+1, r-1);
}
int main() {
    int co = 0, t; cin>>t;  while(t--) {
        cin>>str;
        memset(dp, -1, sizeof dp);
        cout<<"Case "<<++co<<": "<<len(0, str.size()-1)<<endl;
    }
}
