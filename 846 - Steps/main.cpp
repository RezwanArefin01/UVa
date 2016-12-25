#include<bits/stdc++.h>
using namespace std;

int main() {
    int b, a, t; cin>>t; while(t--) {
        cin>>a>>b;
        double diff = b-a;
        if(diff == 0) { puts("0"); continue;}
        cout<<ceil(sqrt(4*diff)-1)<<endl;
    }
}
