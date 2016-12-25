#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b,i,c,cycle,temp,flag;
int main()
{
    while(cin>>a>>b)
    {
        c=0;
        if(a>b) {swap(a,b);flag=1;};
        for(i=a;i<=b;i++)
        {
            temp = i;
            cycle= 1;
            while(!(temp==1))
            {
                if(temp%2==0) temp=temp/2;
                else if (temp%2==1) temp=(3*temp)+1;
                cycle++;
            }
            c=max(c,cycle);
        }
        if(flag==1) swap(a,b);
        cout<<a<<" "<<b<<" "<<c<<endl;
    }
    return 0;
}
