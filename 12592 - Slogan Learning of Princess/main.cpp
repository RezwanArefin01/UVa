#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string, string> m;
    int n; cin>>n; getchar(); string s1, s2;
    while(n--) {
        getline(cin, s1); getline(cin, s2);
        m[s1] = s2;
    } cin>>n; getchar(); while(n--) {
        getline(cin, s1); cout<<m[s1]<<endl;
    }
}
