#include<bits/stdc++.h>
using namespace std;
int i,t,temp,n,cnt[11];
int main()
{
    cin>>t;
    while(t--)
    {
        memset(cnt,0,sizeof(cnt));
        cin>>n;
        for(i=1;i<=n;i++)
        {
            temp = i;
            while(temp)
            {
                cnt[temp%10]++;
                temp/=10;
            }
        }
        for(i=0;i<9;i++) cout<<cnt[i]<<" ";
        cout<<cnt[9]<<endl;
    }
    return 0;
}
