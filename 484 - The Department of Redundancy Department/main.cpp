#include<bits/stdc++.h>
using namespace std;

vector<int> o; map<int,int> m; int n;
int main() {
    while(cin>>n) {
        if(!m[n]) o.push_back(n);
        m[n]++;
    }
    for(int i=0; i<o.size(); i++)
        cout<<o[i]<<" " <<m[o[i]]<<endl;
}
