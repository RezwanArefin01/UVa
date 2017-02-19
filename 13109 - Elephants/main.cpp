#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
	int t; scanf("%d", &t); while(t--) {
		int n,M; scanf("%d %d", &n, &M); int arr[n];
		for(int i=0; i<n; i++) scanf("%d", &arr[i]);
		sort(arr, arr+n); int cnt = 0;
		while(cnt < n && arr[cnt] <= M) 
			M -= arr[cnt++];
		printf("%d\n", cnt);
	}
}