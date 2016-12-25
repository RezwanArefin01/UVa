#include<bits/stdc++.h>
using namespace std;

int r,c,i,j;
int dx[] = {1,0,-1, 0,1,-1, 1,-1};
int dy[] = {0,1, 0,-1,1,-1,-1, 1};
char ch;
bool visited[111][111];
#define valid(x,y) (x>=0 && x<r && y>=0 && y<c && !visited [x][y])
void dfs(int x,int y) {
    visited[x][y] = true;
    for(int i=0;i<8;i++) {
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(valid(xx,yy)){
            dfs(xx,yy);
        }
    }
}
int main() {
    while(cin>>r>>c && (r||c)) {
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                cin>>ch;
                if(ch=='@') visited[i][j] = false;
                else visited[i][j]= true;
            }
        }
        int count = 0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                if(!visited[i][j]) {
                    count++;
                    dfs(i,j);
                }
            }
        }
        cout<<count<<endl;
    }
}
