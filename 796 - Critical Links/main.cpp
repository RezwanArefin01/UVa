#include<bits/stdc++.h>
using namespace std;
#define NIL -1
struct node {
    int u,v;
    node(int _u,int _v) {
        u = min(_v,_u); v=max(_v,_u);
    }
    bool operator < (const node &X) const{
        if(u!=X.u) return u<X.u;
        return v<X.v;
    }
};
vector<node> br;
class Graph{
    int V;
    list<int> *adj;
    void bridgeUtil(int u, bool visited[], int disc[],
                                       int low[], int parent[]);
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void bridge();

};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int> [V];
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}
void Graph::bridgeUtil(int u, bool visited[], int disc[],
                                       int low[], int parent[])
{
    static int time = 0;

    visited[u] = true;
    disc[u] = low[u] = ++time;

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;

        if (!visited[v])
        {
            parent[v] = u;
            bridgeUtil(v, visited, disc, low, parent);
            low[u]  = min(low[u], low[v]);
            if (low[v] > disc[u]) {
                br.push_back(node(u,v));
            }
        }
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}

void Graph::bridge() {
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    for (int i = 0; i < V; i++)
    {
        parent[i] = NIL;
        visited[i] = false;
    }
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            bridgeUtil(i, visited, disc, low, parent);
}
int main(){
    int n,a,e,b,c;
    while(cin>>n) {
        Graph g(n+1);
        while(n--) {
                scanf("%d (%d)",&a,&e);
            for(int i=0;i<e;i++){
                cin>>b;
                g.addEdge(a,b);
            }
        }
        br.clear();
        g.bridge();
        sort(br.begin(),br.end());
        cout<<br.size()<<" critical links\n";
        for(int i=0;i<br.size();i++) {
            cout<<br[i].u<<" - "<<br[i].v<<endl;
        }
        cout<<endl;
    }

}
