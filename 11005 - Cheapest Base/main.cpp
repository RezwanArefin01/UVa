#include<bits/stdc++.h>
using namespace std;

string nums = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<char, int> m;
int W(int num, int base) {
    int sum = 0;
    while(num > 0) {
        sum += m[nums[num % base]];
        num /= base;
    } return sum;
}
int main() { int co = 0;
    int t; cin>>t; while(t--) {
        m.clear();
        for(int i=0; i<36; i++ ) cin>>m[nums[i]];
        cout<<"Case "<<++co<<":\n";
        int T; cin>>T; while(T--) {
            int num; cin>>num; vector<pair<int, int> > v;
            cout<<"Cheapest base(s) for number "<<num<<":";
            for(int i=2; i<=36; i++)
                v.push_back( pair<int,int> (W(num,i), i));
            sort(v.begin(), v.end());
            int Min = v[0].first;
            int i = 0;
            while(v[i].first == Min) {
                cout<<" " << v[i].second;
                i++; if(i == 35) break;
            } cout<<endl;
        } if(t) puts("");
    }
}
