#include<bits/stdc++.h>
using namespace std;

int N, target;
double dist[20][20], memo[1<<16];

double matching(int bitmask) {
    if( memo[bitmask] > -0.5) return memo[bitmask];
    if(bitmask == target) return 0;
    double ans = 20000000000.0;
    int p1, p2;
    for(p1 = 0; p1<(N<<1); p1++)
        if(!(bitmask & (1<<p1))) break;
    for(p2 = p1+1; p2 <(N<<1); p2++)
        if(!(bitmask & (1<<p2)))
            ans = min(ans, dist[p1][p2] + matching(bitmask | (1<<p1) | (1<<p2)));
    return memo[bitmask] = ans;
}
int main() {
    int co = 0, x[20],y[20];

    while(scanf("%d", &N), N){
        for(int i=0; i<(N<<1); i++)
            scanf("%*s %d %d", &x[i],&y[i]);
        for(int i=0; i < (N<<1)-1; i++)
            for(int j=i+1; j < (N<<1); j++)
                dist[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
        for(int i=0; i<(1<<16); i++) memo[i] = -1.0;
        target = (1 << (N<<1)) - 1;
        cout<<"Case "<<++co<<": "<<fixed<<setprecision(2)<<matching(0)<<endl;
    }
}
