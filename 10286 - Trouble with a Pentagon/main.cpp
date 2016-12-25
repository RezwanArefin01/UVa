#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define PI 2*acos(0.0)
double vertex_of_p,side,rule=sin(108*PI/180)/sin(63*PI/180);
int main()
{
    while(cin>>vertex_of_p)
    {
        side = vertex_of_p*rule;
        cout<<fixed<<setprecision(10)<<side<<endl;
    }
    return 0;
}
