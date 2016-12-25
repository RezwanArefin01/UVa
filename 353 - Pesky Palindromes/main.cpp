#include<bits/stdc++.h>
using namespace std;
map<string, int> m;

int main() {
    string str; while(cin>>str) { m.clear();
        int n = str.size(); int cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++){
                string tmp = str.substr(i, j-i+1);
                if(!m[tmp] && tmp == string(tmp.rbegin(), tmp.rend())) m[tmp] = 1,cnt++;
            }
        } cout<<"The string '"<<str<<"' contains "<<cnt<<" palindromes."<<endl;
    }
}
