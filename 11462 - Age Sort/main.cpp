#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long int n,i,ages;
int main()
{
    while(cin>>n && n)
    {
        vector <long int> age;
        for(i=1;i<=n;i++)
        {
            cin>>ages;
            age.push_back(ages);
        }
        sort(age.begin(),age.end());
        cout<<age[0];
        for(i=1;i<n;i++)
        {
            cout<<" "<<age[i];
        }
        cout<<endl;
    }
    return 0;
}
