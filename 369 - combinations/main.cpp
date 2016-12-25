#include<iostream>
using namespace std;
typedef long long ll;
ll nCr(ll n,ll m)
{
    ll res=1,i;
    if(n-m<m)
    m=n-m;
    for(i=1;i<=m;i++,n--){
        res=res*n;
        res=res/i;
    }
return res;
}
int n,m;
int main()
{
    while(cin>>n&&n)
    {
        cin>>m;
        cout<< n<<" things taken "<<m<<" at a time is "<<nCr(n,m)<<" exactly."<<endl;
    }
    return 0;
}
