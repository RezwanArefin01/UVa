#include<bits/stdc++.h>
using namespace std;
int co = 0; unsigned long long a,b;
int main() {
    while(cin>>a>>b && (a||b)) {
        cout<<"Case "<<++co<<": "<< (a*b*(a-1)*(b-1))/4<<endl;
    }
}
