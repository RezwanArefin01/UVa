#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
typedef vector<int> vi;
vi p;
vector<vi> AdjList, res,Cap;
int V,E,u,v,w,s,t,mf,f;

void augment(int v, int minEdge) {
    if(v == s) {f = minEdge; return;}
    else if(p[v] != -1) {augment(p[v], min(res[p[v]][v], minEdge));
                         res[p[v]][v] -= f; res[v][p[v]] += f;}
}
void EdmodsKarps() {
    mf = 0;
    while(1) {
        bitset<52>vis; vis[s] = true; f = 0;
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
}

bitset<55> dfsv;
set<int> SSet;

void dfs(int u) {
	dfsv.set(u),SSet.insert(u);
	for (int i = 0; i < (int) AdjList[u].size(); i++) {
		int v = AdjList[u][i];
		if (!dfsv.test(v) && res[u][v] > 0) dfs(v);
	}
}
void MinCut() {
	SSet.clear();
	for (int i = 0; i < 55; i++) dfsv.reset(i);
	dfs(s);
	set<int>::iterator it;

	for (it = SSet.begin(); it != SSet.end(); it++) {
		int u = *it;
		for (int i = 0; i < (int) AdjList[u].size(); i++) {
			int v = AdjList[u][i];
			if (SSet.count(v))
				continue;
			if (res[u][v] <= 0) {
				printf("%d %d\n", u + 1, v + 1);
			}
		}
	}
	printf("\n");
}
int no = 0;
int main() {
    while(cin>>V>>E && (V||E)) {
        AdjList.clear(), res.clear(), Cap.clear(),p.clear();
        AdjList.assign(V, vi()); res.assign(V, vi(V,0)),Cap.assign(V, vi(V,0));
        s = 0, t = 1;
        while(E--) {
            cin>>u>>v>>w; --u,--v;
            res[u][v] += w, res[v][u] += w;
            AdjList[u].push_back(v), AdjList[v].push_back(u);
        }
        EdmodsKarps();
        MinCut();
    }
}
