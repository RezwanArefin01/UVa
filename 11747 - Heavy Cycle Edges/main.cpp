#include<bits/stdc++.h>
using namespace std;

struct node {
    int u,v,w;
    node(int d,int f,int g) {
        u=d;v=f;w=g;
    }
    bool operator < (node &p) const {
        return w<p.w;
    }
};
vector<node> edge;
vector<int> out;
int pr[1100];
int find(int n) {
    return (pr[n]==n)?n:find(pr[n]);
}
void mst(int n) {
    for(int i=0;i<=n;i++)
        pr[i] = i;
    sort(edge.begin(),edge.end());
    for(int i=0;i<edge.size();i++) {
        int u = find(edge[i].u);
        int v = find(edge[i].v);
        if(u!=v) {
            if(u>v) pr[v] = u;
            else pr[u] = v;
        }
        else {
            out.push_back(edge[i].w);
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
    int n,m,a,b,c;
    while(1) {
        n = read();
        m = read();
        if(!n && !m ) break;
        edge.clear(); out.clear();
        while(m--) {
            a =read();b = read();c=read();
            edge.push_back(node(a,b,c));
        }
        mst(n);
        if(out.size()==0) {
            puts("forest");
        }
        else {
            sort(out.begin(),out.end());
            printf("%d",out[0]);
            int len = out.size();
            for(int i=1;i<len;i++) {
                printf(" %d",out[i]);
            }
            puts("");
        }
    }
    return 0;
}
