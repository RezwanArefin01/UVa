#include<bits/stdc++.h>
using namespace std;

double Tan(double d) {
    return tan(2*d*acos(0.0)/180);
}
int main(){
    double l,w,h,theta;
    while(cin>>l>>w>>h>>theta) {
        double lombo = l * Tan(theta);
        double ans = l*w*h - 0.5*lombo*l*w;
        if(lombo > h) ans += (0.5*(lombo-h)*(lombo-h)*Tan(90-theta) * w);
        cout<<fixed<<setprecision(3)<<ans<<" mL\n";
    }
}
