#include<iostream>
#include<cmath>
using namespace std;
unsigned long int n;
unsigned long long sum;
int last_digit,co=0,t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<"Case #"<<++co<<": "<<n;
        sum=0;
        a:while(!(n==0))
        {
            last_digit = n%10;
            sum += (last_digit * last_digit);
            n/=10;
        }
        if(sum>9)
        {
            n=sum;
            sum=0;
            goto a;
        }
        if(sum==1)cout<<" is a Happy number."<<endl;
        else cout<<" is an Unhappy number."<<endl;
    }
    return 0;
}
