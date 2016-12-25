#include<bits/stdc++.h>
using namespace std;
int cost[1100][1100];
int level[1100][1100];
#define inf 20000000
int ROW,COL;
struct node {
    int x,y,cost;
    node(int a,int b,int c) { x = a; y = b; cost = c;}
    bool operator < (const node& p) const {
        return cost>p.cost;
    }
};
#define valid(x,y) (x>=0 && x<ROW && y>=0 && y<COL)

int dx[] = {1,-1,0 ,0};
int dy[] = {0, 0,1,-1};

void dijkstra() {
    priority_queue<node> Q;
    Q.push(node(0,0,0));
    level[0][0] = cost[0][0];
    while(!Q.empty()) {
        node top = Q.top();
        Q.pop();
        int x = top.x;
        int y = top.y;
        for(int i=0; i<4; i++) {
            int xx = x+dx[i];
            int yy = y+dy[i];
            if(valid(xx,yy)){
                if(level[x][y]+cost[xx][yy]<level[xx][yy]) {
                    level[xx][yy] = level[x][y]+cost[xx][yy];
                    Q.push(node(xx,yy,level[xx][yy]));
                }
            }
        }
    }
}
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
int main() {
    int t;
    t = read();
    while(t--) {
        ROW = read(); COL = read();
        for(int i=0;i<ROW;i++) for(int j=0;j<COL;j++) {
            cost[i][j] = read();
            level[i][j] = inf;
        }
        dijkstra();
        cout<<level[ROW-1][COL-1]<<endl;
    }
}
