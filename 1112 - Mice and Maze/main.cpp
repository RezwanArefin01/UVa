#include<bits/stdc++.h>
using namespace std;
int read() {
    int n;
    char c = 0;
    while(c<33) c = getc(stdin);
        n = 0;
    while(c>33){
        n = n*10 + c - '0';
        c = getc(stdin);
    }
    return n;
}
int main() {
    bool blank = false;
    int t,n,a,b,c,m,time,exit;
    t = read();
    while(t--){
        int count = 0;
        n = read();
        int adj[n+1][n+1];
        memset (adj,63,sizeof adj);
        exit = read(); time = read(); m = read();
        while(m--) {
            a = read(); b= read(); c = read();
            adj[a][b] = c;
        }
        for(int k=0;k<=n;k++) {
            for(int i=0;i<=n;i++) {
                for(int j=0;j<=n;j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
        for(int i=0;i<=n;i++) {
            if(adj[i][exit]<=time || (i==exit))
                count++;
        }
        if(blank) puts("");
        blank = true;
        printf("%d\n",count);
    }
    return 0;
}
