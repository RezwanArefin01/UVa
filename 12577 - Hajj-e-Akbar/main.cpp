#include<iostream>
#include<cstring>
using namespace std;
string s;
int co=0,i;
const char* ans[2]={"Hajj-e-Akbar","Hajj-e-Asghar"};
const char* res[2]={"Hajj","Umrah"};
int main()
{
    while(cin>>s && s!="*")
    {
        cout<<"Case "<<++co<<": ";
        if(s==res[1]) cout<<ans[1<<endl;
        if(s==res[0]) cout<<ans[0]<<endl;
    }
    return 0;
}
