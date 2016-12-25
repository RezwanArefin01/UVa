#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n && n)
    {
        if(n==0)
            break;
        int c=0;
        while(n>=3)
        {
            n=n-3;
            c++;
            n=n+1;
        }
        if(n==2)
        {
            c++;
            cout<<c;
        }
        else
            cout<<c;
        cout<<endl;
    }
    return 0;
}
