#include<iostream>
using namespace std;
#define MOD 131071
char ch;
int number;
int main()
{
    while(cin>>ch)
    {
        number = ch - '0';
        while(cin>>ch)
        {
            if(ch=='#') break;
            number = (number<<1) + (ch-'0');
            number %=  MOD;
        }
        if (number) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
