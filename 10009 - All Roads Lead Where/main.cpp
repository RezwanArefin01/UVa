#include<bits/stdc++.h>
using namespace std;
int read() {
    int n;
    char c = 0;
    while(c<33) c = getc(stdin);
        n = 0;
    while(c>33){
        n = n*10 + c - '0';
        c = getc(stdin);
    }
    return n;
}
map<string, vector<string> > edge; // use TYPE_NAME, vector<TYPE_NAME>
map<string,int> level;             // use TYPE_NAME, int
map<string, string> parent;          // use TYPE_NAME, TYPE_NAME
void BFS(string src) {
    queue <string> Q;
    Q.push(src);
    level[src] = 0;
    while(!Q.empty()) {
        string u = Q.front(); Q.pop();
        int s = edge[u].size();
        for(int i=0;i<s;i++) {
            string v = edge[u][i];
            if(!level.count(v)) {
                level[v] = level[u] +1;
                parent[v] = u;
                Q.push(v);
            }
        }
    }
}
void printpath (string src, string node ) {  // use TYPE_name
    vector<char > n;
    vector<char >::const_iterator itr;
    while(node!=src) {
        n.push_back(node[0]);
        node = parent[node];
    }
    n.push_back(src[0]);
    for(int i=n.size()-1;i>=0;i--) {
        cout<<n[i];
    }
    cout<<endl;
}
int main() {
    int t,n,m;
    string a,b;
    cin>>t;
    while(t--){
        edge.clear();
        cin>>n>>m;
        while(n--) {
            cin>>a>>b;
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        while(m--) {
            cin>>a>>b;
            level.clear();parent.clear();
            BFS(a);
            printpath(a,b);
        }
        if(t) cout<<endl;
    }
}
