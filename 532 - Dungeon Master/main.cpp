#include<bits/stdc++.h>
using namespace std;
bool visited[100][100][100];
int level[100][100][100];
#define inf (2*100*100*10)
struct node{
    int x,y,z;
    node(){}
    node(int xx,int yy,int zz){x=xx;y=yy;z=zz;}
};
int X,Y,Z;
int dx[] = {0, 0,0, 0,1,-1};
int dy[] = {0, 0,1,-1,0, 0};
int dz[] = {1,-1,0, 0,0, 0};
#define valid(x,y,z) (x>=0 && x<X && y>=0 && y<Y && z>=0 && z<Z && !visited[x][y][z])
node src,des;
void BFS() {
    queue<node> Q;
    Q.push(src);
    level[src.x][src.y][src.z] = 0;
    while(!Q.empty()) {
        node top = Q.front(); Q.pop();
        int x=top.x,y=top.y,z=top.z;
        for(int i=0;i<6;i++) {
            int xx = x+dx[i];
            int yy = y+dy[i];
            int zz = z+dz[i];
            if(valid(xx,yy,zz)) {
                visited[xx][yy][zz] = true;
                level[xx][yy][zz] = level[x][y][z] +1;
                if(des.x==xx && des.y==y &&des.z==zz) return;
                Q.push(node(xx,yy,zz));
            }
        }
    }
}
int main () {
    while(cin>>X>>Y>>Z &&X&&Y&&Z){
        char ch;
        for(int i=0;i<X;i++){
            for(int j=0;j<Y;j++) {
                for(int k=0;k<Z;k++) {
                    cin>>ch;
                    level[i][j][k] = inf;
                    if(ch=='#') visited[i][j][k] = true;
                    if(ch=='.') visited[i][j][k] = false;
                    if(ch=='S') {src = node(i,j,k);visited[i][j][k] = true;}
                    if(ch=='E') {des = node(i,j,k);visited[i][j][k] = false;}
                }
            }
        }
        BFS();
        int ans = level[des.x][des.y][des.z];
        if(ans==inf) cout<<"Trapped!\n";
        else cout<<"Escaped in "<<ans<<" minute(s).\n";
    }
}
