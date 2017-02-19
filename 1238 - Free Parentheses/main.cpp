#include <bits/stdc++.h>
using namespace std;
int n, num[31], sign[31]; string str;
bool dp[31][31][6001], used[6001];
int recurr(int idx, int open, int val) {
	if(dp[idx][open][val+3000]) return 0;
	if(idx == n) return used[val+3000] = 1; 
	dp[idx][open][val+3000] = 1;
	int next = val + num[idx] * sign[idx] * ((open&1)?-1:1);
	if(sign[idx] == -1) recurr(idx+1, open+1, next);
	if(open > 0) recurr(idx+1, open-1, next);
	recurr(idx+1, open, next);
}
int main(int argc, char const *argv[]) {
	while(getline(cin,str)) {
		n = 0;istringstream iss(str);
		iss>>num[n++]; char ch; sign[0] = 1;
		while(iss>>ch>>num[n]) {
			sign[n++] = (ch == '-')?-1:1;
		} memset(dp, 0, sizeof dp), memset(used, 0, sizeof used);
		recurr(0,0,0);
		cout<<accumulate(used, used + 6001, 0)<<endl;
	}
}