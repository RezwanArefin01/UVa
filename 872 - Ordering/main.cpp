#include <bits/stdc++.h>
using namespace std;
map<char, int> id;
map<int, char> rev;
int ans[27],n, before[27]; bool possible;

void dfs(int idx, int mask) {
	if(idx == n) {
		cout<<rev[ans[0]];
		for(int i=1; i<n; i++) 
			cout<<" " << rev[ans[i]];
		cout<<endl; possible = 1;
		return;
	} for(int i=0; i<n; i++) {
		if(!(mask & (1<<i)) && ((mask & before[i]) == before[i]) ) {
			ans[idx] = i;
			dfs(idx+1, mask | (1<<i));
		}
	}
}
int main(int argc, char const *argv[]) {
	int t; string str; cin>>t; 
	getline(cin, str); while(t--) {
		string str; getline(cin,str);
		getline(cin, str);  
		str.erase(remove(str.begin(), str.end(), ' ' ), str.end());
		sort(str.begin(), str.end());
		memset(before, 0, sizeof before);
		n = str.size();
		for(int i=0; i<n; i++) 
			id[str[i]] = i, rev[i] = str[i];
		getline(cin, str);
		for(int i=0; i<str.size(); i+=4) {
			int a = id[str[i]], b = id[str[i+2]];
			before[b] |= (1<<a);
		} possible = 0;
		dfs(0, 0);
		if(!possible) puts("NO");
		if(t) puts("");

	}
}
 
