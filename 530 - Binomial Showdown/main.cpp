#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll nCr(int n,int m) {
    ll res=1,i;
    if(n-m<m)
        m=n-m;
    for(i=1;i<=m;i++,n--){
        res *= n;
        res /= i;
    }
    return res;
}
int main () {
    int n,k;
    while(cin>>n>>k && (n||k) ){
        cout<<nCr(n,k)<<endl;
    }
}
