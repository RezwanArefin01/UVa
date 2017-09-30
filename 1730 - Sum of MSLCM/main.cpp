#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

const int maxn = 20000001;
ll ans[maxn]; 

int main(int argc, char const *argv[]) {
	for(int i = 2; i < maxn; ++i) { 
		for(int j = i; j < maxn; j += i) 
			ans[j] += i;	
		ans[i] += ans[i - 1];
	} int n; 
	while(scanf("%d", &n) && n) {
		printf("%lld\n", ans[n] + n - 1);
	}
}