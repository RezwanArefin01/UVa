#include<bits/stdc++.h>
using namespace std;

int countBit(int N) {
    int res = 0;
    while(N) res++, N &= N-1;
    return res;
}
int main() {
    int t,m; cin>>t;
    while(t--) {
        cin>>m;
        int b1 = countBit(m),b2 = 0;
        int tmp = 1;
        while(m) b2 += (m%10)*(tmp), tmp*=16, m/=10;
        b2 = countBit(b2);
        cout<<b1<<" " <<b2<<endl;
    }
}
