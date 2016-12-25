#include<bits/stdc++.h>
using namespace std;
vector<int> edge[10100],cost[10100];
int d[10100];
#define MAX 10000000
void addEdge(int u, int v, int w) {
    edge[u].push_back(v);
    edge[v].push_back(u);
    cost[v].push_back(w);
    cost[u].push_back(w);
}
struct node{
    int u,w;
    node(){}
    node(int U,int W) {
        u =U;w=W;
    }
    bool operator < (const node &a) const {
        return w<a.w;
    }
};
void Dijkstra(int s,int n) {
    for(int i=0;i<n;i++) d[i] = MAX;
    priority_queue<node> Q;
    d[s] = 0;
    Q.push(node(s,0));
    while(!Q.empty()) {
        node top = Q.top();
        Q.pop();
        int u = top.u;
        for(int i=0;i<edge[u].size();i++) {
            int v = edge[u][i];
            if(d[u]+cost[u][i]<d[v]) {
                d[v] = d[u]+cost[u][i];
                Q.push(node(v,d[v]));
            }
        }
    }
}
void TreeDiameter(int n) {
    Dijkstra(0,n);
    int m = 0;
    int src,des;
    for(int i=0;i<n;i++) {
        if(d[i]>m) {
            src = i;
            m = d[i];
        }
    }
    Dijkstra(src,n);
    for(int i=0;i<n;i++) {
        if(d[i]>m) {
            des = i;
            m = d[i];
        }
    }
    cout<<m<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    string str;
    int m = 0,a,b,c;
    while(getline(cin,str,'\n')){
        if(str=="") {
            TreeDiameter(m+1);
            for(int i=0;i<=m+1;i++) {
                edge[i].clear();
                cost[i].clear();
            }
            m = -1;
        }
        else {
            istringstream iss(str);
            iss>>a>>b>>c;
            a--;b--;
            addEdge(a,b,c);
            m = max(m,max(a,b));
        }
    }
    TreeDiameter(m+1);
    return 0;
}
