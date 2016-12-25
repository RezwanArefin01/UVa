#include<bits/stdc++.h>
using namespace std;

int n,t,sum,co = 0;
int main() {
    while(cin>>n && n) {
        sum = 0;
        while(n--) {
            cin>>t;
            sum += ((t>0)?1:-1);
        }
        cout<<"Case "<<++co<<": "<<sum<<endl;
    }
}
