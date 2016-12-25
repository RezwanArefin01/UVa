#include<bits/stdc++.h>
using namespace std;

int main() {
    int t,co=0; cin>>t ; while(t--) {
        int R; cin>>R;
        int l = R*5, r = l*3/5;
        int a = r/2, b = l*55/100, c = l-b;
        cout<<"Case "<<++co<<":\n";
        cout<<-c<<" " <<a<<endl
            << b<<" " <<a<<endl
            << b<<" " <<-a<<endl
            <<-c<<" " <<-a<<endl;
    }
}
