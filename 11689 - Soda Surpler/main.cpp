#include<iostream>
using namespace std;
int total,t,temp,n,h,f,soda;
int main ()
{
    cin>>t;
    while(t--)
    {
        cin>>h>>f>>n;
        total = h+f;
        soda = 0;
        while(total>=n)
        {
            temp = (total/n);
            soda +=temp;
            total = total - (temp*n);
            total +=temp;
        }
        cout<<soda<<endl;
    }
    return 0;
}
