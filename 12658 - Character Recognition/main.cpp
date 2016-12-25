#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; while(cin>>n){
    string s; cin>>s>>s>>s>>s;
    for(int i=0,j=0; j < n; j++, i += 4) {
        if(s[i] == '*') putchar('2');
        else if(s[i+1] == '*') putchar('1');
        else putchar('3');
    } puts("");cin>>s;}
}
