#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

const int maxn = 111;
struct Edmonds {
    int g[maxn][maxn], p[maxn], f;
    vector<int> adj[maxn];
    bitset<maxn> vis; 

    void clear() {
        memset(g, 0, sizeof g);
        for(int i = 0; i < maxn; i++)
            adj[i].clear();
    }
    void addEdge(int u, int v, int w) {
        g[u][v] += w;
        g[v][u] += w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void augment(int u, int s, int Min) {
        if(u == s) { f = Min; return; }
        if(p[u] == -1) return; 
        augment(p[u], s, min(g[p[u]][u], Min));
        g[p[u]][u] -= f; 
        g[u][p[u]] += f; 
    }
    int get(int s, int t) {
        int ret = 0; 
        while(true) { 
            memset(p,-1, sizeof p); 
            vis.reset(); vis[s] = 1; 
            queue<int> q; q.push(s);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                if(u == t) break; 
                for(int v : adj[u]) 
                    if(g[u][v] > 0 && !vis[v])
                        vis[v] = 1, q.push(v), p[v] = u;
            } f = 0; augment(t, s, 1e9);
            if(!f) break;
            ret += f;
        } return ret;
    }
} mf; 

int main(int argc, char const *argv[]) {
    int n, m, co = 0; while(cin >> n && n) {
        mf.clear(); int s, t, u, v, w; 
        cin >> s >> t >> m;
        while(m--) {
            cin >> u >> v >> w;
            mf.addEdge(u, v, w);
        }
        cout << "Network " << ++co << endl;
        cout << "The bandwidth is " << mf.get(s, t) << ".\n\n";
    }
}   