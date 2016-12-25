#include<iostream>
using namespace std;
long long rev(long long int n)
{
    long long int i;
    i=0;
    while(n>0)
    {
        i=(i*10)+(n%10);
        n=n/10;
    }
    return i;
}
int main()
{
    long long int a,b,m,t;
    cin>>t;
    while(t--)
    {
        cin>>a;
        m=0;
        b=rev(a);
        while(a!=b)
        {
            a=(a+b);
            b=rev(a);
            m++;
        }
        cout<<m<<" "<<a<<endl;
    }
    return 0;
}
