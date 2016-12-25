#include<bits/stdc++.h>
using namespace std;
vector<string> adj;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void dfs(int x, int y) {
    for(int i=0; i<4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if(adj[xx][yy] && adj[xx][yy] != 'X' && adj[xx][yy] != adj[x][y])
            adj[xx][yy] = adj[x][y], dfs(xx,yy);
    }
}
int main() {
    string str; while(getline(cin, str)) {
        adj.clear(); adj.push_back(str); string last;
        while(getline(cin, str) && str[0] != '_') adj.push_back(str);
        last = str;
        for(int i=0; i<adj.size(); i++)
            for(int j=0; j<adj[i].size(); j++)
                if(adj[i][j] != 'X' && adj[i][j] != ' ') dfs(i,j);
        for(int i=0; i<adj.size(); i++) cout<<adj[i]<<endl;
        cout<<last<<endl;
    }
}
