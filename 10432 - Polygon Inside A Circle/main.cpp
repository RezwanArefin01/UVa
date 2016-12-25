#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define PI 2*acos(0.0)
double r,n;
double area;
int main()
{
    while(cin>>r>>n)
    {
        area = n*r*r*sin(2.0*PI/n)/2.0;
        cout<<fixed<<setprecision(3)<<(double)area<<endl;
    }
    return 0;
}
