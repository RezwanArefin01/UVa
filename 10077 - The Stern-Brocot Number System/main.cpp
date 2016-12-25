#include<bits/stdc++.h>
using namespace std;

string find ( int x, int y, int a = 0 , int b = 1 , int c = 1 , int d = 0 ) {
    int m = a+c,  n = b+d ;
    if ( x==m && y==n )
        return "" ;
    if ( x*n < y*m )
        return 'L' + find ( x,y,a,b,m,n ) ;
    else
        return 'R' + find ( x,y,m,n,c,d ) ;
}
int a,b;
int main() {
    while(cin>>a>>b) {
        if(a==1 && b==1) return 0;
        cout<<find(a,b)<<endl;
    }
}
