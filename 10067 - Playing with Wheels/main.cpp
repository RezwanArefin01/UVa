#include<bits/stdc++.h>
using namespace std;
#define m INT_MIN
int po[] = {1,10,100,1000};
bool visited[10010];
int level[10010];
int src,des,n;
int read() {
    int res=0,num;
    for(int i=3;i>=0;i--) {
        cin>>num;
        res+=num*po[i];
    }
    return res;
}
int bfs() {
    memset (level,-1,sizeof level);
    queue<int> Q;
    visited[src] = true;
    Q.push(src);
    level[src] = 0;
    while(!Q.empty()) {
        int u = Q.front();  Q.pop();
        int p = u;
        int v;
        for(int i=0;i<4;i++ ){
            int d = po[i];
            if(p%10==9) v = u-(d*9);
            else v = u+d;
            if(!visited[v] && level[v]==-1) {
                Q.push(v);
                visited[v] = true;
                level[v] = level[u]+1;
                if(v==des) return level[v];
            }
            if(p%10==0) v = u+(d*9);
            else v = u-d;
            if(!visited[v] && level[v]==-1){
                Q.push(v);
                visited[v] = true;
                level[v] = level[u]+1;
                if(v==des) return level[v];
            }
            p/=10;
        }
    }
    return -1;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        memset(visited,false,sizeof visited);
        src = read();
        des = read();
        cin>>n;
        while(n--) {
            int f = read();
            visited[f] = true;
        }
        if(src==des){
            cout<<"0\n";
            continue;
        }
        else cout<<bfs()<<'\n';
    }
}
