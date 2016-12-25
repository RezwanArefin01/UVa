#include<bits/stdc++.h>
using namespace std;
int prime[] = {1,3,5,7,9,11,13,15,17,19,21,23,27,29,111,1009,55,51,33,31,37,49};
int main() {
    freopen("in.txt","w",stdout);
    int t  = 1500;
    while(t--) {
        int a = prime[rand()%22];
        int b = prime[rand()%22];
        if(a==b) b = prime[rand()%22];
        int d = rand()% max(a,b);
        cout<<a<<" " <<b<<" " <<d<<endl;
    }
}
