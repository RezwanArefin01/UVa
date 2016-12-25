#include<bits/stdc++.h>
#include<vector>
using namespace std;

#define MAX 100000

int main() {
    int N,E,i,C,node;
    while(cin>>N>>E && N) {
        vector<int>edges[MAX];
        for(i=1;i<=E;i++) {
            int x,y;
            scanf("%d %d",&x,&y);
            edges[x].push_back(y);
            edges[y].push_back(x);
        }
        bool f = false;
        queue <int> Q;  Q.push(0);
        int color[MAX]; memset(color,-1,sizeof(color));
        color[0] = 0;
        while(!Q.empty()) {
            int u = Q.front();  Q.pop();
            int len = edges[u].size();
            for(int i=0;i<len;i++) {
                int v = edges[u][i];
                if (color[v]==-1) {
                    if(color[u]==0) color[v] =1;
                    else color[v] = 0;
                    Q.push(v);
                }
                else {
                    if(color[u]==color[v]) {
                        f=true; break;
                    }
                }
            }
            if(f) break;
        }
        if(f) cout<<"NOT BICOLORABLE."<<endl;
        else cout<<"BICOLORABLE."<<endl;
    }
return 0;
}


//6 13
//1 2
//2 4
//2 5
//5 1
//5 4
//5 3
//4 1
//3 6
//6 6
//6 4
//4 3
//3 1
//1 6

