#include<bits/stdc++.h>
#define max 15
using namespace std;
vector<int>edge[max];
vector<int>cost[max];
int parent[max];
int level[max];

struct node {
    int n,cost;
    node(int a,int b) { n = a; cost = b;}
    bool operator < (const node& p) const {
        return cost>p.cost;
    }
};
void Dijkstra(int start,int n) {
    int i,j,u,v;
    memset(level,63,sizeof level);
    priority_queue<node>Q;
    Q.push(node(start,0));
    level[start] = 0;
    while(!Q.empty()) {
        node top = Q.top();
        Q.pop();
        u = top.n;
        for(i=0; i<edge[u].size(); i++){
            v = edge[u][i];
            if(level[u]+cost[u][i]<level[v]) {
                level[v] = level[u]+cost[u][i];
                parent[v] = u;
                Q.push(node(v,level[v]));
            }
        }
    }
}
void reset() {
    for(int i=0;i<=15;i++) {
        edge[i].clear();
        cost[i].clear();
    }
}
void printpath(int src, int node) {
    vector<int> n;
    while(node!=src) {
        n.push_back(node);
        node = parent[node];
    }
    n.push_back(src);
    int len = n.size()-1;
    for(int i=len;i>=0;i--) cout<<" "<< n[i];
}
int main()
{
    int n,a,b,cas,co=0;
    while(cin>>cas && cas)
    {
        for(int i=1;i<=cas;i++) {
            cin>>n;
            for(int j=0;j<n;j++) {
                cin>>a>>b;
                edge[i].push_back(a);
                cost[i].push_back(b);
            }
        }
        cin>>a>>b;
        Dijkstra(a,b);
        cout<<"Case "<<++co<<": Path =";
        printpath(a,b);
        cout<<"; "<<level[b]<<" second delay"<<endl;
        memset(level,0,sizeof(level));
        for(int l =0; l<max; l++)
        {
            edge[l].clear();
            cost[l].clear();
        }
    }
    return 0;


}
