#include<bits/stdc++.h>
using namespace std;

#define in(arr) { for(auto &i : arr) cin>>i; }

bool check (string &a, string &b) {
    if(b.size() < a.size()) return false;
    for(int i=0; i<a.size(); i++) {
        if(a[i] != b[i]) return false;
    } return true;
}
int main() {
    int t,n; cin>>t; while(t--) {
        cin>>n; string num[n]; in(num);
        sort(num, num+n); bool flag = true;
        for(int i = 0; i < n-1; i++) {
            if(check(num[i], num[i+1])) {flag = false; break;}
        }
        puts(flag ? "YES" : "NO");
    }
}
