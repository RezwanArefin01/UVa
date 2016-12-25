#include<bits/stdc++.h>
using namespace std;

bool isSubset(vector<int> &num, int sum) {
    int n = num.size();
    bool subset[sum+1][n+1];
    for(int i=0;i<=n;i++) subset[0][i] = true;
    for(int i=1;i<=sum;i++) subset[i][0] = false;
    for(int i=1;i<=sum;i++) {
        for(int j=1;j<=n;j++) {
            subset[i][j] = subset[i][j-1];
            if (i >= num[j-1]) subset[i][j] |= subset[i - num[j-1]][j-1];
        }
    }
    return subset[sum][n];
}

int main(){
    int t,n,sum;
    cin>>t;
    while(t--) {
        cin>>sum>>n;vector<int>a(n);
        for(int i=0; i<n;i++) cin>>a[i];
        if(isSubset(a,sum)) puts("YES");
        else puts("NO");
    }
}
