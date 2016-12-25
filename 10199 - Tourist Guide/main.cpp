#include<bits/stdc++.h>
using namespace std;
#define NIL -1
map<string,int> m;
int co =0;
bool blank = false;
class Graph{
    int V;
    list<int> *adj;
    void APUtil(int u, bool visited[], int disc[],
                int low[], int parent[], bool ap[]);
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void AP();
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int> [V];
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::APUtil(int u, bool visited[], int disc[],
                int low[], int parent[], bool ap[]) {
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;
        if (!visited[v])
        {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);

            low[u]  = min(low[u], low[v]);
            if (parent[u] == NIL && children > 1)
               ap[u] = true;
            if (parent[u] != NIL && low[v] >= disc[u])
               ap[u] = true;
        }
        else if (v != parent[u])
            low[u]  = min(low[u], disc[v]);
    }
}
string find(int i) {
    map<string,int>::iterator itr;
    for(itr = m.begin();itr!=m.end();++itr) {
        if(itr->second == i)
            return itr->first;
    }
}
void Graph::AP() {
    vector<string> br;
    bool *visited = new bool[V];
    int *disc = new int[V];
    int *low = new int[V];
    int *parent = new int[V];
    bool *ap = new bool[V];

    for (int i = 0; i < V; i++) {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);
    for (int i = 0; i < V; i++)
        if (ap[i] == true) {
            br.push_back(find(i));
        }
    if(blank) cout<<endl;
    blank = true;
    cout<<"City map #"<<++co<<": "<<br.size()<<" camera(s) found\n";
    sort(br.begin(),br.end());
    for(int i=0;i<br.size();i++)
        cout<<br[i]<<endl;
}
int main(){
    int n,r;
    string str,a,b;
    while(cin>>n && n) {
        m.erase(m.begin(),m.end());
        int tag = 0;
        Graph g(n);
        while(n--) {
            cin>>str;
            m[str] = tag++;
        }
        cin>>r;
        while(r--) {
            cin>>a>>b;
            g.addEdge(m[a],m[b]);
        }
        g.AP();
    }
    return 0;
}
