#include<iostream>
#include<iomanip>
using namespace std;
int t,i,n;
int main()
{
    cin>>t;
    while(t--)
    {
        int num[1001],total=0,count=0;
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>num[i];
            total+=num[i];
        }
        float avg=total/n;
        for(i=0;i<n;i++)
        {
            if(num[i]>avg) count++;
        }
        float ans = (count*100.000/n);
        cout<<std::fixed<<std::setprecision(3)<<ans<<"%"<<endl;
    }
    return 0;
}
