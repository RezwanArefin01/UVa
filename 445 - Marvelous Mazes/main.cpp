#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
char input[140];
int main()
{
    while(gets(input))
    {
        int count = 0;
        for(int i=0;i<strlen(input);i++)
        {
            if(input[i]>='0' && input[i]<='9')
                count += input[i]-'0';
            else if (input[i]=='b')
            {
                for(int j=0;j<count;j++)
                    cout<<" ";
                count = 0;
            }
            else if (input[i]=='!')cout<<endl;
            else {
                for(int j=0;j<count;j++)
                {
                    cout<<input[i];
                }
                count = 0;
            }
        }
        cout<<endl;
    }
    return 0 ;
}
