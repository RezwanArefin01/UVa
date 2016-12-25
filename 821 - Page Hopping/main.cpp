#include<bits/stdc++.h>
using namespace std;
int main() {
//    freopen("in.txt","r",stdin);
    int edge[105][105],co=0;
    int visited[105];
    int x,y;
    while(cin>>x>>y) {
        if (x==0 && y==0) break;
        memset(visited,0,sizeof (visited));
        for(int i=0;i<105;i++) {
            for(int j=0;j<105;j++) {
                if(i==j) edge[i][j] = 0;
                else edge[i][j] = 1000;
            }
        }
        edge[x][y] = 1;
        visited[x] = visited[y] = 1;
        while(cin>>x>>y ) {
            if(x==0 && y==0) break;
            edge[x][y] = 1;
            visited[x] = visited[y] = 1;
        }
        for(int k=0;k<105;k++) {
            for(int i=0;i<105;i++) {
                for(int j=0;j<105;j++) {
                    edge[i][j] = min(edge[i][j] , edge[i][k] + edge[k][j]);
                }
            }
        }
        double sum = 0;
        int div = 0;
        for(int i=0;i<105;i++) {
            for(int j=0;j<105;j++) {
                if(edge[i][j]!=1000) sum+=edge[i][j];
            }
            div+=visited[i];
        }
        printf("Case %d: average length between pages = %.3lf clicks\n",++co,sum/(div*(div-1)));
    }
    return 0;
}
