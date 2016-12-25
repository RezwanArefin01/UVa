#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int a,b,c;
int main()
{
    while(cin>>a && a)
    {
        vector<int> tr;
        cin>>b>>c;
        tr.push_back(a);
        tr.push_back(b);
        tr.push_back(c);
        sort(tr.begin(),tr.end());
        if(tr[0]*tr[0] + tr[1]*tr[1] == tr[2]*tr[2])
            cout<<"right"<<endl;
        else cout<<"wrong"<<endl;
    }
    return 0;
}
