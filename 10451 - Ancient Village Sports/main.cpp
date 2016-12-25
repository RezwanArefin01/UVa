#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
#define PI 2*acos(0.0)
double n,area,rin,rout,pi,rinsqure;
int main()
{
    int t = 1;
    pi =2*acos(0);
    while(1){
        scanf("%lf%lf",&n,&area);
        if(n<3)break;
        rinsqure =area/(n*tan(pi/n));
        rin =sqrt(rinsqure);
        rout = rin /cos(pi/n);
        printf("Case %d: %.5lf %.5lf\n",t,(pi*rout*rout-area),(area-pi*rin*rin));
        t++;
    }
    return 0;
}
