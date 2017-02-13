#include <bits/stdc++.h>
using namespace std;
struct point { double x,y,r;};
int main(int argc, char const *argv[]) {
	int t,co = 0; cin>>t; while(t--) {
		int n,m; cin>>n>>m;
		point a[n]; for(int i=0; i<n; i++) 
		 	cin>>a[i].x>>a[i].y>>a[i].r;
		cout<<"Case "<<++co<<":\n"; 
		while(m--) {
			point p; cin>>p.x>>p.y; bool f = 1; 
			for(int i=0; i<n && f; i++) 
				if(hypot(p.x - a[i].x, p.y - a[i].y) <= a[i].r) 
					f = 0, cout<<"Yes\n";
			if(f) cout<<"No\n"; 
		}
	}	
} 
