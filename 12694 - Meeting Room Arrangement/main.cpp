#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, L, R; cin>>t; while(t--) {
		vector< pair<int, int> > M;
		while(cin>>L>>R && (L || R)) M.push_back({R,L});
		sort(M.begin(), M.end());
		int ret = 0; L = 0;
		for(auto i : M) if(L <= i.second) L = i.first, ret++;
		printf("%d\n", ret);
	}
	return 0;
}
