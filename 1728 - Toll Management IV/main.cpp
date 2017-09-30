 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

const int maxn = 1e4 + 10;
int p[maxn][19], sub[maxn], n, L[maxn], lg;
vector<int> adj[maxn], cost[maxn];

int chainHead[maxn], chainNo[maxn],
    base[maxn], pos[maxn], ptr = 0, chain = 0; 


int tree[maxn<<2], lazy[maxn<<2], t2[maxn << 2];

void build(int node, int l, int r) {
	lazy[node] = t2[node] = 1e9;
	if(l == r) { tree[node] = base[l]; return; } 
	int mid = l + r >> 1;
	build(node<<1, l, mid);
	build(node<<1|1, mid+1, r);
	tree[node] = max(tree[node<<1], tree[node<<1|1]); 
}
void upd(int node, int l, int r, int v) {
	lazy[node] = min(lazy[node], v);
	t2[node] = min(t2[node], v);
}
void shift(int node, int l, int r) {
	if(lazy[node] == 1e9) return; 
	int mid = l + r >> 1;
	upd(node<<1, l, mid, lazy[node]);
	upd(node<<1|1, mid+1, r, lazy[node]);
	lazy[node] = 1e9;
}
void update(int node, int l, int r, int i, int j, ll v) {
	if(r < i || l > j) return;
	if(i <= l && r <= j) {
		upd(node, l, r, v);
		return;
	} shift(node, l, r);
	int mid = l + r >> 1;
	int left = node<<1, right = left|1;
	update(left, l, mid, i, j, v);
	update(right, mid+1, r, i, j, v);
	t2[node] = min(t2[node<<1], t2[node<<1|1]);
}
int query(int node, int l, int r, int i, int j) {
	if(r < i || l > j) return 0;
	if(i <= l && r <= j) {
		return tree[node]; 
	} int mid = l + r >> 1;
	int left = node<<1, right = left|1;
	return max(query(left, l, mid, i, j),
		   query(right, mid+1, r, i,j));
}

int query2(int node, int l, int r, int idx) {
	if(r < idx || l > idx) return 1e9;
	if(r == l) return t2[node];
	shift(node, l, r);
	int mid = l + r >> 1;
	if(idx <= mid) return query2(node << 1, l, mid, idx);
	else return query2(node << 1 | 1, mid+1, r, idx);
}

void clean() {
    for(int i=0; i<=n; i++) {
        adj[i].clear();
        cost[i].clear();
    }
    memset(sub, 0, sizeof sub);
    memset(L, 0, sizeof L);
    memset(p, -1, sizeof p);
    memset(chainHead, -1, sizeof chainHead);
    lg = 0, ptr = 0, chain = 0;
    while((1<<lg) <= n) lg++;
}
void dfs(int u, int par) {
    p[u][0] = par;
    if(par+1) L[u] = L[par]+1;
    for(int i=1; i<=lg; i++) 
        if(p[u][i-1] + 1) 
            p[u][i] = p[p[u][i-1]][i-1];
    sub[u] = 1;
    for(int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i]; 
        if(v == par) continue;
        dfs(v, u);
        sub[u] += sub[v];
    }
}
int lca(int u, int v) {
    if(L[u] < L[v]) swap(u, v);
    for(int i=lg; i >=0; i--) 
        if(p[u][i] + 1 && L[p[u][i]] >= L[v]) 
            u = p[u][i];
    if(u == v) return u;
    for(int i=lg; i>=0; i--) 
        if(p[u][i] - p[v][i]) 
            v = p[v][i], u = p[u][i];
    return p[u][0];
}
void hld(int u, int par, int c = 0) {
    if(chainHead[chain] == -1) 
        chainHead[chain] = u;
    chainNo[u] = chain;
    pos[u] = ptr;
    base[ptr++] = c;
    int Max = -1, sc = -1, ncost;
    for(int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i], w = cost[u][i];
        if(v == par) continue; 
        if(sub[v] > Max) {
            Max = sub[v];
            sc = v, 
            ncost = w;
        }
    }
    if(sc+1) hld(sc, u, ncost);
    for(int i=0; i<adj[u].size(); i++) {
        int v = adj[u][i], w = cost[u][i];
        if(v == par || v == sc) continue; 
        chain++; 
        hld(v, u, w);
    }
}   
int queryup(int u, int v) {
    if(u == v) return 0;
    int uch, vch = chainNo[v], ret = 0;
    while(1) { 
        uch = chainNo[u];
        if(uch == vch) {
            if(u == v) break; 
            ret = max(ret, query(1, 0, ptr-1, pos[v]+1, pos[u])); 
            break;
        } ret = max(ret, query(1, 0, ptr-1, pos[chainHead[uch]], pos[u]));
        u = chainHead[uch];
        u = p[u][0];
    } return ret;
}

void updateup(int u, int v, int w) {
    if(u == v) return;
    int uch, vch = chainNo[v];
    while(1) { 
        uch = chainNo[u];
        if(uch == vch) {
            if(u == v) break; 
            update(1, 0, ptr - 1, pos[v] + 1, pos[u], w);
            break;
        } 
        update(1, 0, ptr - 1, pos[chainHead[uch]], pos[u], w);
        u = chainHead[uch];
        u = p[u][0];
    } 
}
int query_hld(int u, int v) {
    int a = lca(u,v);
    return max(queryup(u, a), queryup(v, a));
}

void update_hld(int u, int v, int w) {
	int a = lca(u, v); 
	updateup(u, a, w);
	updateup(v, a, w);
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL_TESTING
	freopen("in", "r", stdin);
#endif
	int t, co = 0; scanf("%d", &t); while(t--) {
		int m; scanf("%d %d", &n, &m); 
		vector<pair<ii, int> > edges;
		
		ll ans = 0;
		clean(); 

		for(int i = 0; i < n - 1; i++) {
			int u, v, w; 
			scanf("%d %d %d", &u, &v, &w);
			adj[u].push_back(v);
			adj[v].push_back(u);
			cost[u].push_back(w);
			cost[v].push_back(w);
			edges.push_back({{u, v}, w});
		} 

		dfs(1, 0);
		hld(1, 0);
		build(1, 0, ptr-1);

		for(int i = n - 1; i < m; i++) {
			int u, v, w; 
			scanf("%d %d %d", &u, &v, &w);
			int mx = w - query_hld(u, v);
			ll idx = i + 1; 
			ans += idx * idx * mx - idx;

			update_hld(u, v, w);
		} 
		for(int i = 0; i < n - 1; i++) {
			int u = edges[i].first.first, v = edges[i].first.second; 
			int w = edges[i].second; 

			if(L[u] < L[v]) swap(u, v);

			int q = query2(1, 0, ptr-1, pos[u]);
			
			if(q == 1e9) q = -1; 
			else q = q - w;

			ll idx = i + 1;
			ans += idx * q - idx * idx;
		}
		printf("Case %d: %lld\n", ++co, ans);
	}

}