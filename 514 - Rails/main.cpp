#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii; 

bool possible(int a[], int n) {
	stack<int> st; int idx = 1; 
	for(int i = 0; i < n; i++) {
		if(st.empty()) st.push(idx++);
		while(idx <= a[i] && st.top() != a[i]) 
			st.push(idx++); 
		if(st.top() != a[i]) return 0;
		st.pop();
	} return 1; 
}
int main(int argc, char const *argv[]) {
	int n; while(cin >> n && n) {
		int a[n];

		while(cin >> a[0] && a[0]) {
			for(int i = 1; i < n; i++) 
				cin >> a[i];

			if(possible(a, n)) 
				puts("Yes");
			else puts("No");
		} puts("");
	}
}