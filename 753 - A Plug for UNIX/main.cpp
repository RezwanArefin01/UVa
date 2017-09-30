 #include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

const int maxn = 505;
struct Edmonds {
	struct edge { int u, v, cap, flow; };
	vector<edge> E; 
	vector<int> adj[maxn]; 
	int vis[maxn], par[maxn], Min[maxn]; 

	void clear() {
		E.clear();
		for(int i = 0; i < maxn; i++) 
			adj[i].clear();
	}
	
	void addEdge(int u, int v, int w) {
		E.push_back({u, v, w, 0});
		E.push_back({v, u, 0, 0});
		int sz = E.size(); 
		adj[u].push_back(sz - 2);
		adj[v].push_back(sz - 1);
	}
	int get(int s, int t) {
		int flow = 0;
		while(1) {
			memset(vis, 0, sizeof vis);
			memset(Min, 0, sizeof Min);
			queue<int> q; q.push(s); 
			Min[s] = 1e9, vis[s] = 1;
			while(!q.empty()) {
				int u = q.front(); q.pop();
				if(u == t) break; 
				for(int idx : adj[u]) {
					edge e = E[idx]; int v = e.v;
					if(!vis[v] && e.cap > e.flow) {
						Min[v] = min(Min[u], e.cap - e.flow); 
						par[v] = idx; 
						q.push(v); 
						vis[v] = 1;
					}
				} 
			} if(Min[t] == 0) break;
			for(int u = t; u != s; u = E[par[u]].u) {
				E[par[u]].flow += Min[t]; 
				E[par[u] + 1].flow -= Min[t]; 
			} flow += Min[t];
		} return flow; 
	}
} mf; 

int main(int argc, char const *argv[]) {
#ifdef LOCAL_TESTING
    freopen("in", "r", stdin);
#endif
    int n, m, k, t, co = 0; 
    cin >> t; while(t--) {
        mf.clear(); int idx = 2; 
        map<string, int> mp;
        map<int, int> cnt; 
        cin >> n; 
        for(int i = 0; i < n; i++) {
            string x; cin >> x; 
            if(!mp.count(x)) 
            	mp[x] = idx++;
        	cnt[mp[x]]++;
        } 
        for(auto it : cnt) 
        	mf.addEdge(it.first, 1, it.second);
        cin >> m;
        for(int i = 0; i < m; i++) {
            string x, y; cin >> x >> y; 
            if(!mp.count(x)) mp[x] = idx++;
            if(!mp.count(y)) mp[y] = idx++; 
            mf.addEdge(0, mp[x], 1);
            mf.addEdge(mp[x], mp[y], 1); 
        } cin >> k;
        for(int i = 0; i < k; i++) {
            string x, y; cin >> x >> y; 
            if(!mp.count(x)) mp[x] = idx++;
            if(!mp.count(y)) mp[y] = idx++; 
            mf.addEdge(mp[x], mp[y], 111); 
        } cout << m - mf.get(0, 1) << endl;
        if(t) puts("");
    }
}