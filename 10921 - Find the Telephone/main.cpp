#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char res[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ-10"};
char ans[]={"22233344455566677778889999-10"};
int i,j;
int main()
{
    string c;
    while(getline(cin,c,'\n'))
    {
        for(i=0;i<c.size();i++)
        {
            for(j=0;j<29;j++)
            {
                if(c[i]==res[j])
                {
                    cout<<ans[j];
                    break;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
