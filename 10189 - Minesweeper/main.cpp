#include<bits/stdc++.h>
using namespace std;

bool mine[110][110];
int ans[110][110],ROW,COL;

int dx[] = {0,0 ,1,-1,1,-1, 1,-1};
int dy[] = {1,-1,0, 0,1,-1,-1, 1};

#define valid(x,y) (x>=0 && x<ROW && y>=0 && y<COL && !mine[x][y])

bool blank = false;
int co = 0;
char ch;
int main() {
    while(cin>>ROW>>COL && (ROW||COL)){
        for(int i=0;i<ROW;i++) for(int j=0;j<COL;j++) {
            cin>>ch;
            if(ch=='*') mine[i][j] = true;
            else mine[i][j] = false;
            ans[i][j] = 0;
        }
        for(int i=0;i<ROW;i++) for(int j=0;j<COL;j++)
            if(mine[i][j]) {
                for(int k=0;k<8;k++) {
                    int xx = i+dx[k];
                    int yy = j+dy[k];
                    if(valid(xx,yy))
                        ans[xx][yy] += 1 ;
                }
            }
        if(blank) puts(""); blank = true;
        cout<<"Field #"<<++co<<":\n";
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++) {
                if(mine[i][j]) cout<<"*";
                else cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
}
