#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;
int main() {
    ll num;
    while(cin>>num && num) {
        ll a = num + num/9, b = 0;
        for(ll i = a-10; i<= a+10; i++){
            if(i - i/10 == num) {b = i; break;}
        }
        if (b == a) b = 0;
        if(!b) cout<<a<<endl;
        else {
            cout<<min(a,b)<<" "<<max(a,b)<<endl;
        }
    }
}
