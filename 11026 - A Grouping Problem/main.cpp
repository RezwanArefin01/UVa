#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, mod, arr[1111];
long long C[1111][1111];
int main(int argc, char const *argv[]) {
	while(cin>>n>>mod && ( n || mod ) ) {
		for(int i=1; i<=n; i++) 
			cin>>arr[i];
		long long Max = 0;
		for(int i=0; i<=n; i++) 
			C[i][0] = 1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				C[i][j] = C[i-1][j] + C[i-1][j-1] * arr[i];
				C[i][j] %= mod;
			}
		}
		for(int i=1; i<=n; i++)
			Max = max(Max, C[n][i]);
		cout<<Max<<endl;
	}
}

