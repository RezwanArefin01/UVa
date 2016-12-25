#include<bits/stdc++.h>
using namespace std;
int read() {
    int n;
    char c = 0;
    while(c<33) c = getc(stdin);
        n = 0;
    while(c>33){
        n = n*10 + c - '0';
        c = getc(stdin);
    }
    return n;
}
int phi(int n) {
    int result = n;
    for (int p=2; p*p<=n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}
int main() {
    int n;
    int a[50001];
    a[1] = 1;
    for(int i=2;i<50001;i++) {
        a[i] = a[i-1] + 2* phi(i);
    }
    while(1) {
        n = read();
        if(!n) break;
        cout<<a[n]<<endl;
    }
    return 0;
}
