#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

int main(int argc, char const *argv[]) {
	int t, co = 0; cin >> t; while(t--) {
		string s; cin >> s; 
		vector<int> cnt(26, 0); int ans = 1e6;
		for(char c : s) cnt[c - 'a']++;
		for(int a : cnt) ans = min(ans, a);
		cout << "Case " << ++co << ": " << ans << endl;
	}
}