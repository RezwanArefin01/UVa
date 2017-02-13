#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	int t,co = 0; cin>>t; while(t--) {
		int n,k,x; cin>>n>>k>>x;
		cout<<"Case "<<++co<<": " << n*(n+1)/2 - k*(2*x + k -1)/2<<endl;
	}	
} 
 
