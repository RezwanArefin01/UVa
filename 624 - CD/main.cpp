#include<bits/stdc++.h>
using namespace std;

int ans, track[21], n_total, tapeLen, n;

void search(int total, int mask, int p) {
    if(total > tapeLen) return;
    if(total > n_total) {
        n_total = total, ans = mask;
    }
    if(p >= n) return;
    search(total + track[p], mask | (1<<p), p+1);
    search(total, mask, p+1);
}
int main() {
    while(cin>>tapeLen>>n) {
        for(int i=0; i<n; i++) cin>>track[i];
        ans = n_total = -1;
        search(0,0,0);
        for(int i=0;i<n;i++)
            if( (ans >> i) % 2) cout<<track[i]<<" " ;
        cout<<"sum:" <<n_total<<endl;
    }
}
