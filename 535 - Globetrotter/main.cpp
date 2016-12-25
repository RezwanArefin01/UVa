#include<bits/stdc++.h>
using namespace std;
#define rad (3.141592653589793/180.0)
#define R 6378

struct point{
    double Lat, Long;
};
double haversine(double x) {return (1-cos(x))/2.0;}
double gcDist(point p, point q) {
    p.Lat *= rad, p.Long *= rad;
    q.Lat *= rad, q.Long *= rad;

    double a = haversine(q.Lat - p.Lat);
    double b = cos(p.Lat) * cos(q.Lat) * haversine(q.Long - p.Long);
    double c = 2*atan2(sqrt(a +b) , sqrt(1-a-b));
    return R*c;
}
int main() {
    map<string,point> m;
    string city; double x,y;
    while(cin>>city && city != "#") {
        cin>>x>>y;
        m[city] = {x,y};
    }
    string u,v;
    while(cin>>u>>v && u!="#" && v!="#") {
        cout<<u<<" - "<<v<<endl;
        if(m.find(u) == m.end() || m.find(v) == m.end()) {
            puts("Unknown"); continue;
        }
        double ans = gcDist(m[u], m[v]) + 0.5;
        cout<<(int)ans<<" km\n";
    }
}
