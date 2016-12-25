#include<bits/stdc++.h>
using namespace std;

struct node {
    int u,v,w;
    node(int __u,int __v,int __w) {
        u=__u; v=__v; w=__w;
    }
    bool operator <(const node &p) const {
        return w<p.w;
    }
};
vector<node> edge;
int n,m,u,v,w,total;
int pr[200100];
int f(int n) {
    return (pr[n]==n)? n: f(pr[n]);
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
int mst() {
    int s = 0,c = 0;
    sort(edge.begin(),edge.end());
    int len = edge.size();
    for(int i=0;i<len;i++) {
        int u = f(edge[i].u);
        int v = f(edge[i].v);
        if(u!=v) {
            pr[u] = v;
            c++;
            s+=edge[i].w;
            if(c==n-1) break;
        }
    }
    int ans = total-s;
    return ans;
}
int main(){
    while(1) {
        n =read();
        m = read();
        if(n==0 && m==0) break;
        edge.clear();
        total = 0;
        for(int i=0;i<m;i++) {
            pr[i] = i;
            u= read(); v = read(); w = read();
            total+=w;
            edge.push_back(node(u,v,w));
        }
        int ans = mst();
        printf("%d\n",ans);
    }
    return 0;
}
