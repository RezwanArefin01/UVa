#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

const int mod = 1e9 + 7;

int main(int argc, char const *argv[]) {
	int t, co = 0; scanf("%d", &t); 
	while(t--) {
		int n; scanf("%d", &n);
		vector<ii> v(n); 
		for(int i = 0; i < n; i++) 
			scanf("%d %d", &v[i].first, &v[i].second);
		sort(v.begin(), v.end());
		ll score = 0, way = 1, sf = 0;
		for(int i = 0; i < v.size(); i++) {
			sf += v[i].second; 
			score += v[i].second * sf;
			if(i + 1 < v.size()) 
				way = (way * (v[i].second + 1)) % mod;
		} printf("Case %d: %lld %lld\n", ++co, score, way);
	}
}