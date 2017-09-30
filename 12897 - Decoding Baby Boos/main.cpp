#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

int main(int argc, char const *argv[]) {
	int t; cin >> t; while(t--) {
		string str; int q; 
		cin >> str >> q; 
		map<char, char> mp;
		for(char c = 'A'; c <= 'Z'; c++) mp[c] = c;
		mp['_'] = '_';

		while(q--) {
			char a, b; cin >> a >> b;
			for(char c = 'A'; c <= 'Z'; c++) 
				if(mp[c] == b) mp[c] = a;
		}

		for(int i = 0; i < str.size(); i++) 
			cout << mp[str[i]]; cout << endl;
	}
}