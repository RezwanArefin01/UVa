#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	int t,co = 0; cin>>t; while(t--) {
		int n,cnt = 0; cin>>n; 
		vector<int> g(n*n); vector<bool> vis(n*n,false);
		for(int &i : g) cin>>i; 
		for(int i=0; i<n*n; i++) {
			if(vis[i]==0 && g[i] != i) {
				int j =i; while(!vis[j]) 
					{vis[j] = 1; cnt++; j = g[j];}
				if(i) cnt++;
			} 
		} if(g[0] != 0) cnt--;
		cout<<"Case "<<++co<<": "<<cnt<<endl;
	}	
} 	