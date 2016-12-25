#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
int edge[105][105]={0};
void init(int c) {
    for(int i=0;i<=c;i++) {   //memset
        for(int j=0;j<=c;j++) {
            edge[i][j] = inf;
        }
    }
}
int c,l,q,n,a,b,cost,co=0;
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
//    freopen("in.txt","r",stdin);
    bool flag = false;
    while(1) {
        c = read(); l= read(); q=read();
        if(!c && !l && !q) break;
        init(c);
        for(int i=0;i<l;i++) {
            a = read(); b= read(); cost = read();
            edge[a][b] = edge[b][a] = cost;
        }

        for(int k=1;k<=c;k++) {    //Floyd
            for(int i=1;i<=c;i++) {
                for(int j=1;j<=c;j++) {
                    edge[i][j] = min(edge[i][j] , max(edge[i][k] , edge[k][j]));
                }
            }
        }
        if(flag) puts("");
        flag = true;
        printf("Case #%d\n",++co);
        for(int i=0;i<q;i++) {
            a = read(), b=read();
            if(edge[a][b]==inf) puts("no path");
            else printf("%d\n",edge[a][b]);
        }
    }
}
