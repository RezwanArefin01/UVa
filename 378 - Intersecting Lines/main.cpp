#include<bits/stdc++.h>
using namespace std;
#define EPS 1e-9

struct point {
    double x,y;
    point(){}
    point(double _x, double _y): x(_x) , y(_y){}
};
struct line {
    double a,b,c;
    line(){}
    line(point p1, point p2) {
        if(fabs(p1.x - p2.x) < EPS) a = 1.0, b = 0.0, c = -p1.x;
        else {
            a = -(double) (p1.y - p2.y)/(p1.x - p2.x);
            b = 1.0;
            c = -(double)(a * p1.x) - p1.y;
        }
    }
};
bool areParallel(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}
bool areSame(line l1, line l2) {
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}
inline bool areIntersect( line L1, line L2, point &p ) {
    double det = L1.a * L2.b - L1.b * L2.a;
    if( fabs(det) < EPS ) return false;
    p.x = ( L1.b * L2.c - L2.b * L1.c ) / det;
    p.y = ( L1.c * L2.a - L2.c * L1.a ) / det;
    return true;
}
void read(point &p) {cin>>p.x>>p.y;}
int main() {
    int t;
    cin>>t;
    puts("INTERSECTING LINES OUTPUT");
    while(t--) {
        point p1,p2,p3,p4,in;
        read(p1);read(p2);read(p3);read(p4);
        line l1(p1,p2), l2(p3,p4);
        if(areSame(l1, l2)) puts("LINE");
        else if(areParallel(l1,l2)) puts("NONE");
        else {
            areIntersect(l1,l2,in);
            cout<<"POINT "<<fixed<<setprecision(2)<<in.x<<" " <<in.y<<endl;
        }
    }
    puts("END OF OUTPUT");
}

