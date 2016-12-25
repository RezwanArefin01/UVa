#include<bits/stdc++.h>
using namespace std;

struct pilot{
    int min, sec, ms;
    string name1, name2;
};
inline bool cmp(pilot a, pilot b) {
    if (a.min != b.min) return a.min < b.min;
	else if (a.sec != b.sec) return a.sec < b.sec;
	else if (a.ms != b.ms) return a.ms < b.ms;
	else return a.name2 < b.name2;
}
int main() { string tmp;
    int n; while(cin>>n) {
        vector<pilot> v(n);
        for(int i=0; i<n; i++) {
            cin>>v[i].name1>>tmp>>v[i].min>>tmp>>v[i].sec>>tmp>>v[i].ms>>tmp;
            tmp = v[i].name1; for(auto &j : tmp) j = tolower(j);
            v[i].name2 = tmp;
        } sort(v.begin(), v.end(), cmp);
        int row = 0;
        for(int i=0; i<n; i++) {
            if(i%2 == 0) cout<<"Row "<<++row<<endl;
            cout<<v[i].name1<<endl;
        } puts("");
    }
}
