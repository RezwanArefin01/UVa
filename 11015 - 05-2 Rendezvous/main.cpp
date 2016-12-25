#include<bits/stdc++.h>
using namespace std;
#define INF 23000
int co = 0;
int main() {
    int n,m;
    while(cin>>n>>m && (n||m)) {
        int edge[25][25] = {0},dist[25],x,y,c;
        for(int i=0;i<25;i++) {   //memset
            for(int j=0;j<25;j++) {
                edge[i][j] = INF;
            }
            edge[i][i] = 0;
        }
        map<int , string> names;
        string name;
        for(int i=1;i<=n;i++) {
            cin>>name;
            names[i] = name;
        }
        for(int i=1;i<=m;i++) {   //Graph Storing
            cin>>x>>y>>c;
            edge[x][y] = c;
            edge[y][x] = c;
        }
        for(int k=0;k<=n;k++) {    //Floyd
            for(int i=0;i<=n;i++) {
                for(int j=0;j<=n;j++) {
                    edge[i][j] = min(edge[i][j] , edge[i][k] + edge[k][j]);
                }
            }
        }
        int minDist = INF;
        for(int i=1;i<=n;i++){   //node with the smallest sum of distances to all the others
            int sum = 0;
            for(int j=1;j<=n;j++){
                if(edge[i][j]!=INF){
                    sum += edge[i][j];
                }
                else {
                    sum = INF;
                    break;
                }
            }
            minDist = min(minDist,sum);
            dist[i] = sum;
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==minDist) {
                cout<<"Case #"<<++co<<" : "<<names[i]<<endl;
                break;
            }
        }
    }
    return 0;
}

