#include<bits/stdc++.h>
using namespace std;

int main( ){
    int a,b,o,t; while(cin>>a>>b && a!=-1 && b!= -1) {
        if(a > b) o = a - b, t = b + 100 - a;
        else o = b - a, t = a + 100 - b;
        cout<<min(o,t)<<endl;
    }
}
