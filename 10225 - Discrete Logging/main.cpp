#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

ll shanks(ll a, ll b, ll m) { 
	a %= m, b %= m; ll n = sqrt(m) + 1; 
	unordered_map<ll, ll> mp; 
	ll an = 1, base = 1, ans = -1;
	for(int i = 0; i < n; i++) an = (an * a) % m; 
	for(int i = 1; i <= n; i++) {
		base = (base * an) % m; 
		if(!mp.count(base)) 
			mp[base] = i;
	} base = b; 
	for(int j = 0; j <= n; j++) {
		if(mp.count(base)) {
			ll ret = mp[base] * n - j;
			if(ans == -1 || (ret < m && ans > ret)) ans = ret; 
		} base = (base * a) % m;
	} return ans;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL_TESTING
	freopen("in", "r", stdin);
#endif
	ll m, a, b;
	while(scanf("%lld %lld %lld", &m, &a, &b) == 3) {
		ll ans = shanks(a, b, m); 
		if(ans == -1) puts("no solution");
		else printf("%lld\n", ans);
	}
}