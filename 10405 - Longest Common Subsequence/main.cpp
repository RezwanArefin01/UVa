#include<bits/stdc++.h>
using namespace std;
int dp[1100][1100],a,b;
int LCS(string A,string B) {
    for(int i=1;i<=a;i++)
    for(int j=1;j<=b;j++) {
        if(A[i-1]==B[j-1]) dp[i][j] = dp[i-1][j-1] +1;
        else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    }
    return dp[A.size()][B.size()];
}
int main() {
    string A,B;
    while(getline(cin,A)){
        getline(cin,B);
        a = A.size(); b = B.size();
        for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) dp[i][j] = 0;
        cout<<LCS(A,B)<<endl;
    }
}
