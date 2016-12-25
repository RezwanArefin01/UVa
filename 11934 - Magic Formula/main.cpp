#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d,x;
ll f(ll a,ll b,ll c,ll x)
{
    return a*x*x +b*x +c;
}
int main()
{
    ll i;
    while(cin>>a>>b>>c>>d>>x &&d)
    {
        ll count = 0;
        for(i=0;i<=x;i++)
        {
            if(fmod(f(a,b,c,i),d)==0) count++;
        }
        cout<<count<<endl;
    }
    return 0;
}
