#include<iostream>
using namespace std;
typedef unsigned long long ull;
ull n,ans;
int main()
{
    while(cin>>n)
    {
        ans = ((n+1)*(n+1)/4)*6-9;
        cout<<ans<<endl;
    }
    return 0;
}
