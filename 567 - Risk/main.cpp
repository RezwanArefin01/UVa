#include<bits/stdc++.h>
using namespace std;

vector<int> edges[21];
void BFS (int src, int node) {
    queue <int> Q;
    Q.push(src);
    int visited[21] = {0}, level[21];
    level[src] = 0;
    visited[src] =1;
    while(!Q.empty()) {
        int u = Q.front();
        for(int i=0;i<edges[u].size();i++) {
            int v = edges[u][i];
            if(!visited[v]) {
                visited[v] = 1;
                level [v] = level[u] +1;
                Q.push(v);
            }
        }
        Q.pop();
    }
    printf("%2d to %2d: %d\n",src,node,level[node]);
}
int main() {
    int node,src,ver,n,i=1,co=0;
    while(cin>>node) {
        for(int j=0;j<node;j++) {
            cin>>ver;
            edges[i].push_back(ver);
            edges[ver].push_back(i);
        }
        if(i==19) {
            cin>>n;
            cout<<"Test Set #"<<++co<<endl;
            for(int j=0;j<n;j++) {
                cin>>src>>node;
                BFS (src,node);
            }
            cout<<endl;
            i =0;
            for(int j=0;j<21;j++) {
                edges[j].clear();
            }
        }
        i++;
    }
    return 0;
}
