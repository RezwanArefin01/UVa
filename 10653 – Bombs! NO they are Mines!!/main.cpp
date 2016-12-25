#include<bits/stdc++.h>
using namespace std;
struct node {
    int i,j;
    node(int x,int y) {
        i = x;
        j= y;
    }
};
inline void Scan_f(int &a)
{
    char c = 0;
    while(c<33) c = getc(stdin);
    a = 0;
    while(c>33){
        a = a*10 + c - '0';
        c = getc(stdin);
    }
}
int xx[]= {0,0,-1,1};
int yy[]= {1,-1,0,0};
bool flag[1003][1003];
int dist[1003][1003];

int main(){
    int r,c,line,num,in,l,sx,sy,fx,fy;
    while(1) {
        Scan_f(r);
        Scan_f(c);
        if(!r && !c) break;
        memset(flag,0,sizeof(flag));
        Scan_f(line);
        for(int i=0;i<line;i++) {
            Scan_f(num);
            Scan_f(in);
            for(int j=0;j<in;j++) {
                Scan_f(l);
                flag[num][l] = 1;
            }
        }
        queue<node> Q;
        int f = 0;
        Scan_f(sx);Scan_f(sy);
        Q.push(node(sx,sy));
        Scan_f(fx);Scan_f(fy);
        flag[sx][sy] = 1;
        dist[sx][sy] = 0;
        while(!Q.empty()) {
            node up = Q.front();
            int x = up.i;
            int y = up.j;
            for(int i=0;i<4;i++) {
                int mm = x+xx[i];
                int nn = y+yy[i];
                if(mm>=0 && mm<r && nn>=0 && nn<c && !flag[mm][nn]) {
                    Q.push(node(mm,nn));
                    flag[mm][nn] = 1;
                    dist[mm][nn] = dist[x][y]+1;
                    if(mm==fx && nn==fy)
                    {
                        f=1;
                        break;
                    }
                }
            }
            if(f==1) break;
            Q.pop();
        }
        printf("%d\n",dist[fx][fy]);
    }
    return 0;
}
