#include<iostream>
using namespace std;
unsigned long long H(long long n)
{
    long long res = 0;
    for( int i = 1; i <= n; i=i+1 )
    {
        res = (res + n/i);
    }
    return res;
}
unsigned long long n;
int t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<H(n)<<endl;
    }
    return 0;
}
