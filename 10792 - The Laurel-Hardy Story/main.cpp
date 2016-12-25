#include<bits/stdc++.h>
using namespace std;
#define pi (2.0*acos(0.0))

int main() {
    int t,co=0; double r,d,h1;
    cin>>t;
    while(t--) {
        cin>>r>>d>>h1;
        double ab = 2.0 * sqrt(r*r - pow((r-d),2.0));
        double alpha = asin((r-h1)/r);
        double beta  = asin((r-d)/r);
        double theta = alpha - beta;
        double h2 = h1 + ab * sin(theta);
        cout<<"Case "<<++co<<": "<<fixed<<setprecision(4)<<h2<<endl;
    }
}
