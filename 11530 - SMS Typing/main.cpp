#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char res[]={"abcdefghijklmnopqrstuvwxyz "};
char ans[]={"123123123123123123412312341"};
int sum,t,i,j,co=0;
int main()
{
    cin>>t;
    getchar();
    while(t--)
    {
        string s;
        getline(cin,s);
        sum=0;
        for(i=0;i<s.size();i++)
        {
            for(j=0;j<28;j++)
            {
                if(s[i]==res[j])
                {
                    sum+=(ans[j]-'0');
                }
            }
        }
        cout<<"Case #"<<++co<<": "<<sum<<endl;
    }
    return 0;
}
