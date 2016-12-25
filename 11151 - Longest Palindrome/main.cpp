#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001]; string str;
int len(int l, int r) {
    if(l == r) return dp[l][r] = 1;
    if(l + 1 == r) return dp[l][r] = (str[l] == str[r]) ? 2 : 1;
    if(dp[l][r] != -1) return dp[l][r];
    if(str[l] == str[r]) return dp[l][r] = 2 + len(l+1, r-1);
    else return dp[l][r] = max(len(l+1, r), len(l, r-1));
}
int main() {
    int t; cin>>t; getline(cin, str); while(t--) {
        getline(cin, str);
        if(str.size() == 0) {cout<<0<<endl; continue;}
        memset(dp, -1, sizeof dp);
        cout<<len(0, str.size()-1)<<endl;
    }
}
