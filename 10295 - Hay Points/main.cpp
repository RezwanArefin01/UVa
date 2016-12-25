#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str; ll p; map<string, ll> m;
int main() {
    int M,n; cin>>M>>n;
    while(M--) {
        cin>>str>>p; m[str] = p;
    } getline(cin, str);
    while(n--) {
        ll ans = 0;
        while(getline(cin,str)) {
            istringstream ss(str); string s;
            ss>>s; if(s == ".") break;
            ans += m[s];
            while(ss>>s) ans+=m[s];
        }
        cout<<ans<<endl;
    }
}
