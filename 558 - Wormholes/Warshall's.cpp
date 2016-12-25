#include<bits/stdc++.h>
using namespace std;
int V,e,t;
int a,b,c;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define INF INT_MAX
vector<vii> AdjList;
#define REP(i, a, b) \
  for (int i = int(a); i <= int(b); i++)

#define TRvii(c, it) \
  for (vii::iterator it = (c).begin(); it != (c).end(); it++)
void reset(int n) {
    for(int i=0;i<n;i++)
        AdjList[i].clear();
}
int main() {
    cin>>t;
    while(t--) {
        cin>>V>>e;
        AdjList.clear();
        AdjList.assign(V,vii());
        while(e--) {
            cin>>a>>b>>c;
            AdjList[a].push_back(ii(b,c));
        }
        vector<int> dist(V, INF); dist[0] = 0; // INF = 2^31-1
        REP (i, 0, V - 2) // relax all E edges V-1 times, O(V)
            REP (u, 0, V - 1) // these two loops = O(E)
                TRvii (AdjList[u], v) // relax these edges
                    dist[v->first] = min(dist[v->first], dist[u] + v->second);

        bool negative_cycle = false;
        REP (u, 0, V - 1) // one more pass to check
            TRvii (AdjList[u], v)
                if (dist[v->first] > dist[u] + v->second) // should be false, but if possible
                    negative_cycle = true;            // then negative cycle exists!
        if(negative_cycle) puts("possible");
        else puts("not possible");
    }
}
