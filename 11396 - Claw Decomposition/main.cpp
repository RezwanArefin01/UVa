#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<vi> adj;
vector<int> color;
int n,a,b;

bool coloring(int u, int c) {
    color[u] = c;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!color[v]) {
            if (!coloring(v, -c)) return false;
        } else if (color[v] == color[u]) return false;
    } return true;
}

int main() {
    while (scanf("%d", &n) , n) {
        adj.clear(),color.clear(); adj.assign(n+1, vi());
        while (scanf("%d %d", &a, &b) && (a||b))
            adj[a].push_back(b), adj[b].push_back(a);
        color.assign(n+1, false);
        if (coloring(1, 1)) puts("YES");
        else puts("NO");
    }
    return 0;
}
