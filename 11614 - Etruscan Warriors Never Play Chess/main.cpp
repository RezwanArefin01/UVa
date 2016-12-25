#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    double s;
    long long n;
    cin>>t;
    while(t--) {
        cin>>s;
        n = (-1+sqrt(1+8*s))/2;
        cout<<n<<endl;
    }
    return 0;
}
