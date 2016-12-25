#include<bits/stdc++.h>
using namespace std;
int r,c; int adj[101][101];
int dp[101][101];
int dx[] = {1,0,0,-1};
int dy[] = {0,1,-1,0};
int dfs(int x, int y) {
    int &ret = dp[x][y];
    if(ret != -1) return ret; ret = 0;
    for(int i=0; i<4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if(xx >= 0 && yy >=0 && xx < r && yy < c && adj[xx][yy] < adj[x][y]) ret = max(ret, 1 + dfs(xx,yy));
    } return ret;
}
int main() {
    int t; cin>>t; while(t--) {
        string name; cin>>name>>r>>c;
        for(int i=0; i<r; i++) for(int j=0; j<c; j++) cin>>adj[i][j];
        int Ans = -1;
        for(int i=0; i<r; i++) for(int j=0; j<c; j++) {
            memset(dp, -1, sizeof dp);
            Ans = max(Ans, dfs(i,j));
        }
        cout<<name<<": "<<++Ans<<endl;
    }
}
