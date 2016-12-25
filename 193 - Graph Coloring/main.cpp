#include<bits/stdc++.h>
using namespace std;

int V,E;
vector<int> adj[101], Container, ans;
int color[101], Max;

void Clear() {
    for(int i=0; i<V; i++)
        adj[i].clear(), color[i] = 0;
}
void backtrack(int n) {
    if( n == V) {
        if(Container.size() > Max || Container.size() == Max && color[n-1] == 1)
            ans = Container, Max = Container.size();
        return;
    } int hasBlack = false;
    for(int i : adj[n])
        if(color[i] == 1) hasBlack = true;
    if(!hasBlack) {
        color[n] = 1; Container.push_back(n);
        backtrack(n+1);
        Container.pop_back();  color[n] = 0;
    } backtrack(n+1);
}
int main() {
    int t; cin>>t; while(t--) {
        cin>>V>>E; int u,v; Clear();
        while(E--) {
            cin>>u>>v; u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        } Max = 0; backtrack(0);
        cout<<ans.size()<<endl<<++ans[0];
        for(int i =1; i<ans.size(); i++) cout<<" " <<++ans[i];
        cout<<endl;
    }
}
