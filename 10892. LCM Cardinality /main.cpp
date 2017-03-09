#include <bits/stdc++.h>
using namespace std;
int lcm(int a, int b) {
	return (a / __gcd(a,b)) * b; 
} int n;
int main(int argc, char const *argv[]) {
	while(scanf("%d", &n) && n) {
		vector<int> d; 
		for(int i=1; i*i <= n; i++) 
			if(n%i == 0) {
				d.push_back(i); 
				if( i != n/i) d.push_back(n/i);
			}
		int ans = 0;
		for(int i=0; i<d.size(); i++) 
			for(int j=0; j<=i; j++) 
				if(lcm(d[i], d[j]) == n) 
					ans++;
		printf("%d %d\n", n, ans);
	}
}
 
