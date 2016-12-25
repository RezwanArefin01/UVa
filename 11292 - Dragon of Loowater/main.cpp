#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    while(cin>>n>>m && (n||m)) {
        int dragon[n],kni[m];
        for(int i=0; i<n;i++) cin>>dragon[i];
        for(int i=0; i<m;i++) cin>>kni[i];
        int gold,d,k; gold = d = k = 0; sort(dragon,dragon+n); sort(kni,kni+m);
        while(d < n && k < m) {
            while(dragon[d] > kni[k] && k < m) k++;
            if(k == m) break;
            gold += kni[k];
            d++, k++;
        }
        if(d == n) cout<<gold<<endl;
        else puts("Loowater is doomed!");
    }
}
