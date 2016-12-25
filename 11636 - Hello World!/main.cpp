#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, cnt = 1;
	while (scanf("%d", &n), n >= 0) {
		cout<<"Case "<<cnt++<<": "<<max(0.0, ceil(log(n)/log(2)))<<endl;
	}

	return 0;
}
