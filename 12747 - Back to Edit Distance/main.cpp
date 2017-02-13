#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	int t,co = 0; cin>>t; while(t--) {
		int n,pos; cin>>n; vector<int> a(n+1), b(n+1); 
		for(int i=0; i<n; i++) 
			cin>>pos, a[pos] = i; 
		for(int i=0; i<n; i++) 
			cin>>pos, b[i] = a[pos];
		vector<int> tmp(n+1, 100000000); 
		for(int i=0; i<=n; i++) 
			*lower_bound(tmp.begin(), tmp.end(), b[i]) = b[i];
		for(int i=0; i<=n; i++) if(tmp[i] == 100000000) {
			cout<<"Case "<<++co<<": "<<2*(n-i)<<endl; break;
		}
	}	
} 
