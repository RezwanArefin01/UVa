#include<bits/stdc++.h>
using namespace std;
int adj[101][101], n;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

int dfs(int x, int y) {
    if( x<0 || y<0 || x >=n || y >= n) return 0;
    int tmp = adj[x][y]; adj[x][y] = -1;
    int cnt = 1;
    for(int i=0; i<4; i++) {
        int xx = x+dx[i], yy = y + dy[i];
        if(tmp == adj[xx][yy]) cnt += dfs(xx,yy);
    } return cnt;
}
int main() {
    while(cin>>n && n) { cin.ignore();
        for(int i=0; i<n; i++) for(int j =0; j<n; j++) adj[i][j] = n;
        for(int i=1; i<n; i++) {
            string str; getline(cin,str);
            istringstream ss(str); int x,y;
            while(ss>>x>>y) adj[--x][--y] = i;
        } bool ok = true;
        for(int i=0; i<n && ok; i++)  for(int j=0; j<n && ok; j++)
                if(adj[i][j] != -1) if(dfs(i,j) != n) {ok = false; }
        puts(ok ? "good" : "wrong");
    }
}
