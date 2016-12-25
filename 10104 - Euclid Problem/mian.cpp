#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Euclid {
    int x, y, d;
    Euclid() {}
    Euclid( int xx, int yy, int dd ) {
        x = xx, y = yy, d = dd;
    }
};
int gcd( ll a, ll b ) {
    return !b ? a : gcd ( b, a % b );
}
 Euclid egcd( ll a, ll b ) {
     if( !b ) return Euclid ( 1, 0, a );
     Euclid r = egcd ( b, a % b );
     return Euclid( r.y, r.x - a / b * r.y, r.d );
}
int main() {
    Euclid ans;
    ll a,b;
    while(cin>>a>>b) {
        ans = egcd(a,b);
        cout<<ans.x<<" " <<ans.y<<" "<<ans.d<<endl;
    }
    return 0;
}
