#include<bits/stdc++.h>
using namespace std;

int m, memo[1<<22], stick[21], sum;

bool search(int l, int bitmask) {
    if(memo[bitmask] != -1) return memo[bitmask];
    if(l > sum/4) return 0;
    else if(l == sum/4) { if (bitmask == (1<<m) - 1) return 1; l = 0;}

    for(int i=0; i<m; i++)
        if(!(bitmask &  (1<<i)) && search(l + stick[i], bitmask | (1<<i)))
            return 1;
    return memo[bitmask] = 0;
}
bool solved(){
    sum = accumulate(stick, stick + m, 0);
    if(sum % 4) return 0;
    memset(memo, -1, sizeof memo);
    return search(0,0);
}
int main() {
    int t; cin>>t; while(t--) {
        cin>>m; for(int i=0; i<m;i++) cin>>stick[i];
        puts(solved()? "yes" : "no");
    }
}
