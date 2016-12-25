#include<bits/stdc++.h>
using namespace std;

int row, col, cnt; string str;
vector<string> adj;
int dx[]={-1, 0, 1,1,1,0,-1,-1};
int dy[]={-1,-1,-1,0,1,1, 1, 0};

void dfs(int x, int y) {
    if(x < 0 || x >= row || y < 0 || y >= col || adj[x][y] != '1') return;
    cnt++; adj[x][y] = '0'; for(int i=0; i<8; i++) dfs(x+dx[i], y+dy[i]);
}
int main() {
    int t; scanf("%d\n\n", &t); while(t--) {
        adj.clear(); while(getline(cin,str) && str != "") adj.push_back(str);
        int res = 0; col = adj[0].size(); row = adj.size();
        for(int i=0; i<row; i++) for(int j=0;j<col; j++) {
            cnt = 0; dfs(i,j); res = max(res, cnt);
        }
        cout<<res<<endl; if(t) puts("");
    }
}
