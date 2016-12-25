#include <iostream>
using namespace std;
int a,b,c,t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        if(a+b<=c || b+c<=a || a+c<=b)
            cout<<"Wrong!!"<<endl;
        else cout<<"OK"<<endl;
    }
    return 0;
}
