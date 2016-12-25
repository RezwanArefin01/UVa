#include<bits/stdc++.h>
using namespace std;
vector<int> deg, degSum, ind, minVal;
int n;
bool ErdosGallai() {
    bool poss = true;
    int i, sum = 0, j, r;
    for( i = 1; i <= n; i++ ) {
        if( deg[i] >= n ) poss = false;
        sum += deg[i];
    }
    if(!poss || (sum&1) || (n==1&&deg[1]>0 ))
        return false;
    sort( ++deg.begin(), ++deg.begin()+n, greater <int>());
    degSum[0] = 0;
    j = n;
    for( i = 1; i <= n; i++ ) {
        degSum[i] = degSum[i-1] + deg[i];
        for( ; j >= 1 && deg[j] < i; j-- );
        ind[i] = j+1;
    }
    for(r = 1; r < n; r++) {
        j = ind[r];
        if( j == n+1 ) minVal[r]=( n - r ) * r;
        else if( j <= r ) minVal[r] = degSum[n] - degSum[r];
        else {
            minVal[r] = degSum[n] - degSum[j-1];
            minVal[r] += (j-r-1)*r;
        }
    }
    for( r = 1; r < n; r++ )
        if( degSum[r] > ( r*(r-1) + minVal[r] ) ) return false;
    return true;
}
int main() {
    while(cin>>n && n) {
        deg.clear(), degSum.clear(), ind.clear(), minVal.clear();
        deg.resize(n+1), degSum.resize(n+1), ind.resize(n+1), minVal.resize(n+1);
        for(int i=1;i<=n;i++) cin>>deg[i];
        if(ErdosGallai()) puts("Possible");
        else puts("Not possible");
    }
}
