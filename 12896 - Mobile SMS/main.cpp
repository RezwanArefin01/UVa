#include<bits/stdc++.h>
using namespace std;
#define II ( { int a ; read(a) ; a; } )
template< class T > inline bool read( T &x ) {
    int c = getchar() ;
    int sgn = 1;
    while( ~c && c < '0' || c > '9' ) {
        if( c == '-' )sgn = -1 ;
        c = getchar() ;
    }
    for( x = 0 ; ~c && '0' <= c && c <= '9' ; c = getchar() ) x = x * 10 + c - '0' ;
    x *= sgn ;
    return ~c ;
}
string a[15];
void gen(){
    a[0] = "0 ";
    a[1] = "0.,?";
    a[1] += '"';
    a[2] = "0abc";
    a[3] = "0def";
    a[4] = "0ghi";
    a[5] = "0jkl";
    a[6] = "0mno";
    a[7] = "0pqrs";
    a[8] = "0tuv";
    a[9] = "0wxyz";
}
int x[500] , y[500];
int main() {
    //freopen("ain.txt", "r", stdin);
    gen();
    int T = II ;
    while(T--){
        int n = II,i;
        for(i=0;i<n;i++) x[i] = II ;
        for(i=0;i<n;i++) y[i] = II ;
        for(i=0;i<n;i++) printf("%c",a[ x[i] ][ y[i] ]) ;
        puts("");
    }
}
