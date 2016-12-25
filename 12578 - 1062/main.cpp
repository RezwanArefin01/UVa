#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1.0)
double area_red,area_green,l,r,w;
int t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>l;
        w=6.0*l/10.0;
        r=l/5.0;
        area_red = PI*r*r;
        area_green = l*w-area_red;
        cout<<fixed<<setprecision(2)<<area_red<<" "<<area_green<<endl;
    }
    return 0;
}
