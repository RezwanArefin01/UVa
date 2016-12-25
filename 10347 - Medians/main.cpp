#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double m1,m2,m3,s,area;
int main()
{
    while(cin>>m1>>m2>>m3)
    {
        s=(m1+m2+m3)/2.00;
        area = (4.00/3.00)*sqrt(s*(s-m1)*(s-m2)*(s-m3));
        if(!(area>0)) area = -1;
        cout<<fixed<<setprecision(3)<<area<<endl;
    }
    return 0;
}
