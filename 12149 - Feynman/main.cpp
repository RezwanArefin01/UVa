#include<iostream>
using namespace std;
long long int n;
int main()
{
    while(cin>>n && n)
    {
        cout<<n*(n+1)*(2*n+1)/6<<endl;
    }
    return 0;
}
