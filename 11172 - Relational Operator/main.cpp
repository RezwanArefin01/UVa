#include <iostream>
using namespace std;
long int a,b;
int t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        if(a>b) cout<<">"<<endl;
        if(a<b) cout<<"<"<<endl;
        if(a==b)cout<<"="<<endl;
    }
    return 0;
}
