#include<bits/stdc++.h>
using namespace std;
#define inf 1/0.0
double lx[100],ly[100];
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
inline double dist(int a, int b){
    return sqrt( (lx[a] - lx[b])*(lx[a] - lx[b]) + (ly[a] - ly[b])*(ly[a] - ly[b]));
}
int main () {
    int n,co=0,t,c=0;
    double d[101][101],a,b;
    t=read();
    while(t--){
        n = read();
        for(int i=0;i<n;i++) {
            lx[i] = (double) read();
            ly[i] = (double) read();
        }
        for(int i=0;i < n;i++) {
            for(int j=0; j < n;j++) {
                if (i==j) d[i][j] = 0.0;
                else d[i][j] = dist(i,j);
                if (d[i][j] > 10.0) d[i][j] = inf;
            }
        }
        for(int k=0;k<n-1;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    d[i][j] = min(d[i][j] , d[i][k] + d[k][j]);
                }
            }
        }
        double ans = 0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                ans = max(ans,d[i][j]);

        printf("Case #%d:\n", ++co);
        if(isinf(ans))
            puts("Send Kurdy\n");
        else
            printf("%.4lf\n\n",ans);
    }
    return 0 ;
}
