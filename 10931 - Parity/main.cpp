#include<bits/stdc++.h>
using namespace std;
long int n,a,i,parity;
int main()
{
    while(cin>>n && n)
    {
        vector<short> bin;
        parity = 0;
        while(n>0)
        {
            a=n%2;
            if(a==1) parity++;
            bin.push_back(a);
            n/=2;
        }
        cout<<"The parity of ";
        for(i=bin.size()-1;i>=0;i--) cout<<bin[i];
        cout<<" is "<<parity<<" (mod 2)."<<endl;
    }
    return 0;
}
