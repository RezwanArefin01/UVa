#include<bits/stdc++.h>
using namespace std;
int J[500010],n;
int main() {
    J[1] = 1;
    J[2] = 2;int next = 2;
    for ( int i = 3; i <= 500000; i++ ) {
        if ( i < next ) next = 2;
        J[i] = next;
        next += 2;
    }
    while(scanf("%d",&n)&&n)
        printf("%d\n",J[n]);
    return 0;
}
