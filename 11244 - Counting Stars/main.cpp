#include<bits/stdc++.h>
using namespace std;

int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {-1,0,1,-1,0,1,1,-1};

int main() {
    int r,c; while(cin>>r>>c && (r||c)) {
        string adj[r]; int ans = 0;
        for(int i=0; i<r; i++) cin>>adj[i];
        for(int i=0; i<r; i++) for(int j=0; j<c; j++){
            if(adj[i][j] == '*') { int cnt = 0;
                for(int k=0; k<8 && !cnt; k++) {
                    int x = i+dx[k], y = j + dy[k];
                    if(x >= 0 && y >= 0 && x < r && y < c) if(adj[x][y] == '*') cnt = 1;
                } if(!cnt) ans++;
            }
        } cout<<ans<<endl;
    }
}
