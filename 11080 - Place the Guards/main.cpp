#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<vi> adj;
int color[210];
int t,v,e,a,b;
int co1, co2;
bool dfs(int u, int c) {
    color[u] = c;
    if(c > 0) co1++; else co2++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!color[v]) {
            if (!dfs(v, -c)) return false;
        } else if (color[v] == color[u]) return false;
    } return true;
}

int main() {
    cin>>t;
    while(t--) {
        cin>>v>>e;
        adj.clear(); adj.assign(v,vi());
        while(e--) {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 0;  memset(color, 0, sizeof color);
        co1 = co2 = 0;
        for(int i=0 ;i<v; i++) {
            if(color[i]) continue;
            if(dfs(i,1)) {
                ans += (co1 && co2 ) ?
						min(co1, co2):
						max(co1,co2);
                co1 = co2 = 0;
            } else {
                ans = -1; break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
