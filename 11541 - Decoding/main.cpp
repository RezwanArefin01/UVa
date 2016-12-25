#include<bits/stdc++.h>
using namespace std;

int main() {
    int co =0 ,t; cin>>t; while(t--) {
        string str; cin>>str;
        cout<<"Case "<<++co<<": ";
        for(int i=0; str[i]; ) {
            char curr = str[i++];
            int n = str[i++] - '0';
            while(isdigit(str[i])) n = n*10 + str[i++] - '0';
            for(int j =0; j<n ;j++) cout<<curr;
        } cout<<endl;
    }
}
