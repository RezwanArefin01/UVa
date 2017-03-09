#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
bool mark[MAXN+10];
vector<int> prime; 
void sieve() {
	memset(mark, 1, sizeof mark);
	mark[0] = mark[1] = 0;
	for(int i=3; i*i<=MAXN; i+=2) if(mark[i]) 
		for(int j=i*i; j<=MAXN; j+=i+i) mark[j] = 0;
	prime.push_back(2);
	for(int i=3; i<=MAXN; i+=2) if(mark[i]) 
		prime.push_back(i);
}
int main(int argc, char const *argv[]) {
	sieve(); 
	int ans[MAXN]; ans[0] = ans[1] = 0;
	for(int n=2; n<=MAXN; n++) {
		ans[n] = ans[n-1]; int idx = 0, num =n;
		while(prime[idx] * prime[idx] <= num && num != 1) {
			while(num % prime[idx] == 0) ans[n]++, num/=prime[idx];
			idx++;
		} if(num != 1) ans[n]++;
	} 
	int n; while(scanf("%d", &n) == 1) {
		printf("%d\n", ans[n]);
	}
}
