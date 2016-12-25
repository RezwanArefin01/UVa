#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define PI 2*acos(0.0)
double a,b,c,s,area_T,outer_r,inner_r,area_I,area_O;
int main()
{
    while(cin>>a>>b>>c)
    {
        s=(a+b+c)/2;
        area_T = sqrt(s*(s-a)*(s-b)*(s-c));
        inner_r = area_T/s;
        outer_r = a*b*c/(4*area_T);
        area_I = PI*inner_r*inner_r;
        area_O = PI*outer_r*outer_r;
        cout<<fixed<<setprecision(4)<<(double)area_O-area_T<<" "<<(double)area_T-area_I<<" "<<(double)area_I<<endl;
    }
    return 0;
}
