#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;

ll  phi ( ll  n ) {
	ll  i,res = n ;
	for (  i = 2 ; i * i <= n ; ++ i )
		if ( n % i == 0 ) {
			while ( n % i == 0 )
				n /= i ;
			res -= res / i ;
		}
	if ( n > 1 ) res -= res / n ;
	return res ;
}

int main(){
    ll n ;
    while(scanf("%lld",&n) && n ){
        if( n == 1 ) puts("0");
        else printf("%lld\n",phi(n));
    }
}
