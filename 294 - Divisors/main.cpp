#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t;
    unsigned long long n,m,i,j;
    cin>>t;
    while(t--)
    {
        long long res[3];
        res[1]=0;
        res[2]=0;
        cin>>n>>m;
        for(i=n;i<=m;i++)
        {
            vector <unsigned long long> ans;
            for(j=1;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    if(j*j==i) ans.push_back(j);
                    else {
                    ans.push_back(j);
                    ans.push_back(i/j);}
                }
            }
            if(res[2]<ans.size())
            {
                res[1] = i;
                res[2] = ans.size();
            }
        }
        cout<<"Between "<<n<<" and "<<m<<", "<< res[1]<<" has a maximum of "<<res[2]<<" divisors."<<endl;
    }
    return 0;
}
