#include<iostream>
using namespace std;
long long int n;
int main()
{
    while(cin>>n && n>0)
    {
        if(n==1) cout<<"0%"<<endl;
        else cout<<n*25<<"%"<<endl;
    }
    return 0;
}
