#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m,c, co=0;
    while(cin>>n>>m>>c && n) {
        bool f[n]; int q[n]; memset(f,0,sizeof f);
        for(int i=0; i<n; i++) cin>>q[i];
        bool burn = false; long long curr = 0, Max = 0, tmp;
        while(m--) {
            cin>>tmp; if(burn) continue; tmp--;
            f[tmp] = !f[tmp];
            if(f[tmp]) curr += q[tmp];
            else curr -= q[tmp];
            Max = max(Max, curr);
            if(curr > c) burn = true;
        }
        cout<<"Sequence "<<++co<<endl;
        if(burn) puts("Fuse was blown.");
        else puts("Fuse was not blown."), cout<<"Maximal power consumption was "<<Max<<" amperes.\n";
        puts("");
    }
}
