#include <bits/stdc++.h>
using namespace std;
int BIT[100010]; 
void update(int x, int val) {
	for(; x<=100000; x += (x&-x)) 
		BIT[x] += val;
} int read( int x) { 
	int sum = 0;
	while(x) {sum += BIT[x]; x -= (x&-x);}
	return sum;
}
int main(int argc, char const *argv[]) {
	int n; while(cin>>n && n) {
		memset(BIT, 0, sizeof BIT); 
		for(int i=0; i<n; i++) {
			string str; int a,b,y; cin>>str; if(str[0] == 'B') {
				cin>>a>>b>>y; 
				update(a,y); update(b+1, -y); 
			} else {
				cin>>a; cout<<read(a)<<endl; 
			}
		}
	}
}