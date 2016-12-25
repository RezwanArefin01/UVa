#include<bits/stdc++.h>
using namespace std;
struct data{
    char ch; int rank;
    bool operator < (data & d) {
        return rank > d.rank?1: rank == d.rank? ch < d.ch : 0;
    }
};
int R,C;
char adj[505][505];

int dx[]={0, 0, 1,-1};
int dy[]={1,-1, 0, 0};

void dfs(int x, int y) {
    if(x < 0 || x >= R || y < 0 || y >= C || adj[x][y] == '_') return;
    char tmp = adj[x][y];
    adj[x][y] = '_';
    for(int i=0; i<4; i++) {
        int xx = x+dx[i], yy = y + dy[i];
        if(tmp == adj[xx][yy]) dfs(xx,yy);
    }
}
int main() {
    int t, co=0; cin>>t; while(t--) {
        cin>>R>>C;
        for(int i=0; i < R; i++) for(int j=0; j < C; j++) cin>>adj[i][j];
        map<char, int> m;
        for(int i=0; i<R; i++) for(int j=0; j<C; j++) {
            if(adj[i][j] != '_') m[adj[i][j]]++, dfs(i,j);
        } vector<data> v;
        cout<<"World #"<<++co<<endl;
        for(map<char,int> :: iterator it = m.begin(); it != m.end(); it++)
            v.push_back({it->first,it->second});
        sort(v.begin(), v.end());
        for(auto n : v) cout<<n.ch<<": "<<n.rank<<endl;
    }
}
