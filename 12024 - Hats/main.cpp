#include <iostream>
using namespace std;
int fn[13],nf[13],t,i;
int main()
{
    fn[0]=1;fn[1]=0;
    nf[0]=1;nf[1]=1;
    for(i=2;i<13;i++)
    {
        fn[i] = (i-1) * (fn[i-1]+fn[i-2]);
        nf[i] = i*nf[i-1];
    }
    cin>>t;
    while(t--)
    {
        cin>>i;
        cout<<fn[i]<<"/"<<nf[i]<<endl;
    }
    return 0;
}
