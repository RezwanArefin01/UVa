#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b; while(cin>>a>>b) {
        cout<<"["<<a/b<<";"; a %= b;
        while(a != 1) {
            cout<<b/a<<',';
            b %= a;
            swap(a,b);
        } cout<<b<<"]\n";
    }
}
