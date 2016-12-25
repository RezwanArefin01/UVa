#include<iostream>
#include<cstring>
using namespace std;
string n;
long int BinToSc(string n)
{
    long int result = 0, pow =2;
    for(int i=n.length()-1;i>=0;--i)
    {
        result += (n[i] - '0') * (pow-1);
        pow<<=1;
    }
    return result;
}
int main()
{
    while(cin>>n && n!="0")
    {
        cout<<BinToSc(n)<<endl;
    }
    return 0;
}
