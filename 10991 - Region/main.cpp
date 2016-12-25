#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{

    double r1,r2,r3,a,b,c,A,B,C,s,area;
    int t;
    cin>>t;
    while(t--){
        cin>>r1>>r2>>r3;
        a=r1+r2;
        b=r2+r3;
        c=r3+r1;
        s =(a+b+c)/2;
        C = acos((a*a+b*b-c*c)/(2*a*b));
        A = acos((b*b+c*c-a*a)/(2*b*c));
        B = acos((c*c+a*a-b*b)/(2*c*a));
        area =sqrt(s*(s-a)*(s-b)*(s-c))-(r1*r1*B+r2*r2*C+r3*r3*A)/2;
        cout<<fixed<<setprecision(6)<<area<<endl;
    }
    return 0;
}
