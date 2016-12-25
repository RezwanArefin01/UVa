#include<bits/stdc++.h>
using namespace std;

string base(const string &s){
    string ret = s;
    ret.erase(remove(ret.begin(), ret.end(), ' '), ret.end());
    sort(ret.begin(), ret.end());
    return ret;
}
int main() {
    int t; cin>>t; cin.ignore(), cin.ignore();
    while(t--) {
        vector<string> v; string str;
        while(getline( cin, str) && str != "") v.push_back(str);
        sort(v.begin(), v.end());
        for(int i=0; i<v.size(); i++)
            for(int j= i +1; j<v.size(); j++)
                if(base(v[i]) == base(v[j]))
                 cout<<v[i]<<" = "<<v[j]<<endl;
        if(t) puts("");

    }

}
