#include<bits/stdc++.h>
using namespace std;
int a,b, co = 0;
int main() {
    while(cin>>a>>b && (a||b)) {
        int dp[a+1][b+1]; memset(dp, 0, sizeof(dp));
        int A[a], B[b];
        for(int i=0;i<a; i++) cin>>A[i];
        for(int i=0;i<b; i++) cin>>B[i];
        for(int i=1; i<=a; i++) for(int j=1; j<=b; j++) {
            if(A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
        cout<<"Twin Towers #"<<++co<<endl;
        cout<<"Number of Tiles : "<< dp[a][b]<<endl<<endl;
    }
}
