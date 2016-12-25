#include<iostream>
using namespace std;
typedef unsigned long long ull;
int temp;
int f(ull n)
{
    int sum=0;
    while(n != 0)
    {
        temp = n%10;
        sum+=temp;
        n/=10;
    }
    return sum;
}
int g(ull n)
{
    while(!(n<=9))
    {
        n=f(n);
    }
    return n;
}
int main()
{
    ull n;
    while(cin>>n && n)
    {
        cout<<g(n)<<endl;
    }
    return 0;
}
