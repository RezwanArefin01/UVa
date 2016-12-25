#include <iostream>
using namespace std;
long int ans,b,p,m;
int main()
{
    while(cin>>b>>p>>m)
    {
        b%=m;
        ans=1;
        while(p)
        {
            if(p&1) ans = (ans*b)%m;
            b=(b*b)%m;
            p>>=1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
