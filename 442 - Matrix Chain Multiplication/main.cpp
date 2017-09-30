#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

ii d[27]; 

void solve(string s) {
	stack<ii> st; ll cost = 0;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '(') continue;
		if(s[i] != ')') { st.push(d[s[i] - 'A']); continue; }

		ii b = st.top(); st.pop();
		ii a = st.top(); st.pop();
		
		if(a.second != b.first) {
			puts("error"); return;
		}
		
		cost += (ll) a.first * a.second * b.second; 
		st.push({a.first, b.second});
	
	} cout << cost << endl;
}
int main(int argc, char const *argv[]) {
	int n; cin >> n; 
	for(int i = 0; i < n; i++) {
		char c; int x, y;
		cin >> c >> x >> y; 
		d[c - 'A'] = {x, y};
	} string str; 
	while(cin >> str) {
		solve(str); 
	}
}