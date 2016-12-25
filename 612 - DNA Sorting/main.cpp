#include<bits/stdc++.h>
using namespace std;

struct sq{
    string s; int inv;
};
int mes(string s) {
    int ret = 0;
    for(int i=0; s[i]; i++)
        for(int j=i+1; s[j]; j++)
            if(s[i] > s[j]) ret++;
    return ret;
}
bool cmp(sq a, sq b) {
    return a.inv < b.inv ? 1 : 0;
}
int main() {
    int t; cin>>t; while(t--) {
        int n,m; cin>>m>>n;
        vector<sq> v(n);
        for(int i=0; i<n;i++) {
            cin>>v[i].s;
            v[i].inv = mes(v[i].s);
        } stable_sort(v.begin(), v.end(), cmp);
        for(auto a : v) cout<<a.s<<endl;
        if(t) puts("");
    }
}
