#include<bits/stdc++.h>
using namespace std;
int co =0 ;
int main() {
    double a,b,ratio, r,theta;
    while(scanf("%lf : %lf", &a, &b) == 2){
        theta = atan(b / a);
        r = b/2 * b/2 + a/2 * a/2;
        ratio = 400 / (2 * a + 4 * theta * sqrt(r));
        printf("Case %d: %.12f %.12f\n", ++co,a*ratio, b*ratio);
    }
}
