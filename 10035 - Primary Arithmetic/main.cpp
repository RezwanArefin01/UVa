#include <iostream>
using namespace std;
long int a,b;
int getcarry(long a,long b)
{
    int ret=0,carry=0,last_a,last_b;
    while(a!=0 || b!=0)
    {
        last_a = (int)a%10;a/=10;
        last_b = (int)b%10;b/=10;
        if((last_a+last_b+carry)>9)
        {
            ret++;
            carry=1;
        }
        else carry = 0;
    }
    return ret;
}
int main()
{
    short carry;
    while(cin>>a>>b)
    {
        if(a==b && b==0) break;
        else
        {
            carry = getcarry(a,b);
            if(carry == 0) cout<<"No carry operation.";
            else if(carry == 1) cout<<"1 carry operation.";
            else cout<<carry<<" carry operations.";
        }
        cout<<endl;
    }
    return 0;
}
