#include<bits/stdc++.h>
using namespace std;

int N, target;
int memo[1<<20];
vector<int> C;
int matching(int bitmask) {
    if(bitmask == target) return 0;
    if(memo[bitmask] != -1) return memo[bitmask];
    int p1, p2, p3;
    int ans = 0;
    for(p1=0 ;p1<N; p1++) if(!(bitmask & (1<<p1)))
    for(p2=p1+1 ;p2<N; p2++) if(!(bitmask & (1<<p2)))
    for(p3=p2+1 ;p3<N; p3++) if(!(bitmask & (1<<p3)))
            ans = max(ans, ((C[p1] + C[p2] + C[p3] >= 20)?1:0) +
                        matching(bitmask | (1<<p1) | (1<<p2) | (1<<p3)));
    return memo[bitmask] = ans;
}
int main() {
    int co = 0;
    while(scanf("%d",&N) && N) {
        C.resize(N);
        for(int i=0; i<N; i++) cin>>C[i];
        target = (1 << N) -1;
        for(int i=0; i<(1<<20); i++) memo[i] = -1.0;
        printf("Case %d: %d\n", ++co, matching(0));
    }
}
