#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
short t,n,co=0,age;
int main()
{
    cin>>t;
    while(t--)
    {
        vector<short> ages;
        cin>>n;
        while(n--)
        {
            cin>>age;
            ages.push_back(age);
        }
        cout<<"Case "<<++co<<": ";
        sort(ages.begin(),ages.end());
        cout<<ages[(ages.size()+1)/2-1]<<endl;
    }
    return 0;
}
