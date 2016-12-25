#include<bits/stdc++.h>
using namespace std;

int deg(int n ) {
    if( n == 9) return 1;
    int sum = 0;
    while(n > 0) sum += n%10, n/=10;
    return 1+deg(sum);
}
int main() {
    string s;
    while(cin>>s) {
        int len = s.size();
        if(len == 1 && s[0] == '0') return 0;
        int sum = 0;
        for(int i=0; i<len; i++)  sum += (s[i] -'0');
        if(sum % 9 != 0)
            cout<<s<<" is not a multiple of 9."<<endl;
        else {
            cout<<s<<" is a multiple of 9 and has 9-degree "<<deg(sum)<<"."<<endl;
        }
    }
}
