#include<iostream>
#include<cmath>
using namespace std;
long int a,b,i,j;
int main()
{
    int count;
    while(cin>>a>>b)
    {
        count = 0;
        if(a==b && b==0) break;
        else
        {
            for(int i=a;i<=b;i++)
            {
                if(sqrt(i)==floor(sqrt(i))) count ++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
