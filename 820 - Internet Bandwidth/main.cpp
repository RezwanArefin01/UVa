#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
typedef vector<int> vi;
vi p;
vector<vi> AdjList, res;
int V,E,u,v,w,s,t,mf,f;

void augment(int v, int minEdge) {
    if(v == s) {f = minEdge; return;}
    else if(p[v] != -1) {augment(p[v], min(res[p[v]][v], minEdge));
                         res[p[v]][v] -= f; res[v][p[v]] += f;}
}
int no = 0;
int main() {
    while(cin>>V && V) {
        AdjList.clear(), res.clear(),p.clear();
        AdjList.assign(V, vi()); res.assign(V, vi(V,0));
        cin>>s>>t>>E;
        --s,--t;
        while(E--) {
            cin>>u>>v>>w; --u,--v;
            res[u][v] += w, res[v][u] += w;
            AdjList[u].push_back(v), AdjList[v].push_back(u);
        }
        mf = 0;
        while(1) {
            bitset<101>vis; vis[s] = true; f = 0;
            queue<int> Q; Q.push(s);
            p.assign(V, -1);
            while(!Q.empty()) {
                u = Q.front(); Q.pop();
                if(u == t) break;
                for(int i=0; i<(int) AdjList[u].size(); i++) {
                    v = AdjList[u][i];
                    if(res[u][v] > 0 && ! vis[v])
                        vis[v] = true, Q.push(v), p[v] = u;
                }
            }
            augment(t,INF);
            if(f == 0) break;
            mf+=f;
        }
        cout<<"Network "<<++no<<endl;
        cout<<"The bandwidth is "<<mf<<".\n\n";
    }
}
