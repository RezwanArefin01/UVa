#include<bits/stdc++.h>
using namespace std;

vector<int> edges[200];
int level[200], dist1[200],dist2[200],dist3[200];
void BFS (int src) {
    queue <int> Q;
    Q.push(src);
    int visited[200] = {0};
    level[src] = 0;
    visited[src] =1;
    while(!Q.empty()) {
        int u = Q.front();
        for(int i=0;i<edges[u].size();i++) {
            int v = edges[u][i];
            if(!visited[v]) {
                visited[v] = 1;
                level [v] = level[u] +1;
                Q.push(v);
            }
        }
        Q.pop();
    }
}
int main() {
    int co =0, t,ed,a,b,node;
    cin>>t;
    while(t--) {
        cin>>node>>ed;
        for(int i=0;i<ed;i++) {
            cin>>a>>b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        cin>>a>>b;

        memset(level,0,sizeof level);
        BFS(a);
        for(int i=0;i<node;i++) dist1[i] = level[i];
        memset(level,0,sizeof(level));
        BFS(b);
        for(int i=0;i<node;i++) dist2[i] = level[i];
        for(int i=0;i<node;i++)
            dist3[i] = dist1[i] + dist2[i];
        sort(dist3,dist3+node);
        cout<<"Case "<<++co<<": "<<dist3[node-1]<<endl;
        for(int i=0;i<node;i++) edges[i].clear();
    }
    return 0;
}
