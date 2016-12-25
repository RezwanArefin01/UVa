#include<bits/stdc++.h>
using namespace std;
class Graph {
    int V;
    list<int> *adj;
    void DFSUtill(int s, bool visited[]);
public:
    Graph(int V);
    void addEdge(int u,int v) ;
    void DFS(int s);
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}
void Graph::DFSUtill(int s,bool visited[]) {
    list<int>::iterator i;
    for(i = adj[s].begin(); i!=adj[s].end();i++)
        if(!visited[*i]){
            visited[*i] = true;
            DFSUtill(*i,visited);
        }
}
void Graph::DFS(int s) {
    vector<int> ans;
    bool *visited = new bool[V];
    for(int i=0;i<V;i++) {
        visited[i] = false;
    }
    int count = 0;
    DFSUtill(s,visited);
    for(int i=0;i<V;i++)
        if(!visited[i]) {
            count++;
            ans.push_back(i+1);
        }
    cout<<count;
    for(int i=0;i<ans.size();i++)
        cout<<" " <<ans[i];
    cout<<endl;
}
int main() {
    int n,m,a,b;
    int q,s;
    while(cin>>n && n) {
        Graph g(n);
        while(cin>>a && a)
            while(cin>>b && b)
                g.addEdge(a-1,b-1);
        cin>>q;
        while(q--) {
            cin>>s;
            g.DFS(s-1);
        }
    }
}

