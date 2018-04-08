#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
using namespace std;

typedef long double ld; 
ld PI = acosl(-1);

struct base {
	ld a, b;
	base(ld _a = 0.0, ld _b = 0.0) : a(_a), b(_b) {}
	const base operator + (const base &c) const 
		{ return base(a + c.a, b + c.b); }
	const base operator - (const base &c) const
		{ return base(a - c.a, b - c.b); }
	const base operator * (const base &c) const
		{ return base(a * c.a - b * c.b, a * c.b + b * c.a); }
}; 

const int N = 1 << 19; 
base w[2][20][N]; 
int rev[N]; 

void calcw() { 	
	for(int d = 0; d < 2; ++d) {
		for(int i = 1; i <= 19; ++i) {
			int l = 1 << i; 
			ld ang = (d ? 2 : -2) * PI / l;
			base wn(cos(ang), sin(ang)); 
			w[d][i][0] = base(1, 0);
			for(int j = 1; j < (l >> 1); ++j) {
				w[d][i][j] = w[d][i][j - 1] * wn;
			}
		}
	} 
} 
void calcrev(int n) { int i = 0;
	for(int j = 1; j < n - 1; ++j) {
		for(int k = n >> 1; k > (i ^= k); k >>= 1);
		rev[j] = i; 
	} 
}
base p[N];
void fft(int n, int dir) {
	for(int i = 1; i < n - 1; i++) 
		if(i < rev[i]) swap(p[i], p[rev[i]]);
	int lg = 31 - __builtin_clz(n); 
	for(int i = 1; i <= lg; ++i) { int l = 1 << i; 
		for(int j = 0 ; j < n; j += l) {
			base t, *wn = w[dir][i]; 
			base *u = p + j, *v = u + (l >> 1), *e = v; 
			while(u != e) {
				t = *v * *wn;
				*v = *u - t; 
				*u = *u + t;
				++u, ++v, ++wn;
			}
		}
	} if(dir) for(int i = 0; i < n; ++i) p[i].a /= n, p[i].b /= n;
} 


int main(int argc, char const *argv[]) {
	calcw(); calcrev(N);
	int n, m, x;
	while(scanf("%d", &n) == 1) {
		p[0].a = 1;
		for(int i = 1; i < N; ++i) 
			p[i] = base(0, 0); 
		for(int i = 0; i < n; ++i) {
			scanf("%d", &x); p[x].a = 1;
		}
		fft(N, 0);
		for(int i = 0; i < N; ++i) 
			p[i] = p[i] * p[i];  
		fft(N, 1); 
		scanf("%d", &m); int ans = 0;
		for(int i = 0; i < m; ++i) {
			scanf("%d", &x);
			if(int(p[x].a + 0.5) > 0) ++ans;
		}
		printf("%d\n", ans);
	}
}