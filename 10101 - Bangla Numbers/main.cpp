#include<bits/stdc++.h>
using namespace std;
void bangla(long long f) {
    if(f >= 10000000) {
        bangla(f / 10000000);
        printf(" kuti");
        f %= 10000000;
    }
    if(f >= 100000) {
        bangla(f / 100000);
        printf(" lakh");
        f %= 100000;
    }
    if(f >= 1000) {
        bangla(f / 1000);
        printf(" hajar");
        f %= 1000;
    }
    if(f >= 100) {
        bangla(f / 100);
        printf(" shata");
        f %= 100;
    }
    if(f) printf(" %d",f);
}
int main() {
    long long num;
    int co = 0;
    while(cin>>num) {
        printf("%4d.",++co);
        if(num==0) printf(" 0");
        else bangla(num);
        puts("");
    }
}
