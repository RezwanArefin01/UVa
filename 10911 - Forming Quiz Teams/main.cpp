#include <bits/stdc++.h>
using namespace std;
int n, target;
double dist[20][20], memo[1<<16];
double match(int mask) {
    if(memo[mask] < 2*1e9) return memo[mask];
    if(mask == 0) return memo[mask] = 0;
    double ans = 2*1e9;
    int p1 = log2((mask&-mask)); 
    for(int p2 = p1+1; p2 < 2*n; p2++) if(mask & (1 << p2)) 
        ans = min(ans, dist[p1][p2] + 
                       match(mask - (1<<p1) - (1<<p2)));
    return memo[mask] = ans;
}
int main() {
    int co = 0, x[20],y[20];
    while(scanf("%d", &n), n) {
        for(int i=0; i<2*n; i++) 
            scanf("%*s %d %d", &x[i], &y[i]);
        for(int i=0; i<2*n; i++) for(int j=i+1; j<2*n; j++)
            dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);
        for(int i=0; i<(1<<16); i++) memo[i] = 2*1e9;
        printf("Case %d: %.2f\n", ++co, match( (1 << (2*n)) -1) ) ;
    }
}
