#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> ii;
#define pii pair<double ,ii >
vector<int> pr(1000);
void initset(int V) { pr.resize(V);for(int i=0;i<V;i++) pr[i] = i; }
int find(int a) {return pr[a]==a?a:find(pr[a]);}
#define Union(a,b) (pr[find(a)] = find(b))
#define isSameset(a,b) (find(a)==find(b))

int V,u,v,w;
inline double dist(double x1, double y1, double x2, double y2) {
    return hypot(x1-x2, y1-y2);
}
int main() {
    int T;
    cin>>T;
    while(T--) {
        cin>>V; vector<ii> p(V); double x,y;
        for(int i=0;i<V;i++) {
            cin>>x>>y;
            p[i] = ii(x,y);
        }
        priority_queue< pii > Q;
        for(int i=0; i<V; i++) for(int j=i+1; j<V;j++) {
            Q.push(make_pair(-dist(p[i].first,p[i].second, p[j].first, p[j].second), ii(i,j)));
        }
        double cost = 0; initset(V);
        while(!Q.empty()) {
            pii top = Q.top(); Q.pop();
            if(!isSameset(top.second.first,top.second.second))
                cost += -top.first, Union(top.second.first,top.second.second);
        }
        cout<<fixed<<setprecision(2)<<cost<<endl;
        if(T) puts("");
    }
}
