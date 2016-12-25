#include<bits/stdc++.h>
using namespace std;

int co =0;
int main() {
    string A,B;
    while(getline(cin,A) && A!="#") {
        getline(cin,B);
        int a = A.size(), b = B.size();
        int dp[a+1][b+1];
        memset(dp, 0, sizeof(dp));

        for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) {
            if(A[i-1]==B[j-1]) dp[i][j] = dp[i-1][j-1] +1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

        cout<<"Case #"<<++co<<": you can visit at most "<<dp[a][b]<<" cities."<<endl;

    }
}
