#include<bits/stdc++.h>
using namespace std;

string adj[36]; int r;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
inline bool isSafe(int row, int col) {
    return (row < r && col < adj[row].size() && row > 0 && col > 0 && adj[row][col] == ' ');
}
void floodfill(int row, int col) {
    if(!isSafe(row,col)) return;
    adj[row][col] = '#';
    for(int i=0; i<4; i++) floodfill(row + dx[i], col + dy[i]);
}
int main() {
    int t, row, col; cin>>t; getline(cin, adj[0]);while(t--) {
        bool go = true; r = 0;
        while(go) {
            getline(cin, adj[r]); go = false;
            for(int i=0; i<adj[r].size(); i++) {
                if(adj[r][i] != '_') {
                    go = true; if(adj[r][i] == '*') row = r, col = i;
                }
            } r++;
        }
        adj[row][col] = ' '; floodfill(row, col);
        for(int i=0; i<r; i++) puts(adj[i].c_str());
    }
}
