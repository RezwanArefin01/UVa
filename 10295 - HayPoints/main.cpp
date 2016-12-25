#include<bits/stdc++.h>
using namespace std;

int main() {
    map<string,int> m;
    string s;
    int t,ma,n;
    unsigned long long total=0;
    cin>>ma>>n;
    while(ma--) {
        cin>>s>>t;
        m[s] = t;
    }
    while(n--) {
        while(cin>>s) {
            if(s==".") {
                cout<<total<<endl;
                total = 0;
                break;
            }
            total+=m[s];
        }
    }
}
