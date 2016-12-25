#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    string s;
    int c=0,i;
    while(getline(cin,s,'\n'))
    {
            for(i=0;i<s.size();i++)
            {
                if(s[i]=='"')
                {
                    if (c&1) cout<<"''";
                    else cout<<"``";
                    c++;
                }else cout<<s[i];
            }
            cout<<endl;
    }
    return 0;
}
