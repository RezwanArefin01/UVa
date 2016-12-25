#include<bits/stdc++.h>
using namespace std;

char grid[26][26];
int X;

int dx[] = {1,1,0,-1,-1,-1,0,1};
int dy[] = {0,1,1,1,0,-1,-1,-1};

void fill(int x, int y) {
    if(x<0 || x>=X || y < 0 || y >= X) return;
    if(grid[x][y] != '1') return;
    grid[x][y] = '2';
    for(int d=0; d<8; d++)
        fill(x+dx[d], y+dy[d]);
}
int no = 0;
int main() {
    while(cin>>X) {
        for(int i=0; i<X; i++) for(int j=0 ;j<X; j++) cin>>grid[i][j];
        int cc = 0;
        for(int i=0; i<X; i++)
            for(int j=0; j<X;j++)
                if(grid[i][j] == '1') fill(i,j), cc++;
        printf("Image number %d contains %d war eagles.\n", ++no, cc);
    }
}
