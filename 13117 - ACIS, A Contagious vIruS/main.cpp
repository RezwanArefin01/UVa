#include <bits/stdc++.h>
using namespace std;
struct point{ double x,y;};
inline double dist(point &a, point &b) { 
	return hypot(a.x-b.x, a.y-b.y);
}
inline double angle(point a, point o, point b) {
	double theta = atan2(a.y - o.y, a.x - o.x) - atan2(b.y - o.y, b.x - o.x);
	if(theta < 0) theta += 4*acos(0.0);
	return theta;
}
inline double DistToLine(point &a, point &b, point &p) {
	double u = (p.x - a.x) * (b.x - a.x) + (p.y - a.y) * (b.y - a.y);
	u /=  dist(a,b)*dist(a,b);
	point Int; 
	Int.x = a.x + u*(b.x - a.x);
	Int.y = a.y + u*(b.y - a.y);
	if(u < 0.0 || u > 1.0)
		return min(dist(a,p), dist(b,p));
	return dist(p,Int);
}
int main(int argc, char const *argv[]) {
	int n; while(cin>>n){ 
		double Min = 1e9; point o, p[n]; cin>>o.x>>o.y;
		for(int i=0; i<n; i++) 
			cin>>p[i].x>>p[i].y;
		for(int i=0; i < n; i++) 
			Min = min(Min, DistToLine(p[i],p[(i+1)%n],o));
		printf("%.3f\n", Min);

	}
}