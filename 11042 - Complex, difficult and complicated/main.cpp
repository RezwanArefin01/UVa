#include<bits/stdc++.h>
using namespace std;

int main() {
    int t,a,b; cin>>t;
    while(t--) {
        cin>>a>>b;
        if(!b) puts("1");
        else if(!a) puts("2");
        else if (abs(a) == abs(b) ) puts("4");
        else puts("TOO COMPLICATED");
    }
}
