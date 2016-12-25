#include<bits/stdc++.h>
using namespace std;
int main() {
    int a,b; while(cin>>a>>b) {
        if(a == b) { puts("0"); continue; }
        int level[10000]; memset(level, 0, sizeof level);
        bool visited[10000]; memset(visited, 0, sizeof visited);
        queue<int> Q; Q.push(a); level[a] = 0; visited[a] = 1;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            int v = (u+1) % 10000;
            if(!visited[v]) visited[v] = 1, Q.push(v), level[v] = level[u] + 1;
            if(v == b) break;
            v = (u*2) % 10000;
            if(!visited[v]) visited[v] = 1, Q.push(v), level[v] = level[u] + 1;
            if(v == b) break;
            v = u/3;
            if(!visited[v]) visited[v] = 1, Q.push(v), level[v] = level[u] + 1;
            if(v == b) break;
        }
        cout<<level[b]<<endl;
    }
}
