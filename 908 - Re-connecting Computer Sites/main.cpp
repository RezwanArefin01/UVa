#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> pii;

vector<int> pr(1000);
void initset(int V) { pr.resize(V);for(int i=0;i<V;i++) pr[i] = i;}
int find(int a) {return pr[a]==a?a:find(pr[a]);}
#define Union(a,b) (pr[find(a)] = find(b))
#define isSameset(a,b) (find(a)==find(b))


int u,v,w, V,E,total; bool t=false;
vector <pair<int,ii> > EdgeList;

int main() {
    while(cin>>V) {
        total = 0;
        if(t) puts(""); t= true;
        for(int i=0; i<V-1; i++) {
            cin>>u>>v>>w;
            total +=w;
        }
        cout<<total<<endl;
        priority_queue< pii > Q;
        int m;cin>>m;
        while(m--) {
            cin>>u>>v>>w;
            Q.push(make_pair(-w,make_pair(--u,--v)));
        }
        cin>>m;
        while(m--) {
            cin>>u>>v>>w;
            Q.push(make_pair(-w,make_pair(--u,--v)));
        }
        int cost = 0; initset(V);
        while(!Q.empty()) {
            pii top = Q.top(); Q.pop();
            if(!isSameset(top.second.first,top.second.second)) {
                cost += -top.first;
                Union(top.second.first,top.second.second);
            }
        }
        cout<<cost<<endl;
    }
}
