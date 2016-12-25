#include<bits/stdc++.h>
using namespace std;
#define gcd(a,b) __gcd(a,b)
struct point{
    long long x,y;
    point (){}
    point(long long xx,long long yy) {x=xx;y=yy;}
};
double areaPolygon(point P[], int n) {
    double area = 0;
    for( int i = 0, j = n - 1; i < n; j = i++ )
        area += P[j].x * P[i].y - P[j].y * P[i].x;
    return fabs(area)/2.0;
}

int main() {
    long long n;
    while(cin>>n && n) {
        point P[n];
        long long b = 0;
        cin>>P[0].x>>P[0].y;
        for(int i=1;i<n;i++) {
            cin>>P[i].x>>P[i].y;
            b += gcd(abs(P[i].x-P[i-1].x), abs(P[i].y-P[i-1].y));
        }
        b += gcd(abs(P[n-1].x - P[0].x), abs(P[n-1].y - P[0].y) );
        double area = areaPolygon(P,n);
        long long i = area + 1 - double(b)/2.0;
        cout<<i<<endl;
    }
}
