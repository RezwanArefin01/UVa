#include <iostream>
using namespace std;
unsigned int gcd(unsigned int a,unsigned int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    unsigned int i,a,L,t;
    cin>>t;
    while(t--)
    {
        cin>>a>>L;
        if(L%a) cout<<"NO SOLUTION"<<endl;
        else
        {
            for(i=L/a;i<=L;i+=L/a)
            {
                if(a/gcd(a,i)*i==L) { cout<<i<<endl;break;}
            }
            if(i>L) cout<<"NO SOLUTION"<<endl;
        }
    }
    return 0;
}
