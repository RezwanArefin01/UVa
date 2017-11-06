#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9; // larger than Min Cut
const int maxn = 160;

int cost[maxn][maxn], w[maxn];
bool vis[maxn], merged[maxn]; 
vector<int> bestCut;

int MinCut(int n) {
	int best = inf; merged[0] = 1;
	for(int i = 1; i < n; i++) merged[i] = 0;
	// vector<int> cut; 
	for(int phase = 1; phase < n; ++phase) {
		vis[0] = 1; 
		for(int i = 1; i < n; ++i) if(!merged[i]) 
			vis[i] = 0, w[i] = cost[0][i];
		
		int prv = 0, nxt; 
		for(int i = n - 1 - phase; i >= 0; --i) {
			nxt = -1; 
			for(int j = 1; j < n; ++j) 
				if(!vis[j] && (nxt == -1 || w[j] > w[nxt])) 
					nxt = j;
			vis[nxt] = 1; 
			if(i) { prv = nxt;
				for(int j = 1; j < n; ++j) 
					if(!vis[j]) w[j] += cost[nxt][j];
			}
		} 
		for(int i = 0; i < n; i++) 
			cost[i][prv] = (cost[prv][i] += cost[nxt][i]);
		merged[nxt] = 1;
		// cut.push_back(nxt); 
		if(best > w[nxt]) {
			best = w[nxt];
			// bestCut = cut;
		}
	} return best;
}
int main(int argc, char const *argv[]) {
#ifdef LOCAL_TESTING
	freopen("in", "r", stdin);
#endif
	int t, co = 0; scanf("%d", &t); while(t--) {
		int n, m; scanf("%d %d", &n, &m);
		memset(cost, 0, sizeof cost); 
		for(int i = 0; i < m; i++) {
			int u, v, c; 
			scanf("%d %d %d", &u, &v, &c); 		
			--u, --v;
			cost[u][v] += c; cost[v][u] += c;
		} 
		printf("Case #%d: %d\n", ++co, MinCut(n)); 
	}
}