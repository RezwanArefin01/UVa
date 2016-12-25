#include<iostream>
using namespace std;
#define MAX(a,b) (a>b?a:b)
unsigned long long t,n,i,max_dist,k,dist,co=0;
int main()
{
    cin>>t;
    while(t--)
    {
        k=max_dist=dist=0;
        cin>>n;
        unsigned long long r[n];
        r[0]=0;
        for(i=1;i<=n;i++)
        {
            cin>>r[i];
            max_dist = MAX(max_dist,(r[i]-r[i-1]));
        }
        k = max_dist;
        for(i=1;i<=n;i++)
        {
            dist = r[i]-r[i-1];
            if(dist == max_dist) max_dist--;
            else if (dist > max_dist) {max_dist = -1;break;}
        }
        if(max_dist>0) cout<<"Case "<<++co<<": "<<k<<endl;
        else cout<<"Case "<<++co<<": "<<k+1<<endl;
    }
    return 0;
}
