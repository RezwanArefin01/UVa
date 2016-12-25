#include<bits/stdc++.h>
using namespace std;

int dx[] = { -2, -2, -1, 1, 2, 2, 1, -1 };
int dy[] = { -1, 1, 2, 2, 1, -1, -2, -2 };

int main() {
    string a,b; while(cin>>a>>b) {
        pair<int,int> src = {a[0] - 'a', a[1] - '1'};
        pair<int,int> des = {b[0] - 'a', b[1] - '1'};
        map<pair<int,int>, int > vis, level;
        queue<pair<int,int> > Q; Q.push(src);
        level[src] = 0; vis[src] = 1;
        while(!Q.empty()) {
            pair<int,int> u = Q.front(); Q.pop();
            for(int i=0; i<8; i++){
                pair<int,int> v = {u.first + dx[i], u.second + dy[i]};
                if(v.first >= 0 && v.second >= 0 && v.first < 8 && v.second < 8 && !vis.count(v)) {
                    vis[v] = 1; level[v] = level[u] + 1; Q.push(v);
                }
            }
        } cout<<"To get from "<<a<<" to "<<b<<" takes "<<level[des] << " knight moves."<<endl;
    }
}
