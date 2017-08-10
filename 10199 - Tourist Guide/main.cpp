#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> adj[111]; 
int cut[111], low[111], vis[111], now = 0, n, m; 

void dfs(int u, int par) {
    low[u] = vis[u] = ++now; int ch = 0; 
    for(int v : adj[u]) if(v - par) { 
        if(vis[v]) low[u] = min(low[u], vis[v]); 
        else { ch++;
            dfs(v, u); 
            low[u] = min(low[u], low[v]); 
            if(par + 1 && low[v] >= vis[u]) 
                cut[u] = 1;
        }
    } if(par == -1 && ch > 1) cut[u] = 1;
}

void ArticulationPoint() {
    memset(vis, 0, sizeof vis);
    memset(low, 0, sizeof low); 
    memset(cut, 0, sizeof cut); 
    now = 0; 
    for(int i = 0; i < n; i++) {
        if(!vis[i]) dfs(i, -1); 
    }
}
int main(int argc, char const *argv[]) {
    int co = 0, f = 0; while(cin >> n && n) {
        if(f) cout << endl; 
        f = 1;
        map<string, int> mp; 
        map<int, string> rev;
        for(int i = 0; i < n; i++) {
            adj[i].clear(); 
            string str; cin >> str;
            mp[str] = i;
            rev[i] = str; 
        }
        cin >> m; 
        while(m--) {
            string u, v; 
            cin >> u >> v;
            adj[mp[u]].push_back(mp[v]);
            adj[mp[v]].push_back(mp[u]); 
        }

        ArticulationPoint(); 

        vector<string> v; 
        for(int i = 0; i < n; i++) 
            if(cut[i]) v.push_back(rev[i]);

        printf("City map #%d: %d camera(s) found\n", ++co, v.size());
        sort(v.begin(), v.end());
        for(string x : v) {
            cout << x << endl;
        }
    }
}