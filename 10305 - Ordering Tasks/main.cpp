#include<iostream>
#include <list>
#include <stack>

using namespace std;
class Graph{
    int V; // No. of vertices'
    list<int> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void topologicalSort();

};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int> [V];
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    Stack.push(v);
}

void Graph::topologicalSort() {
    stack<int> Stack;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
    cout<<Stack.top()+1;
    Stack.pop();
    while (!Stack.empty()){
        cout <<" "<<Stack.top()+1;
        Stack.pop();
    }
    cout<<endl;
}

int main(){
    int n,m,a,b;
    while(cin>>n>>m ) {
        if(!n && !m) break;
        Graph g(n);
        for(int i=0;i<m;i++) {
            cin>>a>>b;
            g.addEdge(a-1,b-1);
        }
        g.topologicalSort();
    }
    return 0;

}
