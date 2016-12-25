#include<bits/stdc++.h>
using namespace std;

int main() {
    string str; int n; while(cin>>n && n) {
        vector<string>a(n), b(n);
        getline(cin, str);
        for(int i=0; i<n; i++) {
            getline(cin, a[i]);
            getline(cin, b[i]);
        }
        getline(cin, str); int i = 0;
        while(i != n) {
            int n = str.find(a[i]);
            if(n != -1) {
                str.erase(n, a[i].size());
                str.insert(n, b[i]);
            } else i++;
        } cout<<str<<endl;
    }
}
