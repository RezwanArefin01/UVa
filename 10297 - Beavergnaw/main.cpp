#include<bits/stdc++.h>
using namespace std;

int main() {
    double d,v;
    while(cin>>d>>v && (d||v)) {
        cout<<fixed<<setprecision(3)<<cbrt(d*d*d - (6.0*v)/(2.0*acos(0.0)))<<endl;
    }
}
