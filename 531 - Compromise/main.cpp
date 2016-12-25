#include<bits/stdc++.h>
using namespace std;
string A[110],B[110];
int dp[110][110],a=0,b=0;
void LCS() {
    for(int i=0;i<=a;i++) for(int j=0;j<=b;j++ ) dp[i][j] = 0;
    for(int i=1;i<=a;i++)
    for(int j=1;j<=b;j++) {
        if(A[i-1]==B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
}
bool blank = false;
void traceback(int i, int j){
 if(i == 0|| j == 0)return;
 if(A[i-1] == B[j-1]) {
     traceback(i-1, j-1);
     if(blank) cout<<" ";
     blank = true;
     cout << A[i-1];
 }
 else if(dp[i-1][j] > dp[i][j-1])
     traceback(i-1, j);
 else traceback(i, j-1);
}
int main() {
    string T;
    while(cin>>T) {
        A[a++] = T;
        while(cin>>T && T!= "#") {A[a++] = T;}
        while(cin>>T && T!= "#") {B[b++] = T;}
        LCS();
        traceback(a,b);
        cout<<endl;
        blank = false;
        a= 0;b=0;
    }
    return 0;
}
