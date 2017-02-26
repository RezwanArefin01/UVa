#include <bits/stdc++.h>
using namespace std;
double x,y,h,w,a,b;
#define eps (1e-6)
int main() {
   while(cin>>x>>y>>h) {
        double lo=0, hi=min(x,y), ah;
        while(1) {
            w = (hi-lo)/2 + lo;
            a = sqrt(x*x - w*w), b = sqrt(y*y - w*w);
            ah = a*b/(a+b);
            if(fabs(ah - h) <= eps) break;
            if(ah > h) lo = w;
            else hi = w;
        }cout<<setprecision(3)<<fixed<<w<<endl;
   }
}
