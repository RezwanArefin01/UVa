#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    double f,a,c,d;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>c>>d;
        f = 9.0*c/5.0+d;
        a = f*5.0/9.0;
        cout<<"Case "<<i<<": "<<fixed << setprecision(2)<<a<<endl;
    }
    return 0;
}
