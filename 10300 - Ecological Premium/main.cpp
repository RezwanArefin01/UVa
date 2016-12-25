#include <iostream>
using namespace std;

int main()
{
    long long t,a,b,c;
    cin>>t;
    while(t--)
    {
        long long sum=0 ;
        int n;
        cin>>n;
        while (n--)
        {
            cin>>a>>b>>c;
            sum+=(long)a*c;
        }
        cout<<sum<<endl;
    }
    return 0;
}
