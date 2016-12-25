#include<bits/stdc++.h>
using namespace std;
double u,v,t,s,a,num;
int co=0;
void uvt()
{
    cin>>u>>v>>t;
    a = (v-u)/t;
    s = t*((u+v)/2.0);
    cout<<fixed<<setprecision(3)<<s<<" "<<a<<endl;
}
void uva()
{
    cin>>u>>v>>a;
    t = (v-u)/a;
    s = t*((u+v)/2.0);
    cout<<fixed<<setprecision(3)<<s<<" "<<t<<endl;
}
void uas()
{
    cin>>u>>a>>s;
    v = sqrt(u*u + 2*a*s);
    t = (v-u)/a;
    cout<<fixed<<setprecision(3)<<v<<" "<<t<<endl;
}
void vas()
{
    cin>>v>>a>>s;
    u = sqrt(v*v - 2*a*s);
    t = (v-u)/a;
    cout<<fixed<<setprecision(3)<<u<<" "<<t<<endl;
}
int main()
{
    while(cin>>num && num)
    {
        cout<<"Case "<<++co<<": ";
        if(num==1) uvt();
        else if(num==2) uva();
        else if(num==3) uas();
        else vas();
    }
    return 0;
}
