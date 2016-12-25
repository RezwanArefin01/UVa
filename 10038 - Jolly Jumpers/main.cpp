#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,num;
int main()
{
    while(cin>>n)
    {
        vector <int> main;
        vector <int> s;
        int flag = 0;
        for(i=1;i<=n;i++)
        {
            cin>>num;
            main.push_back(num);
        }
        for(i=1;i<main.size();i++)
        {
            s.push_back(fabs(main[i]-main[i-1]));
        }
        sort(s.begin(),s.end());
        for(i=1;i<n;i++)
        {
            if(s[i-1]!=i) {flag=1; break;}
        }
        if(flag) cout<<"Not jolly"<<endl;
        else cout<<"Jolly"<<endl;
    }
    return 0;
}
