#include <bits/stdc++.h>
using namespace std;
map<int,vector<int> > edge;
map<int,int> level;
void BFS(int src) {
    queue <int> Q;
    Q.push(src);
    level[src] = 0;
    while(!Q.empty()) {
        int u = Q.front(); Q.pop();
        int s = edge[u].size();
        for(int i=0;i<s;i++) {
            int v = edge[u][i];
            if(!level.count(v)) {
                level[v] = level[u] +1;
                Q.push(v);
            }
        }
    }
}
int main() {
    int n,x,y,co=0;
    while(cin>>n && n) {
        edge.clear();
        for(int i=0;i<n;i++)  {
            cin>>x>>y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        int src,ttl;
        while(cin>>src>>ttl && (src||ttl)) {
            level.clear();
            BFS(src);
            int res = 0;
            for(map<int,int>::const_iterator it = level.begin();it!=level.end();++it) {
                if((*it).second>ttl) res++;
            }
            res += edge.size()-level.size();
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",++co,res,src,ttl);
        }
    }
}
