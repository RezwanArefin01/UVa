#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

ll OR(ll l, ll r) {
	if(l == r) return l;
	ll add = (l & 1) || (l != r);
	return (OR(l / 2, r / 2) << 1) + add; 
}
ll AND(ll l, ll r) {
	int suff = 0; 
	while(l != r) l >>= 1, r >>= 1, suff++;
	return l << suff; 
}
int main(int argc, char const *argv[]) {
	int t, co = 0; scanf("%d", &t); 
	while(t--) {
		ll l, r; scanf("%lld %lld", &l, &r);
		printf("Case %d: %lld %lld\n", ++co, OR(l, r), AND(l, r) );
	}
}