#include <bits/stdc++.h>
using namespace std;
bool cmp (char a, char b) {
    if(tolower(a) == tolower(b)) return a<b;
    return tolower(a) < tolower(b);
}
int main() {
	freopen("out", "w", stdout);
    //int t; cin>>t; while(t--) {
        string s = "BbaA";  sort(s.begin(), s.end(), cmp);
        do {
            cout<<s<<endl;
        } while(next_permutation(s.begin(), s.end(),cmp));
    //}
}
