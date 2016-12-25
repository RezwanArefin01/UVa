#include<bits/stdc++.h>
using namespace std;

int main() {
    string str,tmp;
    while(getline(cin,str)) {
        istringstream iss(str);
        iss>>tmp;
        reverse(tmp.begin(),tmp.end());cout<<tmp;
        while(iss>>tmp) {
            reverse(tmp.begin(),tmp.end());
            cout<<" " <<tmp;
        }
        puts("");
    }
    return 0;
}
