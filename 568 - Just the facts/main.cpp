#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main()
{
    LL a;
    while(cin>>a)
    {
        LL ans=1;
        for(LL i=a;i>=1;i--)
        {
            ans*=i;
            while(ans%10==0)
                ans/=10;
            ans%=1000000000;
        }
        cout<<setw(5)<<setiosflags(ios::right)<<a<<" -> "<<ans%10<<endl;
    }
    return 0;
}
