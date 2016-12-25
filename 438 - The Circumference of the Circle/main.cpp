#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
#define PI 3.141592653589793
struct point {double x,y;};
point A,B,C;
double ROutercircle,area,s,AB,BC,AC,Circumference;
double dist(point A,point B)
{
    return sqrt(pow((B.x-A.x),2)+pow((A.y-B.y),2));
}
int main()
{
    while(cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y)
    {
        AB=dist(A,B);
        AC=dist(A,C);
        BC=dist(B,C);
        s=(AB+BC+AC)/2.0;
        area = sqrt(s*(s-AB)*(s-BC)*(s-AC));
        ROutercircle = (AB*BC*AC)/(4.0*area);
        Circumference = 2*PI*ROutercircle;
        cout<<fixed<<setprecision(2)<<Circumference<<endl;
    }
    return 0;
}
