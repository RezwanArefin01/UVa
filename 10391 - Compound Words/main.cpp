#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
int main() {
    vector<string> v; string s; while(cin>>s) v.push_back(s);
    string a,b;
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size()-1; j++) {
            a = v[i].substr(0,j);
            b = v[i].substr(j,v[i].size());
            if(binary_search(all(v), a) && binary_search(all(v), b)) {
                cout<<v[i]<<endl; break;
            }
        }
    }
}
