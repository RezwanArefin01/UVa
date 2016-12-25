#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin>>t; string str; getline(cin,str); while(t--) {
        getline(cin, str); int len = sqrt(str.size());
        if(len * len != str.size()) puts("INVALID");
        else {
            for(int i=0; i<len; i++) {
                for(int j=i; j<len*len; j+=len) cout<<str[j];
            } cout<<endl;
        }
    }
}
