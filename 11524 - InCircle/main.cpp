#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    int t;
    double r,m1,m2,n1,n2,m3,n3;
    double a,b,c;
    double area;
    cin>>t;
    while(t--)
    {
        cin>>r>>m1>>n1>>m2>>n2>>m3>>n3;
        a=m1+n1;
        b=m2+n2;
        c=m3+n3;
        double s=(a+b+c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        cout<<fixed<<setprecision(4)<<(double)area<<endl;
    }
    return 0;
}
