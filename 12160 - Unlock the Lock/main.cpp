#include<bits/stdc++.h>
using namespace std;

int main() {
    int src,node,R,co=0;
    while(cin>>src>>node>>R ){
        int RB[100];
        int level[10000] = {0};
        if(!src && !node && !R) break;
        for(int i=0;i<R;i++) cin>>RB[i];
        queue <int> Q;
        Q.push(src);
        level[src] = 1;
        while(!Q.empty()) {
            if(level[node]) break;
            int u = Q.front();Q.pop();
            for(int i=0;i<R;i++) {
                int tmp = u+RB[i];
                if(tmp>=10000) tmp-=10000;
                if(level[tmp] == 0) {
                    level[tmp] = level[u] +1;
                    Q.push(tmp);
                }
            }
        }
        cout<<"Case "<<++co<<": ";
        if(level[node]) cout<<level[node] -1;
        else cout<<"Permanently Locked";
        cout<<endl;
    }
}
