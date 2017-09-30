#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

int main(int argc, char const *argv[]) {
	int t; scanf("%d", &t);
	while(t--) {
		double w, h, z, x, y, p;
		cin >> w >> h >> z >> x >> y >> p; 
		double a = atan2(x - w, y - h);
		double b = asin(sin(a) / p);
		double d = z - w + h * tan(a); 
		double ans = d / (tan(a) - tan(b));
		if(ans <= 0) ans = 0;
		if(ans > h) puts("Impossible");
		else printf("%.4f\n", ans);
	}
}