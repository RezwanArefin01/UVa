#include<iostream>
using namespace std;

int main()
{
    unsigned int t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(b%a==0) cout<<a<<" "<<b<<endl;
        else cout<<"-1"<<endl;
    }
    return 0;
}
