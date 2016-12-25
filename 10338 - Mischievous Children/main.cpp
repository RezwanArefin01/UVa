#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef unsigned long long int ull;
int t,count,len,i,j,co=0;
ull div,ans;
ull fact(int n)
{
    return n<2?1:(n*fact(n-1));
}
int main()
{
    cin>>t;
    getchar();
    while(t--)
    {
        div=1;
        char ch[21];
        gets(ch);
        len = strlen(ch);
        for(i=0;i<len;i++)
        {
            count = 1;
            if(ch[i]!='\0')
            {
                for(j=i+1;j<len;j++)
                {
                    if(ch[i]==ch[j])
                    {
                        ch[j]='\0';
                        count++;
                    }
                }
            }
            div*=fact(count);
        }
        ans = fact(len)/div;
        cout<<"Data set "<<++co<<": "<<ans<<endl;
    }
    return 0;
}
