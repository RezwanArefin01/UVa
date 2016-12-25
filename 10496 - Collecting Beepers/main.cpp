#include<bits/stdc++.h>
using namespace std;
int dist[11][11], memo[11][1<<11],target, t, x[11],y[11], n;

int tsp(int pos, int bitmask) {
    if(bitmask == target) return dist[pos][0];
    if(memo[pos][bitmask] != -1) return memo[pos][bitmask];

    int ans = 1e9;
    for(int i=0; i<n; i++)
        if(pos != i && !(bitmask & (1 << i)))
            ans = min(ans, dist[pos][i] + tsp(i, bitmask | (1<<i)));
    return memo[pos][bitmask] = ans;
}
int main() {
    cin>>t;
    while(t--) {
        scanf("%*d %*d");
        scanf("%d %d", &x[0], &y[0]);
        cin>>n; n++; target = (1 << n) -1;
        for(int i = 1; i < n; i++)
            scanf("%d %d", &x[i], &y[i]);
        for(int i=0;i<n;i++) for(int j=0;j<n;j++)
            dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    memset(memo, -1, sizeof memo);
    printf("The shortest path has length %d\n", tsp(0, 1));
    }
}
